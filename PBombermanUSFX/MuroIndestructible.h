#pragma once
class MuroIndestructible
{
	int altura;
	int ancho;
	int tiempoVisible;
	int posicionX;
	int posicionY;

public:
	int getAltura() { return altura; }
	void setAltura(int _altura) { altura = _altura; }

	int getAncho() { return ancho; }
	void setAncho(int _ancho) { ancho = _ancho; }

	int getVisible() { return tiempoVisible; }
	void setVisible(int _tiempoVisible) { tiempoVisible = _tiempoVisible; }

	int getPosicionX() { return posicionX; }
	void setPosicionX(int _posicionX) { posicionX = _posicionX; }

	int getPosicionY() { return posicionY; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }
};

