#pragma once
class Puerta
{
private:
	int altura;
	int ancho;
	int posicionX;
	int posicionY;

public:
	int getAltura() { return altura; }
	void setAltura(int _altura) { altura = _altura; }

	int getAncho() { return ancho; }
	void setAncho(int _ancho) { ancho = _ancho; }

	int getPosicionX() { return posicionX; }
	void setPosicionX(int _posicionX) { posicionX = _posicionX; }

	int getPosicionY() { return posicionY; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }

	void Abrir();
};

