#include "RotationMode.h"


RotationMode::RotationMode(int number)
{
	this->number = number;
}
RotationMode::RotationMode()
{
	number = 0;
}
RotationMode::Mode RotationMode::getNextRotationFrom(RotationMode::Mode previousRotation){

	int newRotationIndex = (previousRotation + 1) % 4;
	return RotationMode::Mode(newRotationIndex);

}

RotationMode::~RotationMode()
{
}
