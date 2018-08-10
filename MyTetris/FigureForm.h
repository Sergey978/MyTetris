#pragma once


class FigureForm
{
public:
	FigureForm();
	
	enum Form { I_FORM, J_FORM, L_FORM, O_FORM, S_FORM, Z_FORM, T_FORM };

	/**
	* @return Случайный объект этого enum'а, т.е. случайная форма
	*/
	static FigureForm::Form getRandomForm(); 
	

	~FigureForm();


};

