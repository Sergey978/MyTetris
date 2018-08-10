#include "GameField.h"
#include<array>



GameField::GameField()
{
	spawnNewFigure();
	//инициализация массивов 0
	for (int y = 0; y < Constants::COUNT_CELLS_Y + Constants::OFFSET_TOP; y++)
	{
		for (int x = 0; x < Constants::COUNT_CELLS_X; x++)
		{
			field[x][y] = 0;
		}
	}

	for (int y = 0; y < Constants::COUNT_CELLS_Y + Constants::OFFSET_TOP; y++)
	{
		countFilledCellsInLine[y] =  0;
	}


}

bool GameField::isEmpty(int x, int y)
{
			return (field[x][y] == 0);
	
}

Figure* GameField::getFigure()
{
	return figure;
}

Figure * GameField::getSecondFigure()
{
	return secondFigure;
}

/*Создаёт новую фигуру в невидимой зоне
* X - координата для генерации не должна быть ближе к правому краю,
*чем максимальная ширина фигуры(MAX_FIGURE_WIDTH), чтобы влезть в экран
*/

void GameField::spawnNewFigure(){
	
	int x = Constants::COUNT_CELLS_X / 2 - Constants::MAX_FIGURE_WIDTH / 2;
	if (figure == nullptr)
	{
			figure = new Figure( Coord(x, Constants::COUNT_CELLS_Y + Constants::OFFSET_TOP - 1));
			secondFigure = new Figure(Coord(x, Constants::COUNT_CELLS_Y + Constants::OFFSET_TOP - 1));
	}
	else
	{
		figure = secondFigure;
		secondFigure = new Figure(Coord(x, Constants::COUNT_CELLS_Y + Constants::OFFSET_TOP - 1));
	}
	

}

void GameField::shiftLinesDown()
{

	/* Номер обнаруженной пустой линии (-1, если не обнаружена) */
	int fallTo = -1;

	/* Проверяем линии снизу вверх*/
	for (int y = 0; y < Constants::COUNT_CELLS_Y; y++) {
		if (fallTo == -1) { //Если пустот ещё не обнаружено
			if (countFilledCellsInLine[y] == 0) fallTo = y; //...пытаемся обнаружить (._.)
		}
		else { //А если обнаружено
			if (countFilledCellsInLine[y] != 0) { // И текущую линию есть смысл сдвигать...

												  /* Сдвигаем... */
				for (int x = 0; x < Constants::COUNT_CELLS_X; x++) {
					field[x][fallTo] = field[x][y];
					field[x][y] = 0;
				}

				/* Не забываем обновить мета-информацию*/
				countFilledCellsInLine[fallTo] = countFilledCellsInLine[y];
				countFilledCellsInLine[y] = 0;

				/*
				* В любом случае линия сверху от предыдущей пустоты пустая.
				* Если раньше она не была пустой, то сейчас мы её сместили вниз.
				* Если раньше она была пустой, то и сейчас пустая -- мы её ещё не заполняли.
				*/
				fallTo++;
			}
		}
	}
}

bool GameField::tryDestroyLine(int y)
{
	if (countFilledCellsInLine[y] < Constants::COUNT_CELLS_X) {
		return false;
	}

	for (int x = 0; x < Constants::COUNT_CELLS_X; x++) {
		field[x][y] = 0;
	}

	/* Не забываем обновить мета-информацию! */
	countFilledCellsInLine[y] = 0;

	return true;
}

void GameField::tryShiftFigure(ShiftDirection shiftDirection)
{

	std::array<Coord, Constants::MAX_FIGURE_WIDTH> shiftedCoords = figure->getShiftedCoords(shiftDirection);

	bool canShift = true;

	for (Coord coord : shiftedCoords) {
		if ((coord.y<0 || coord.y >= Constants::COUNT_CELLS_Y + Constants::OFFSET_TOP)
			|| (coord.x<0 || coord.x >= Constants::COUNT_CELLS_X)
			|| !isEmpty(coord.x, coord.y)) {
			canShift = false;
		}
	}

	if (canShift) {
		figure->shift(shiftDirection);
	}
}

void GameField::tryRotateFigure()
{
	std::array<Coord, Constants::MAX_FIGURE_WIDTH> rotatedCoords = figure->getRotatedCoords();

	bool canRotate = true;

	for (Coord coord : rotatedCoords) {
		if ((coord.y<0 || coord.y >= Constants::COUNT_CELLS_Y + Constants::OFFSET_TOP)
			|| (coord.x<0 || coord.x >= Constants::COUNT_CELLS_X)
			|| !isEmpty(coord.x, coord.y)) {
			canRotate = false;
		}
	}

	if (canRotate) {
		figure->rotate();
	}
}

void GameField::letFallDown()
{
	std::array<Coord, Constants::MAX_FIGURE_WIDTH> fallenCoords = figure->getFallenCoords();

	bool canFall = true;
	bool t;
	for (Coord coord : fallenCoords) {
		if ((coord.y < 0 || coord.y >= Constants::COUNT_CELLS_Y + Constants::OFFSET_TOP)
			|| (coord.x < 0 || coord.x >= Constants::COUNT_CELLS_X)
			|| !isEmpty(coord.x, coord.y)) {
			canFall = false;
		}
		t = isEmpty(coord.x, coord.y);
	}
	 
		if (canFall) {
			figure->fall();
		}
		else {
			std::array<Coord, Constants::MAX_FIGURE_WIDTH> figureCoords = figure->getCoords();

			/* Флаг, говорящий о том, что после будет необходимо сместить линии вниз
			* (т.е. какая-то линия была уничтожена)
			*/
			bool haveToShiftLinesDown = false;

			for (Coord coord : figureCoords) {
				field[coord.x][coord.y] = 1;

				/* Увеличиваем информацию о количестве статичных блоков в линии*/
				countFilledCellsInLine[coord.y]++;

				/* Проверяем, полностью ли заполнена строка Y
				* Если заполнена полностью, устанавливаем  haveToShiftLinesDown в true
				*/
				haveToShiftLinesDown = tryDestroyLine(coord.y) || haveToShiftLinesDown;
			}
			field, 10;
			/* Если это необходимо, смещаем линии на образовавшееся пустое место */
			if (haveToShiftLinesDown) 
				shiftLinesDown();

			/* Создаём новую фигуру взамен той, которую мы перенесли*/
			delete figure;
			spawnNewFigure();
		}
	
}

bool GameField::isOverfilled()
{
	
		bool ret = false;

		for (int i = 0; i < Constants::OFFSET_TOP; i++) {
			if (countFilledCellsInLine[Constants::COUNT_CELLS_Y + i] != 0) ret = true;
		}

		return ret;
	
}

GameField::~GameField()
{
}
