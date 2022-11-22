#pragma once
#include <iostream>
#include <cstring>
#include"Casilla.h"
using namespace std;

class Tablero
{
private:

	int jugador;
	string tipo;
	Casilla **miMatriz;
public:

	Tablero(Tablero*);
	Tablero(int,string);
	Tablero();
	Casilla find(int, int);
	void Mostrar();
	void ColocarFlota(int);
	Casilla nextx(Casilla);
	Casilla nexty(Casilla);
	Casilla prevx(Casilla);
	Casilla prevy(Casilla);
	void LlenarCasilla(int,int);
	bool isAviable(Casilla);
};

