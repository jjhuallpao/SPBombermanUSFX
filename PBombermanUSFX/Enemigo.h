#pragma once
class Enemigo
{
private:
	int anchoAvatar;
	int altoAvatar;
	int velocidad;
	int posicionX;
	int posicionY;

public:
	int getAnchoAvatr() { return anchoAvatar; }
	void setAnchoAvatar(int _anchoAvatar) { anchoAvatar = _anchoAvatar; }

	int getAltoAvatr() { return altoAvatar; }
	void setAltoAvatar(int _altoAvatar) { altoAvatar = _altoAvatar; }

	int getVelocidad() { return velocidad; }
	void setVelocidad(int _velocidad) { velocidad = _velocidad; }

	int getPosicionX() { return posicionX; }
	void setPosicionX(int _posicionX) { posicionX = _posicionX; }

	int getPosicionY() { return posicionY; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }


	void Mover();
	void Girar();
	void Morir();
	void Crear();

};

