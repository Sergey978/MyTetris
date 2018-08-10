#include "Figure.h"
#include "CoordMask.h"
#include<array>

Figure::Figure(Coord metaPointCoords)
{
	this->metaPointCoord = metaPointCoords;
	this->currentRotation = RotationMode::NORMAL;
	this->form = FigureForm::getRandomForm();
}

Figure::Figure(Coord metaPointCoords, RotationMode::Mode rotation, FigureForm::Form form)
{
	this->metaPointCoord = metaPointCoords;
	this->currentRotation = rotation;
	this->form = form;
}

std::array<Coord, Constants::MAX_FIGURE_WIDTH> Figure::getCoords()
{
	return CoordMask::generateFigure(metaPointCoord, currentRotation , form);
}

std::array<Coord, Constants::MAX_FIGURE_WIDTH> Figure::getRotatedCoords()
{

	
		return CoordMask::generateFigure(metaPointCoord, RotationMode::getNextRotationFrom(currentRotation), form);
	
	
}

void Figure::rotate()
{
	
		currentRotation = RotationMode::getNextRotationFrom(currentRotation);
	
}

std::array<Coord, Constants::MAX_FIGURE_WIDTH> Figure::getShiftedCoords(ShiftDirection direction)
{
	
	
		Coord newFirstCell ;

		switch (direction) {
		case LEFT:
			newFirstCell =  Coord(metaPointCoord.x - 1, metaPointCoord.y);
			break;
		case RIGHT:
			newFirstCell =  Coord(metaPointCoord.x + 1, metaPointCoord.y);
			break;
		
		}

		return CoordMask::generateFigure(newFirstCell, currentRotation, form);
	


}

void Figure::shift(ShiftDirection direction)
{

	
		switch (direction) {
		case LEFT:
			metaPointCoord.x--;
			break;
		case RIGHT:
			metaPointCoord.x++;
			break;
		
		}
	
}

std::array<Coord, Constants::MAX_FIGURE_WIDTH> Figure::getFallenCoords()
{
	
		Coord newFirstCell =  Coord(metaPointCoord.x, metaPointCoord.y - 1);

		return CoordMask::generateFigure(newFirstCell, currentRotation, form);
	
}

void Figure::fall()
{
	
		metaPointCoord.y--;
	
}


Figure::~Figure()
{
}
