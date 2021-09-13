#pragma once
class Bomba
{
private:
	int altura;
	int ancho;
	int tiempoDuracion;
	int posicionX;
	int posicionY;
	int alcanceExplosionX;
	int alcanceExplosionY;

public:
	int getAltura() { return altura; }
	void setAltura(int _altura) { altura = _altura; }

	int getAncho() { return ancho; }
	void setAncho(int _ancho) { ancho = _ancho; }

	int getTiempoDuracion() { return tiempoDuracion; }
	void setTiempoDuracion(int _tiempoDuracion) { tiempoDuracion = _tiempoDuracion; }

	int getPosicionX() { return posicionX; }
	void setPosicionX(int _posicionX) { posicionX = _posicionX; }

	int getPosicionY() { return posicionY; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }

	int getAlcanceExplosionX() { return alcanceExplosionX; }
	void setAlcanceExplosionX(int _alcanceExplosionX) { alcanceExplosionX = _alcanceExplosionX; }

	int getAalcanceExplosionY() { return alcanceExplosionY; }
	void setAlcanceExplosionY(int _alcanceExplosionY) { alcanceExplosionY = _alcanceExplosionY; }

	void DestruirEnemigo();
	void DestruirMuro();
};

