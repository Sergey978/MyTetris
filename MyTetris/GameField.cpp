#include "GameField.h"
#include<array>



GameField::GameField()
{
	spawnNewFigure();
	//������������� �������� 0
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

/*������ ����� ������ � ��������� ����
* X - ���������� ��� ��������� �� ������ ���� ����� � ������� ����,
*��� ������������ ������ ������(MAX_FIGURE_WIDTH), ����� ������ � �����
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

	/* ����� ������������ ������ ����� (-1, ���� �� ����������) */
	int fallTo = -1;

	/* ��������� ����� ����� �����*/
	for (int y = 0; y < Constants::COUNT_CELLS_Y; y++) {
		if (fallTo == -1) { //���� ������ ��� �� ����������
			if (countFilledCellsInLine[y] == 0) fallTo = y; //...�������� ���������� (._.)
		}
		else { //� ���� ����������
			if (countFilledCellsInLine[y] != 0) { // � ������� ����� ���� ����� ��������...

												  /* ��������... */
				for (int x = 0; x < Constants::COUNT_CELLS_X; x++) {
					field[x][fallTo] = field[x][y];
					field[x][y] = 0;
				}

				/* �� �������� �������� ����-����������*/
				countFilledCellsInLine[fallTo] = countFilledCellsInLine[y];
				countFilledCellsInLine[y] = 0;

				/*
				* � ����� ������ ����� ������ �� ���������� ������� ������.
				* ���� ������ ��� �� ���� ������, �� ������ �� � �������� ����.
				* ���� ������ ��� ���� ������, �� � ������ ������ -- �� � ��� �� ���������.
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

	/* �� �������� �������� ����-����������! */
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

			/* ����, ��������� � ���, ��� ����� ����� ���������� �������� ����� ����
			* (�.�. �����-�� ����� ���� ����������)
			*/
			bool haveToShiftLinesDown = false;

			for (Coord coord : figureCoords) {
				field[coord.x][coord.y] = 1;

				/* ����������� ���������� � ���������� ��������� ������ � �����*/
				countFilledCellsInLine[coord.y]++;

				/* ���������, ��������� �� ��������� ������ Y
				* ���� ��������� ���������, �������������  haveToShiftLinesDown � true
				*/
				haveToShiftLinesDown = tryDestroyLine(coord.y) || haveToShiftLinesDown;
			}
			field, 10;
			/* ���� ��� ����������, ������� ����� �� �������������� ������ ����� */
			if (haveToShiftLinesDown) 
				shiftLinesDown();

			/* ������ ����� ������ ������ ���, ������� �� ���������*/
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
