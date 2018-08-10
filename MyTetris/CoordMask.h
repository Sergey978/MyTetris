#pragma once
#include "Coord.h"
#include "Constants.h"
#include "RotationMode.h"
#include "figureform.h"

#include <array>



class CoordMask
{
public:
	CoordMask();
	
	static std::array<Coord, Constants::MAX_FIGURE_WIDTH>  generateFigure(Coord initialCoord, RotationMode::Mode rotation, FigureForm::Form form);
	
	~CoordMask();
};

