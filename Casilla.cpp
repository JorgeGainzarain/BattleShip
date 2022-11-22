#include "Casilla.h"
#include "SegmentoBarco.h"
#include <iostream>
using namespace std;
static int counter = 0;

Casilla::Casilla(Casilla* caux)
{
	Casilla();
}
Casilla::Casilla()
{
	empty = true;
	pos = new Coordenada();
	counter++;
	//Casilla::Total();
}
Casilla::Casilla(int j, int k)
{
	this->pos = new Coordenada(j, k);
	this->empty = true;
}
Casilla::Casilla(Coordenada c)
{
	pos = c;
	this->empty = true;
	counter++;
	//Casilla::Total();
}

void Casilla::mostrar()
{
	if (this->empty) cout << "|0";
	else cout << "|X";
}


bool Casilla::isEmpty()
{
	return empty;
}


void Casilla::llenar()
{
	this->empty = false;
	cout << "\nCasilla llenada (X:" << getx() << " Y:" << gety() << ")\n";
}

void Casilla::vaciar()
{
	empty = true;
}

int Casilla::getx()
{
	return pos.getX();
}

int Casilla::gety()
{
	return pos.getY();
}

void Casilla::setcoord(Coordenada c)
{
	pos.setCoord(c);
}

void Casilla::setcoord(int i, int j)
{
	pos.setCoord(i, j);
}

void Casilla::Total()
{
	cout << "\nTotal casillas: " << counter <<"\n";
}


