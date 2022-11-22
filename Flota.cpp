#include "Flota.h"
#include <stdio.h>
#include <string.h>
using namespace std;

Flota::Flota(int j)
{
	Jugador = j;
	ArrayF = NULL;
}

Flota::Flota(Flota* f)
{
	Flota(f->Jugador);
}

Flota::Flota(int j,Tablero t)
{
	Jugador = j;
	string barcos[5] = { "Buque","Portaaviones","Acorazado","Submarino","Patrullero" };
	bool b[5] = { true,true,true,true,true};
	ArrayF = new Barco[5];
	int n = 0;
	while (b[0]||b[1]||b[2]||b[3]||b[4])
	{
		t.Mostrar();
		cout << "\nHa seleccionado colocar flota, elija un barco a colocar:\n";
		for (int i = 0; i < 5; i++)
		{
			if (b[i])cout<< "\n" << (i+1) << "-" << barcos[i] << "(Longitud: "<< i+1 << ")";
		}
		int sel;
		cout << "\n: ";
		cin >> sel;
		sel--;
		cout << "\n Ha seleccionado: " << barcos[sel] << "\n";
		if (ColocarBarcos(sel,n,t))
		{
			n++;
			b[sel] = false;
		}
	}
}

bool Flota::ColocarBarcos(int j,int n,Tablero t)
{
	int sel1;
	string sel2;
	cout << "\nElija la casilla inicial del barco Ej: \nN:0\nL:A\n\n";
	t.Mostrar();
	cout << "\nN:";
	cin >> sel1;
	cout << "L:";
	cin >> sel2;
	int sel3;
	string ArrayC[10] = {"A","B","C","D","E","F","G","H","I","J"};
	for (int i = 0; i < 10; i++)
	{
		if (sel2 == ArrayC[i]) sel3 = i;
	}
	Casilla C1 = t.find(sel1, sel3);
	if (!t.isAviable(C1))
	{
		cout << "\nError: Esta casilla no es valida\n";
		return false;
	}
	int x = sel1;
	int y = sel3;
	cout << "\n\n(X:" << x << ",Y:" << y << ")\n";
	cout << "\n Casilla elegida: (Columna: " << x << ",Fila:" << y << ")\n";
	cin.ignore(std::numeric_limits<size_t>::max());
	if (j == 0)
	{
		t.LlenarCasilla(x, y);
		Barco Baux(j, C1, 1, t);
		ArrayF[n] = Baux;
		return true;
	}
	int sel4 = SeleccionarDireccion(C1,j,t);
	for (int i = 0; i < j; i++)
	{
		if (sel4 == 1) x--;
		if (sel4 == 2) x++;
		if (sel4 == 3) y--;
		if (sel4 == 4) y++;
		t.LlenarCasilla(x, y);
	}
	Barco Baux(j, C1, sel4, t);
	ArrayF[n] = Baux;
	return true;
}

int Flota::SeleccionarDireccion(Casilla inicial, int size, Tablero t)
{
	cout << "Elige hacia donde orientar el barco:\n";
	int x = inicial.getx();
	int y =  inicial.gety();
	int xaux;
	int yaux;
	bool Dir[4] = { true,true,true,true };
	if (x - size >= 0)
	{
		cout << "\nComprobando Izquierda";
		for (xaux = x; xaux >= x - size; xaux--)
		{
			if (!t.isAviable(t.find(xaux, y))) Dir[0] = false;
		}
	}
	else Dir[0] = false;
	if (x + size <= 9)
	{
		cout << "\nComprobando Derecha";
		for (xaux = x; xaux <= x + size; xaux++)
		{
			if (!t.isAviable(t.find(xaux, y))) Dir[1] = false;
		}
	}
	else Dir[1] = false;
	if (y - size >= 0)
	{
		cout << "\nComprobando Arriba";
		for (yaux = y; yaux >= y - size; yaux--)
		{
			if (!t.isAviable(t.find(x, yaux))) Dir[2] = false;
		}
	}
	else Dir[2] = false;
	if (y + size <= 9)
	{
		cout << "\nComprobando  Abajo";
		for (yaux = y; yaux <= y + size; yaux++)
		{
			if (!t.isAviable(t.find(x, yaux))) Dir[3] = false;
		}
	}
	else Dir[3] = false;

	if (!Dir[0] && !Dir[1] && !Dir[2] && !Dir[3])
	{
		cout << "\nSeleccion Casilla no valida, No hay espacio.\n";
		return false;
	}
	t.LlenarCasilla(x, y);
	t.Mostrar();

	if (Dir[0]) cout << "1-Izquierda\n";
	if (Dir[1]) cout << "2-Derecha\n";
	if (Dir[2]) cout << "3-Arriba\n";
	if (Dir[3]) cout << "4-Abajo\n";
	cout << ": ";
	int sel4;
	cin >> sel4;
	return sel4;
}
