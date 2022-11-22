#pragma once
#include <iostream>
#include <cstring>
#include "Tablero.h"
#include "SegmentoBarco.h"


class Barco
{
private:
	int size;
	SegmentoBarco* ArrayB;
public:
	Barco();
	Barco(Barco*);
	Barco(int,Casilla,int,Tablero);
	void llenarCasillas();
};

