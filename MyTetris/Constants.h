#pragma once
class Constants
{
public:
	Constants();
	/* ���������� ����� �� ������ �� ����������� � ��������� */
	static const unsigned int COUNT_CELLS_X = 15;
	static const unsigned int  COUNT_CELLS_Y = 30;

	/*��������� ������������ ������, � ������� ��������� ������*/
	static const unsigned int OFFSET_TOP = 3;

	/* ���������� ���, � ������� ������������� �������� �������,
	* ���� ������������ ����� �������������� �������
	*/
	static const unsigned int BOOST_MULTIPLIER = 5;

	/*����� �� ������� ������ ������ �� ���� ������ */
	static const unsigned int FALL_TIME = 300;

		
	/* ����������� ��������� ������ ������ */
	static const unsigned int MAX_FIGURE_WIDTH = 4;

	~Constants();
};

