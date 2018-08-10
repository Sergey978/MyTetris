// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.

#include "TestApp.h"
#include <ctime>

void main ()
{
	system("mode con cols=80 lines=40");
	srand((unsigned)time(0));
	TestApp app;
	app.Run();
}
