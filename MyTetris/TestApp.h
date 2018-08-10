// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.

#pragma once

#include "BaseApp.h"
#include"GameField.h"
#include"Enums.h"

class TestApp : public BaseApp
{
	typedef BaseApp Parent;

	private:
		/** ���� ��� ���������� ��������� ����� ��������� */
		boolean endOfGame;


		/** ������� ����. ��. ������������ GameField */
		GameField * gameField;

		/** ����������� ��� ������, ���������� �� ��������� �������� */
		ShiftDirection shiftDirection;

		/** ��� �� �� ��������� �������� �������� ������� ������ */
		boolean isRotateRequested;

		/** ���� �� �� ��������� �������� ��������� ��������� �������*/
		boolean isBoostRequested;

		
		// ������ �������� ����� ����� ������������ ������ ��� ������� 
		float loopTime;
		//����� ������� 
		float timerLimit;

		/**
		* ����� ���������� �������� ������� �������� --
		* ������� ������������ ���������� �� ����������,
		* ����������� ������� ���� (� ������)
		*/
		void logic(float deltaTime);


		/**
		* ��������� �������� ����
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
