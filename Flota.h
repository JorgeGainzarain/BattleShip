#pragma once
#include "Barco.h"
#include "Tablero.h"
#include "Casilla.h"
#include <iostream>
#include <cstring>
#include "Barco.h"
#include <stdio.h>
#include <string.h>

class Flota
{
private:
	int Jugador;
	Barco* ArrayF;

public: 
	Flota(int);
	Flota(Flota*);
	Flota(int,Tablero);
	bool ColocarBarcos(int, int, Tablero);
	int SeleccionarDireccion(Casilla, int, Tablero);
};

