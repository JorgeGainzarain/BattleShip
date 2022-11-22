#pragma once
class Coordenada
{
private:
	int x;
	int y;
public:
	Coordenada();
	Coordenada(Coordenada*);
	Coordenada(int, int);
	int getX();
	int getY();
	void setCoord(int, int);
	void setCoord(Coordenada);
};

