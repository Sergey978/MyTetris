#pragma once

#include "Coord.h"
#include "RotationMode.h"
#include "FigureForm.h"
#include "Constants.h"
#include"Enums.h"
#include <array>


class Figure
{
public:
	Figure(Coord metaPointCoords);
	Figure(Coord metaPointCoords, RotationMode::Mode mode, FigureForm::Form form);

	/**
	* @return ���������� �������� ����� ������ � ������� ���������
	*/
	std::array<Coord, Constants::MAX_FIGURE_WIDTH> getCoords();

	/**
	* @return ���������� ����� ������, ��� ���� ��
	* ��� ���� �������� ������ ������� ������� �� �������� ���������
	*/
	std::array<Coord, Constants::MAX_FIGURE_WIDTH>  getRotatedCoords(); 


	/**
	* ������������ ������ ������ ������� �������
	*/
	 void rotate(); 


	 /**
	 * @param direction ����������� ������
	 * @return ���������� ����� ������, ��� ���� ��
	 * ��� ���� �������� � ������� �����������
	 */
	 std::array<Coord, Constants::MAX_FIGURE_WIDTH> getShiftedCoords(ShiftDirection direction); 


	 /**
	 * ������ ������ X-���������� ������
	 * ��� ������ � �������� �����������
	 *
	 * @param direction ����������� ������
	 */
	 void shift(ShiftDirection direction); 


	 /**
	 * @return ���������� ����� ������, ��� ���� ��
	 * ��� ���� �������� ���� �� ���� ������
	 */
	 std::array<Coord, Constants::MAX_FIGURE_WIDTH>  getFallenCoords(); 

	 /**
	 * ������ ������ Y-���������� ������
	 * ��� ������ �� ���� ������ ����
	 */
	 void fall(); 


	virtual ~Figure();

private:
	/**
	* ������ ���������� ������. �� ���� ����������
	* ����� ����� ������������ ���������� ��������
	* ������ ������.
	*/
	Coord metaPointCoord;
	RotationMode::Mode currentRotation;
	FigureForm::Form form;


};

