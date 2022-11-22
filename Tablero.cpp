#include "Tablero.h"
#include <iostream>
#include <cstring>
#include "Casilla.h"
#include "Flota.h"
using namespace std;

Tablero::Tablero(Tablero* t)
{
	Tablero(t->jugador, t->tipo);
}

Tablero::Tablero(int J, string t)
{
	jugador = J;
	this->tipo= t;
	miMatriz = new Casilla*[10];
	for (int i = 0; i < 10; i++)
	{
		miMatriz[i] = new Casilla[10];
	}
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			miMatriz[i][j].setcoord(j,i);
		}
	}
}

Tablero::Tablero()
{
	jugador = 0;
	tipo = "default";
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			miMatriz[i][j] = NULL;
		}
	}
}


Casilla Tablero::find(int c, int f)
{
	//cout << "\n\nFind working with (X: " << f << ", Y:" << c << ")\n\n";
	Casilla nuevaCasilla(c, f);
	nuevaCasilla.vaciar();
	if (c < 0 || c > 9) return nuevaCasilla;
	if (f < 0 || f > 9) return nuevaCasilla;
	return this->miMatriz[f][c];
}

void Tablero::Mostrar()
{
	string letras[10]= {"A","B","C","D","E","F","G","H","I","J"};
	for (int i = 0; i < 10; i++)
	{
		cout << "   " << i ;
	}
	cout << "\n";
	for (int i = 0; i < 10; i++)
	{
		cout << letras[i];
		for (int j = 0; j < 10; j++)
		{
			if (miMatriz[i][j].isEmpty()) cout << "| O ";
			else cout << "| X ";
		}
		cout << "|\n";
	}
}

void Tablero::ColocarFlota(int j)
{
	new Flota(j,this);
}

Casilla Tablero::nextx(Casilla c)
{
	return this->find(c.getx()+1,c.gety());
}

Casilla Tablero::nexty(Casilla c)
{
	return this->find(c.getx(), c.gety()+1);
}

Casilla Tablero::prevx(Casilla c)
{
	return this->find(c.getx()-1, c.gety());
}

Casilla Tablero::prevy(Casilla c)
{
	return this->find(c.getx(), c.gety()-1);
}

void Tablero::LlenarCasilla(int x, int y)
{
	miMatriz[y][x].llenar();
}

bool Tablero::isAviable(Casilla c)
{
	int x = c.getx();
	int y = c.gety();
	//Casilla media
	if (!c.isEmpty() || x == -1) return false;
	//Lados
	else if (!nexty(c).isEmpty()) return false;
	else if (!prevy(c).isEmpty()) return false;
	else if (!nextx(c).isEmpty()) return false;
	else if (!prevx(c).isEmpty()) return false;
	//Esquinas
	else if (!find(x + 1, y + 1).isEmpty()) return false;
	else if (!find(x + 1, y - 1).isEmpty()) return false;
	else if (!find(x - 1, y + 1).isEmpty()) return false;
	else if (!find(x - 1, y - 1).isEmpty()) return false;
	//Comprobadas las 8 casillas que le rodean
	else return true;

}
