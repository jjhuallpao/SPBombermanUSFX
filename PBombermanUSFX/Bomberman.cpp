#include "Bomberman.h"

Bomberman::Bomberman(Texture* _textura, Tile* _tileActual) :GamePawn(_textura, _tileActual)
{
	
}

void Bomberman::setTileActual(Tile* _tileNuevo)
{
}

void Bomberman::update()
{
	if (keyboardInput->IsKeyOn(botonAbajo)) {
		this->setPosicionY(getPosicionY() + 1);
	}
	else if (keyboardInput->IsKeyOn(botomArriba)) {
		this->setPosicionY(getPosicionY() - 1);
	}
	else if (keyboardInput->IsKeyOn(botonDerecha)) {
		this->setPosicionX(getPosicionX() + 1);
	}
	else if (keyboardInput->IsKeyOn(botomIzquierda)) {
		this->setPosicionX(getPosicionX() - 1);
	}

	if (keyboardInput->IsKeyOn(botonAbajo2)) {
		this->setPosicionY(getPosicionY() + 1);
	}
	else if (keyboardInput->IsKeyOn(botonArriba2)) {
		this->setPosicionY(getPosicionY() - 1);
	}
	else if (keyboardInput->IsKeyOn(botonDerecha2)) {
		this->setPosicionX(getPosicionX() + 1);
	}
	else if (keyboardInput->IsKeyOn(botonIzquierda2)) {
		this->setPosicionX(getPosicionX() - 1);
	}
}



void Bomberman::render()
{
	GamePawn::render();
}
