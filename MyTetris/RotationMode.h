#pragma once

class RotationMode
{
public:
	RotationMode(int number);
	RotationMode();

	enum Mode {
		/** ��������� ��������� */
		NORMAL = 0,

		/** ���������, ��������������� �������� ������ ������� �������*/
		FLIP_CCW = 1,

		/** ���������, ��������������� ����������� ���������*/
		INVERT = 2,

		/** ���������, ��������������� �������� �� ������� ������� (��� ��� ��������� ������)*/
		FLIP_CW = 3

	};

	
	static RotationMode::Mode getNextRotationFrom(RotationMode::Mode previousRotation);

	~RotationMode();


private:
	int number;

	



};

