#pragma once

class RotationMode
{
public:
	RotationMode(int number);
	RotationMode();

	enum Mode {
		/** Ќачальное положение */
		NORMAL = 0,

		/** ѕоложение, соответствующее повороту против часовой стрелки*/
		FLIP_CCW = 1,

		/** ѕоложение, соответствующее зеркальному отражению*/
		INVERT = 2,

		/** ѕоложение, соответствующее повороту по часовой стрелке (или трЄм поворотам против)*/
		FLIP_CW = 3

	};

	
	static RotationMode::Mode getNextRotationFrom(RotationMode::Mode previousRotation);

	~RotationMode();


private:
	int number;

	



};

