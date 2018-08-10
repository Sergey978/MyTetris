// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.

#include "TestApp.h"
#include<array>
#include"Coord.h"
#include "Enums.h"

void TestApp::drawGameOver()
{
	char gameOver[] = "Game Over ";
	for (int x = 0; x < strlen( gameOver) ; x++)
	SetChar(Constants::COUNT_CELLS_X + 5 + x, Constants::COUNT_CELLS_Y / 2, gameOver[x]);
}

TestApp::TestApp() : Parent(80, 40)
{
	
	endOfGame = false;
	shiftDirection = ShiftDirection::AWAITING;
	isRotateRequested = false;
	isBoostRequested = false;
	loopTime = 0;
	timerLimit = Constants::FALL_TIME / 1000.0f;

	gameField = new GameField;
}

void TestApp::logic(float deltaTime)
{
	loopTime += deltaTime;
	
	if (shiftDirection != ShiftDirection::AWAITING) { // Если есть запрос на сдвиг фигуры

													  /* Пробуем сдвинуть */
		gameField->tryShiftFigure(shiftDirection);

		/* Ожидаем нового запроса */
		shiftDirection = ShiftDirection::AWAITING;
	}

	if (isRotateRequested) { // Если есть запрос на поворот фигуры

							 /* Пробуем повернуть */
		gameField->tryRotateFigure();

		/* Ожидаем нового запроса */
		isRotateRequested = false;
	}

	
	if (loopTime > timerLimit )
		gameField->letFallDown();

	//обнуление таймера
	if (loopTime > timerLimit) loopTime = 0;
	//Если нажата кнопка ускорения
	if (isBoostRequested)
	{
		timerLimit = (Constants::FALL_TIME / Constants::BOOST_MULTIPLIER) / 1000.0f;
		gameField->letFallDown();
		isBoostRequested = false;
	}
	else
	{
		timerLimit = Constants::FALL_TIME / 1000.0f;
	}


	/* Если поле переполнено, игра закончена */
	endOfGame = endOfGame || gameField->isOverfilled();
	
}


void TestApp::drawGameField()
{
	

	//drawing border
	for (int x = 0; x < Constants::COUNT_CELLS_X + 2; x++)
	{
		for (int y = 0; y < Constants::COUNT_CELLS_Y + 3; y++)
		{
			if ( x == 0 || y == 0 || x == Constants::COUNT_CELLS_X + 1 || y == Constants::COUNT_CELLS_Y + 2)
			{
				SetChar(x, y, L'#');
			}
			
		}
	}
	//clear second figure area
	for (int x = Constants::COUNT_CELLS_X + 9; x < Constants::COUNT_CELLS_X + 14; x++)
		for (int y = 7; y < 13; y++)
		{
			SetChar(x, y, L' ');
		}
	
	//drawing second figure
	Figure *secondFigure = gameField->getSecondFigure();
	for (Coord coord : secondFigure->getCoords()) {
			
		SetChar(coord.x + Constants::COUNT_CELLS_X + 5 , Constants::COUNT_CELLS_Y - coord.y + 10, L'█');
	}


	//drawing game field
	for (int x = 0; x < Constants::COUNT_CELLS_X; x++)
	{
		for (int y = 0; y <= Constants::COUNT_CELLS_Y; y++)
		{
			if (gameField->isEmpty(x, y))
			{
				SetChar(x + 1, Constants::COUNT_CELLS_Y - y + 1, L' ');
			}
			else
			{
				SetChar(x + 1, Constants::COUNT_CELLS_Y - y + 1, L'█');
			}
		}
	}



	// drawing figure
	Figure *figure = gameField->getFigure();
	for (Coord coord : figure->getCoords()) {
		SetChar(coord.x + 1, Constants::COUNT_CELLS_Y - coord.y + 1,L'█');
	}

}

void TestApp::KeyPressed(int btnCode)
{
	
	switch (btnCode)

	{
	case 32: //space
	
		isRotateRequested = true;
		break;
	

	case 80:  //down
	
		isBoostRequested = true;
		break;
	

	case 75: //left
	
		shiftDirection = ShiftDirection::LEFT;
		break;
	

	case 77: //right
	
		shiftDirection = ShiftDirection::RIGHT;
		break;
	}
	

}

void TestApp::UpdateF(float deltaTime)
{
	
	if (!endOfGame)
	{

		logic( deltaTime);
		drawGameField();
	}
		
	else
	{
		drawGameOver();
	}
			
		
		

	
}
