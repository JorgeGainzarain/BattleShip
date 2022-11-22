#include "SegmentoBarco.h"
using namespace std;

SegmentoBarco::SegmentoBarco()
{
	this->status = false;
	this->c = NULL;
}

SegmentoBarco::SegmentoBarco(SegmentoBarco* s)
{
	SegmentoBarco(s->c);
	SegmentoBarco();
}

SegmentoBarco::SegmentoBarco(Casilla c)
{
	status = true;
	this->c = c;
	c.llenar();
}

bool SegmentoBarco::getstatus()
{
	return this->status;
}


Casilla SegmentoBarco::getCasilla()
{
	return this->c;
}


