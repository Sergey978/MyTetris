#pragma once
class Constants
{
public:
	Constants();
	/*  оличество €чеек на экране по горизонтали и вертикали */
	static const unsigned int COUNT_CELLS_X = 15;
	static const unsigned int  COUNT_CELLS_Y = 30;

	/*Ќевидимое пространство сверху, в котором создаютс€ фигуры*/
	static const unsigned int OFFSET_TOP = 3;

	/*  оличество раз, в которое увеличиваетс€ скорость падени€,
	* если пользователь нажал соответсвующую клавишу
	*/
	static const unsigned int BOOST_MULTIPLIER = 5;

	/*¬рем€ за которое фигура падает на одну клетку */
	static const unsigned int FALL_TIME = 300;

		
	/* ћаксимально возможна€ ширина фигуры */
	static const unsigned int MAX_FIGURE_WIDTH = 4;

	~Constants();
};

