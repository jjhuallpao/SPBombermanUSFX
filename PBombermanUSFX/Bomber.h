#pragma once
class Bomber
{
private:
	int anchoAvatar;
	int altoAvatar;
	int velocidad;
	int vidas;
	int posicionX;
	int posicionY;

public:
	int getAnchoAvatr() { return anchoAvatar; }
	void setAnchoAvatar(int _anchoAvatar) { anchoAvatar = _anchoAvatar; }

	int getAltoAvatr() { return altoAvatar; }
	void setAltoAvatar(int _altoAvatar) { altoAvatar = _altoAvatar; }

	int getVelocidad() { return velocidad; }
	void setVelocidad(int _velocidad) { velocidad = _velocidad; }

	int getVidas() { return vidas; }
	void setVidas(int _vidas) { vidas = _vidas; }

	int getPosicionX() { return posicionX; }
	void setPosicionX(int _posicionX) { posicionX = _posicionX; }

	int getPosicionY() { return posicionY; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }

	void Morir();
	void Correr();
	void Mover();
	void ColocarBomba();
	void ActivarBomba();
	void Crear();
	void Girar();
};

