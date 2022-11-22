#include "Barco.h"
using namespace std;
static Casilla current;

Barco::Barco()
{
	this->size = 0;
	ArrayB = NULL;
}

Barco::Barco(int size, Casilla c1,int s, Tablero t)
{
	this->size = size;
	current = c1;
	ArrayB = new SegmentoBarco[size];
	for (int i = 0; i < size; i++)
	{
		SegmentoBarco aux = new SegmentoBarco(current);
		ArrayB[i] = aux;
		if (s == 0) current = t.prevx(current);
		if (s == 1) current = t.nextx(current);
		if (s == 2) current = t.nexty(current);
		if (s == 3) current = t.prevy(current);
	}
}

void Barco::llenarCasillas()
{
	for (int i = 0; i < size; i++)
	{
		ArrayB[i].getCasilla().llenar();
	}
}

Barco::Barco(Barco* b)
{
	Barco();
}


