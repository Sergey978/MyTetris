// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.

#pragma once

#include "BaseApp.h"
#include"GameField.h"
#include"Enums.h"

class TestApp : public BaseApp
{
	typedef BaseApp Parent;

	private:
		/** Флаг для завершения основного цикла программы */
		boolean endOfGame;


		/** Игровое поле. См. документацию GameField */
		GameField * gameField;

		/** Направление для сдвига, полученное за последнюю итерацию */
		ShiftDirection shiftDirection;

		/** Был ли за последнюю итерацию запрошен поворот фигуры */
		boolean isRotateRequested;

		/** Было ли за последнюю итерацию запрошено ускорение падения*/
		boolean isBoostRequested;

		
		// таймер задающий время между перемещением фигуры при падении 
		float loopTime;
		//лимит таймера 
		float timerLimit;

		/**
		* Здесь происходят основные игровые действия --
		* запросы пользователя передаются на исполнение,
		* обновляется игровое поле (и фигура)
		*/
		void logic(float deltaTime);


		/**
		* Отрисовка игрового поля
		*/
		void drawGameField();

		/**
		* Game Over
		*/

		void drawGameOver();
	public:
		TestApp();
		virtual void KeyPressed(int btnCode);
		virtual void UpdateF(float deltaTime);
};
