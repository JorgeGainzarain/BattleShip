#include "Coordenada.h"

Coordenada::Coordenada()
{
	x = -1;
	y = -1;
}

Coordenada::Coordenada(Coordenada* c)
{
	Coordenada(c->x, c->y);
}

Coordenada::Coordenada(int i, int j)
{
	x = i;
	y = j;
}

int Coordenada::getX()
{
	return x;
}

int Coordenada::getY()
{
	return y;
}

void Coordenada::setCoord(int i, int j)
{
	x = i;
	y = j;
}

void Coordenada::setCoord(Coordenada c)
{
	x = c.getX();
	y = c.getY();
}
