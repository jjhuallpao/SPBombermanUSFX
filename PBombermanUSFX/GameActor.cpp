#include "GameActor.h"

GameActor::GameActor() :GameObject() {
	posicionX = 0;
	posicionY = 0;
	imagenX = 0;
	imagenY = 0;
	ancho = 34;
	alto = 34;

	solido = true;
	indestructible = false;
	visible = true;
	movil = false;
	enMovimiento = false;
	aereo = false;
	terrestre = true;
	subterraneo = false;

	velocidad = 5;
	energia = 100;
	vidas = 3;

	textura = nullptr;
	tileActual = nullptr;
	tileSiguiente = nullptr;
	direccionActual = MOVE_DIRECTION_NONE;
	direccionSiguiente = MOVE_DIRECTION_NONE;
}


GameActor::GameActor(Texture* _textura, Tile* _tileActual) :GameObject() {
	posicionX = 0;
	posicionY = 0;
	imagenX = 0;
	imagenY = 0;
	ancho = 34;
	alto = 34;

	solido = true;
	indestructible = false;
	visible = true;
	movil = false;
	enMovimiento = false;
	aereo = false;
	terrestre = true;
	subterraneo = false;

	velocidad = 5;
	energia = 100;
	vidas = 3;

	textura = _textura;
	tileActual = _tileActual;
	tileSiguiente = nullptr;
	direccionActual = MOVE_DIRECTION_NONE;
	direccionSiguiente = MOVE_DIRECTION_NONE;
}

void GameActor::render()
{
	if (visible) {
		SDL_Rect* cuadroAnimacion = new SDL_Rect({ imagenX, imagenY, getAncho(), getAlto() });
		textura->render(getPosicionX(), getPosicionY(), cuadroAnimacion);
	}
}
