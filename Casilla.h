#pragma once
#include <iostream>
#include"Coordenada.h"
class Casilla
{
private:
	bool empty;
	Coordenada pos;
public:
	Casilla(Casilla*);
	Casilla();
	Casilla(int, int);
	Casilla(Coordenada);
	void mostrar();
	bool isEmpty();
	void llenar();
	void vaciar();
	int getx();
	int gety();
	void setcoord(Coordenada);
	void setcoord(int, int);
	static void Total();
};

