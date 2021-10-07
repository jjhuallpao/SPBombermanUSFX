#include "MapGenerator.h"

MapGenerator::MapGenerator()
{
	anchoPantalla = 0;
	altoPantalla = 0;
	renderer = nullptr;
}

MapGenerator::MapGenerator(SDL_Renderer* _renderer, int _anchoPantalla, int _altoPantalla):
	anchoPantalla(_anchoPantalla),
	altoPantalla(_altoPantalla),
	renderer(_renderer)
{
	
}

bool MapGenerator::crearObjetosJuego(string _path)
{
	// Crea un flujo de archivo
	fstream file;

	// Abrir el archivo
	file.open(_path.c_str(), ios::in);

	if (file.is_open() == false) {
		std::cout << "No se pudo abrir el archivo de mapa" << std::endl;
		return false;
	}

	string line;
	
	Texture* texturaBomberman;
	texturaBomberman = new Texture();
	Texture* texturaBomberwoman;
	texturaBomberwoman = new Texture();
	Texture* texturaMuroMetal;
	texturaMuroMetal = new Texture();
	Texture* texturaMuroCeramica;
	texturaMuroCeramica = new Texture();
	Texture* texturaSueloCesped;
	texturaSueloCesped = new Texture();
	
	Texture::renderer = renderer;

	texturaBomberman->loadFromImage("resources/bomberman.jpg");
	texturaBomberwoman->loadFromImage("resources/bomberwoman.bmp");
	texturaMuroCeramica->loadFromImage("resources/muro_ceramica.jpg");
	texturaMuroMetal->loadFromImage("resources/muro_metal.jpg");
	texturaSueloCesped->loadFromImage("resources/suelo_cesped.jpg");
	
	int x = 0;
	int y = 0;
	int bombermanPosicionX = -1;
	int bombermanPosicionY = -1;
	int bomberwomanPosicionX = -1;
	int bomberwomanPosicionY = -1;


	while (getline(file, line)) {
		vector<char> chars(line.begin(), line.end());
		x = 0;

		for (int i = 0; i < chars.size(); i++) {
			GameObject* objetoNuevo = nullptr;
			Tile* tileNuevo = tilesGraph->getTileEn(x, y);
			switch (chars[i]) {
			case '0':
				objetoNuevo = new SueloCesped(texturaSueloCesped, tileNuevo);
				if (x > bombermanPosicionX && bombermanPosicionX == -1) {
					bombermanPosicionX = x;
					bombermanPosicionY = y;
				}

				if (x > bomberwomanPosicionX || y > bomberwomanPosicionY) {
					bomberwomanPosicionX = x;
					bomberwomanPosicionY = y;
				}

				break;
			case '1':
				objetoNuevo = new MuroMetal(texturaMuroCeramica, tileNuevo);
				break;
			case '2':
				objetoNuevo = new MuroCeramica(texturaMuroMetal, tileNuevo);
				break;
			/*case 'B':
				objetoNuevo = new Bomberman(texturaBomberman, tileNuevo);
				break;*/
			}

			if (objetoNuevo != nullptr) {
				((GameActor*)objetoNuevo)->setPosicionX(x * 34);
				((GameActor*)objetoNuevo)->setPosicionY(y * 34);
				vectorObjectosJuego.push_back(objetoNuevo);
				x++;
			}
		}
		y++;
	}

	GameObject* objetoBomberman = nullptr;
	Tile* tileNuevo = tilesGraph->getTileEn(bombermanPosicionX, bombermanPosicionY);
	objetoBomberman = new Bomberman(texturaBomberman, tileNuevo);
	if (objetoBomberman != nullptr) {
		((GameActor*)objetoBomberman)->setPosicionX(bombermanPosicionX * 34);
		((GameActor*)objetoBomberman)->setPosicionY(bombermanPosicionY * 34);
		vectorObjectosJuego.push_back(objetoBomberman);
	}

	GameObject* objetoBomberwoman = nullptr;
	tileNuevo = tilesGraph->getTileEn(bomberwomanPosicionX, bomberwomanPosicionY);
	objetoBomberwoman = new Bomberman(texturaBomberwoman, tileNuevo);
	if (objetoBomberwoman != nullptr) {
		((GameActor*)objetoBomberwoman)->setPosicionX(bomberwomanPosicionX * 34);
		((GameActor*)objetoBomberwoman)->setPosicionY(bomberwomanPosicionY * 34);
		vectorObjectosJuego.push_back(objetoBomberwoman);
	}


	return false;
}

void MapGenerator::transferirObjetosJuego(vector<GameObject*>& _vectorObjetosJuegoDestino)
{
	for (int i = 0; i < vectorObjectosJuego.size(); i++) {
		_vectorObjetosJuegoDestino.push_back(vectorObjectosJuego[i]);
	}
}
