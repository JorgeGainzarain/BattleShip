#pragma once
#include "Casilla.h"
class SegmentoBarco
{
private:
	bool status;
	Casilla c;
public:
	SegmentoBarco();
	SegmentoBarco(SegmentoBarco*);
	SegmentoBarco(Casilla);
	bool getstatus();
	Casilla getCasilla();


};

