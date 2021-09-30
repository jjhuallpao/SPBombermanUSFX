#include "GameActor.h"

GameActor::GameActor(Texture* _textura) :GameObject() {
	posicionX = 0;
	posicionY = 0;
	imagenX = 0;
	imagenY = 0;
	ancho = 25;
	alto = 25;

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
	direccionActual = GAME_DIRECTION_NONE;
	direccionSiguiente = GAME_DIRECTION_NONE;
}

void GameActor::render()
{
	if (visible) {
		SDL_Rect* cuadroAnimacion = new SDL_Rect({ imagenX, imagenY, getAncho(), getAlto() });
		textura->render(getPosicionX(), getPosicionY(), cuadroAnimacion);
	}
}
