#include "FigureForm.h"
#include <stdlib.h>


FigureForm::FigureForm()
{
}

FigureForm::Form FigureForm::getRandomForm()
{
	
		int formNumber =  rand() % Form::T_FORM + 1;
		return Form(formNumber);
	
}


FigureForm::~FigureForm()
{
}
