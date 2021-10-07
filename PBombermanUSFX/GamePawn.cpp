#include "GamePawn.h"

GamePawn::GamePawn():GameActor(), keyboardInput(KeyboardInput::Instance())
{

}

GamePawn::GamePawn(Texture* _textura, Tile* _tileActual):GameActor(_textura, _tileActual)
{
	keyboardInput = KeyboardInput::Instance();
}

GamePawn::~GamePawn()
{
}

void GamePawn::render()
{
	GameActor::render();
}

void GamePawn::update()
{
	GamePawn::render();
}

void GamePawn::deleteGameObjet()
{
	GameActor::deleteGameObject();
}

void GamePawn::setTileActual(Tile* _tileNuevo)
{
}
