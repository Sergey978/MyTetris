#pragma once
#include "Figure.h"
#include "Constants.h"
#include "coord.h"

/**
* ������ ���������� � ���� � � �������� ������.
* �������� ������ ��� �� ����������, � ��������� � ��� ����������.
*/

class GameField
{
public:
	GameField();

	/**
	* @param x X-���������� ����������� ������
	* @param y Y-���������� ����������� ������
	* @return �������� �� ������ � ������������ (X, Y) ������
	*/
	bool isEmpty(int x, int y); 

	/**
	* @return ���������� � ������� � ������ ������ ������
	*/
	Figure *getFigure(); 


	/**
	* @return ���������� � ���������  ������
	*/
	Figure *getSecondFigure();


	/**
	* ���� ��� ��������, ������� �������� ������ � ����������� shiftDirection
	*
	* @param shiftDirection �����������, � ������� ���������� �������� ������
	*/
	 void tryShiftFigure(ShiftDirection shiftDirection);


	 /**
	 * ���� ��� ��������, ������� ��������� ������ �� ������� �������
	 */
	 void tryRotateFigure();

	 /**
	 * ���� ������ ����� �������� ����, �������.
	 * ���� ��� ����������, ��������� ������ � ������ ��������� ������ � ������ �����.
	 */
	 void letFallDown();

	 /**
	 * @return ���� �� � ��������� ���� ��� ����� ��������� �����
	 */
	 bool isOverfilled(); 


	~GameField();

private :
	
	int field[Constants::COUNT_CELLS_X][Constants::COUNT_CELLS_Y + Constants::OFFSET_TOP]; // 0 -����� , 1 ���������
	//���������� �������� ����� � ������
	int countFilledCellsInLine[Constants::COUNT_CELLS_Y + Constants::OFFSET_TOP];

	Figure *figure = nullptr;
	Figure *secondFigure = nullptr;

	/**
	* ������ ����� ������ � ��������� ����
	* X-���������� ��� ��������� �� ������ ���� ����� � ������� ����,
	* ��� ������������ ������ ������ (MAX_FIGURE_WIDTH), ����� ������ � �����
	*/
	void spawnNewFigure();

	/**
	* ���� �� ���� ���� �������� ������ �����, �������� ����������� �������� ����� �� �� �����.
	*/
	void shiftLinesDown();



	/**
	* ���� ����� �������� ���������, ���������� � (�� �� �������� ���������!)
	*
	* @param y ����� ����������� �����
	* @return ���� �� ����� ����������
	*/
	 bool tryDestroyLine(int y);

	 
};



