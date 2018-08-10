#include "CoordMask.h"




/**
* ������ ����� -- ������, ������� �� ������ ���������� ������ �
* ��������� � �������� ���������� 4 ���������� �������� ������
* ������, ������� ������ ������������.
* �.�. ����� ����� �������������� ����� ������.
*/

CoordMask::CoordMask()
{
}

std::array<Coord, Constants::MAX_FIGURE_WIDTH>   CoordMask::generateFigure(Coord initialCoord, RotationMode::Mode rotation,FigureForm::Form form){
	std::array<Coord, Constants::MAX_FIGURE_WIDTH>  ret ;

	switch (form)
	{
		/* �������� [][][][] */
	case FigureForm::I_FORM:

		switch (rotation) {
		case RotationMode::NORMAL:
		case RotationMode::INVERT:
			ret[0] = initialCoord;
			ret[1] =  Coord(initialCoord.x, initialCoord.y - 1);
			ret[2] =  Coord(initialCoord.x, initialCoord.y - 2);
			ret[3] =  Coord(initialCoord.x, initialCoord.y - 3);
			break;
		case RotationMode::FLIP_CCW:
		case RotationMode::FLIP_CW:
			ret[0] = initialCoord;
			ret[1] =  Coord(initialCoord.x + 1, initialCoord.y);
			ret[2] =  Coord(initialCoord.x + 2, initialCoord.y);
			ret[3] =  Coord(initialCoord.x + 3, initialCoord.y);
			break;
		}


		break;
		/* ��������  []
		*            [][][]
		*/
	case FigureForm::J_FORM:
		switch (rotation) {
		case RotationMode::NORMAL:
			ret[0] = Coord(initialCoord.x + 1, initialCoord.y);
			ret[1] = Coord(initialCoord.x + 1, initialCoord.y - 1);
			ret[2] = Coord(initialCoord.x + 1, initialCoord.y - 2);
			ret[3] = Coord(initialCoord.x, initialCoord.y - 2);
			break;
		case RotationMode::INVERT:
			ret[0] = Coord(initialCoord.x + 1, initialCoord.y);
			ret[1] = initialCoord;
			ret[2] = Coord(initialCoord.x, initialCoord.y - 1);
			ret[3] = Coord(initialCoord.x, initialCoord.y - 2);
			break;
		case RotationMode::FLIP_CCW:
			ret[0] = initialCoord;
			ret[1] = Coord(initialCoord.x + 1, initialCoord.y);
			ret[2] = Coord(initialCoord.x + 2, initialCoord.y);
			ret[3] = Coord(initialCoord.x + 2, initialCoord.y - 1);
			break;
		case RotationMode::FLIP_CW:
			ret[0] = initialCoord;
			ret[1] = Coord(initialCoord.x, initialCoord.y - 1);
			ret[2] = Coord(initialCoord.x + 1, initialCoord.y - 1);
			ret[3] = Coord(initialCoord.x + 2, initialCoord.y - 1);
			break;

		}
		break;

			/* ��������    []
			*          [][][]
			*/
	case FigureForm::L_FORM:

		switch (rotation) {
		case RotationMode::NORMAL:
			ret[0] = initialCoord;
			ret[1] = Coord(initialCoord.x, initialCoord.y - 1);
			ret[2] = Coord(initialCoord.x, initialCoord.y - 2);
			ret[3] = Coord(initialCoord.x + 1, initialCoord.y - 2);
			break;
		case RotationMode::INVERT:
			ret[0] = initialCoord;
			ret[1] = Coord(initialCoord.x + 1, initialCoord.y);
			ret[2] = Coord(initialCoord.x + 1, initialCoord.y - 1);
			ret[3] = Coord(initialCoord.x + 1, initialCoord.y - 2);
			break;
		case RotationMode::FLIP_CCW:
			ret[0] = Coord(initialCoord.x, initialCoord.y - 1);
			ret[1] = Coord(initialCoord.x + 1, initialCoord.y - 1);
			ret[2] = Coord(initialCoord.x + 2, initialCoord.y - 1);
			ret[3] = Coord(initialCoord.x + 2, initialCoord.y);
			break;
		case RotationMode::FLIP_CW:
			ret[0] = Coord(initialCoord.x, initialCoord.y - 1);
			ret[1] = initialCoord;
			ret[2] = Coord(initialCoord.x + 1, initialCoord.y);
			ret[3] = Coord(initialCoord.x + 2, initialCoord.y);
			break;

		}

		break;

		/* �������� [][]
		*           [][]
		*/
	case FigureForm::O_FORM:

		ret[0] = initialCoord;
		ret[1] =  Coord(initialCoord.x, initialCoord.y - 1);
		ret[2] =  Coord(initialCoord.x + 1, initialCoord.y - 1);
		ret[3] =  Coord(initialCoord.x + 1, initialCoord.y);

		break;

		/* ��������  [][]
		*          [][]
		*/
	case FigureForm::S_FORM:

		switch (rotation) {
		case RotationMode::NORMAL:
		case RotationMode::INVERT:
			ret[0] = Coord(initialCoord.x, initialCoord.y - 1);
			ret[1] = Coord(initialCoord.x + 1, initialCoord.y - 1);
			ret[2] = Coord(initialCoord.x + 1, initialCoord.y);
			ret[3] = Coord(initialCoord.x + 2, initialCoord.y);
			break;
		case RotationMode::FLIP_CCW:
		case RotationMode::FLIP_CW:
			ret[0] = initialCoord;
			ret[1] = Coord(initialCoord.x, initialCoord.y - 1);
			ret[2] = Coord(initialCoord.x + 1, initialCoord.y - 1);
			ret[3] = Coord(initialCoord.x + 1, initialCoord.y - 2);
			break;
		}

		break;

		/* �������� [][]
		*             [][]
		*/
	
		case FigureForm::Z_FORM:

			switch (rotation) {
			case RotationMode::NORMAL:
			case RotationMode::INVERT:
				ret[0] = initialCoord;
				ret[1] = Coord(initialCoord.x + 1, initialCoord.y);
				ret[2] = Coord(initialCoord.x + 1, initialCoord.y - 1);
				ret[3] = Coord(initialCoord.x + 2, initialCoord.y - 1);
				break;
			case RotationMode::FLIP_CCW:
			case RotationMode::FLIP_CW:
				ret[0] = Coord(initialCoord.x + 1, initialCoord.y);
				ret[1] = Coord(initialCoord.x + 1, initialCoord.y - 1);
				ret[2] = Coord(initialCoord.x, initialCoord.y - 1);
				ret[3] = Coord(initialCoord.x, initialCoord.y - 2);
				break;
			}
		break;

		/* �������� [][][]
		*             []
		*/
		
case FigureForm::T_FORM:
	switch (rotation) {
	case RotationMode::NORMAL:
		ret[0] = initialCoord;
		ret[1] =  Coord(initialCoord.x + 1, initialCoord.y);
		ret[2] =  Coord(initialCoord.x + 1, initialCoord.y - 1);
		ret[3] =  Coord(initialCoord.x + 2, initialCoord.y);
		break;
	case RotationMode::INVERT:
		ret[0] =  Coord(initialCoord.x, initialCoord.y - 1);
		ret[1] =  Coord(initialCoord.x + 1, initialCoord.y - 1);
		ret[2] =  Coord(initialCoord.x + 1, initialCoord.y);
		ret[3] =  Coord(initialCoord.x + 2, initialCoord.y - 1);
		break;
	case RotationMode::FLIP_CCW:
		ret[0] = initialCoord;;
		ret[1] =  Coord(initialCoord.x, initialCoord.y - 1);
		ret[2] =  Coord(initialCoord.x + 1, initialCoord.y - 1);
		ret[3] =  Coord(initialCoord.x, initialCoord.y - 2);
		break;
	case RotationMode::FLIP_CW:
		ret[0] =  Coord(initialCoord.x + 1, initialCoord.y);
		ret[1] =  Coord(initialCoord.x + 1, initialCoord.y - 1);
		ret[2] =  Coord(initialCoord.x, initialCoord.y - 1);
		ret[3] =  Coord(initialCoord.x + 1, initialCoord.y - 2);
		break;
	}

		break;




	}
	return ret;
}


CoordMask::~CoordMask()
{
}
