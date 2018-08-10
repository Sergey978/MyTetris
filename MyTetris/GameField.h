#pragma once
#include "Figure.h"
#include "Constants.h"
#include "coord.h"

/**
* Хранит информацию о поле и о падающей фигуре.
* Содержит методы для их обновления, и получения о них информации.
*/

class GameField
{
public:
	GameField();

	/**
	* @param x X-координата проверяемой ячейки
	* @param y Y-координата проверяемой ячейки
	* @return Является ли ячейка с координатами (X, Y) пустой
	*/
	bool isEmpty(int x, int y); 

	/**
	* @return Информация о летящей в данный момент фигуре
	*/
	Figure *getFigure(); 


	/**
	* @return Информация о следующей  фигуре
	*/
	Figure *getSecondFigure();


	/**
	* Если это возможно, смещает летящуюю фигуру в направлении shiftDirection
	*
	* @param shiftDirection направление, в котором необходимо сместить фигуру
	*/
	 void tryShiftFigure(ShiftDirection shiftDirection);


	 /**
	 * Если это возможно, пробуем повернуть фигуру по часовой стрелке
	 */
	 void tryRotateFigure();

	 /**
	 * Если фигуру можно сместить вниз, смещаем.
	 * Если это невозможно, переносим фигуру в список статичных блоков и создаём новую.
	 */
	 void letFallDown();

	 /**
	 * @return Есть ли в невидимой зоне над полем статичные блоки
	 */
	 bool isOverfilled(); 


	~GameField();

private :
	
	int field[Constants::COUNT_CELLS_X][Constants::COUNT_CELLS_Y + Constants::OFFSET_TOP]; // 0 -пусто , 1 заполнено
	//количество непустых ячеек в строке
	int countFilledCellsInLine[Constants::COUNT_CELLS_Y + Constants::OFFSET_TOP];

	Figure *figure = nullptr;
	Figure *secondFigure = nullptr;

	/**
	* Создаёт новую фигуру в невидимой зоне
	* X-координата для генерации не должна быть ближе к правому краю,
	* чем максимальная ширина фигуры (MAX_FIGURE_WIDTH), чтобы влезть в экран
	*/
	void spawnNewFigure();

	/**
	* Если на поле есть полностю пустые линии, сдвигает вышестоящие непустые линии на их место.
	*/
	void shiftLinesDown();



	/**
	* Если линия полностю заполнена, уничтожает её (но не сдвигает остальные!)
	*
	* @param y Номер проверяемой линии
	* @return Была ли линия уничтожена
	*/
	 bool tryDestroyLine(int y);

	 
};



