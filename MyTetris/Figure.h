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
	* @return Координаты реальных ячеек фигуры в текущем состоянии
	*/
	std::array<Coord, Constants::MAX_FIGURE_WIDTH> getCoords();

	/**
	* @return Координаты ячеек фигуры, как если бы
	* она была повёрнута против часовой стрелки от текущего положения
	*/
	std::array<Coord, Constants::MAX_FIGURE_WIDTH>  getRotatedCoords(); 


	/**
	* Поворачивает фигуру против часовой стрелки
	*/
	 void rotate(); 


	 /**
	 * @param direction Направление сдвига
	 * @return Координаты ячеек фигуры, как если бы
	 * она была сдвинута в указано направлении
	 */
	 std::array<Coord, Constants::MAX_FIGURE_WIDTH> getShiftedCoords(ShiftDirection direction); 


	 /**
	 * Меняет мнимую X-координату фигуры
	 * для сдвига в указаном направлении
	 *
	 * @param direction Направление сдвига
	 */
	 void shift(ShiftDirection direction); 


	 /**
	 * @return Координаты ячеек фигуры, как если бы
	 * она была сдвинута вниз на одну ячейку
	 */
	 std::array<Coord, Constants::MAX_FIGURE_WIDTH>  getFallenCoords(); 

	 /**
	 * Меняет мнимую Y-координаты фигуры
	 * для сдвига на одну ячейку вниз
	 */
	 void fall(); 


	virtual ~Figure();

private:
	/**
	* Мнимая координата фигуры. По этой координате
	* через маску генерируются координаты реальных
	* блоков фигуры.
	*/
	Coord metaPointCoord;
	RotationMode::Mode currentRotation;
	FigureForm::Form form;


};

