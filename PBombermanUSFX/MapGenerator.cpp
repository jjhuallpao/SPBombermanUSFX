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
	Texture* texturaMuroMetal;
	texturaMuroMetal = new Texture();
	Texture* texturaMuroCeramica;
	texturaMuroCeramica = new Texture();
	Texture* texturaSueloCesped;
	texturaSueloCesped = new Texture();
	
	Texture::renderer = renderer;

	texturaBomberman->loadFromImage("resources/bomberman.jpg");
	texturaMuroCeramica->loadFromImage("resources/muro_ceramica.jpg");
	texturaMuroMetal->loadFromImage("resources/muro_metal.jpg");
	texturaSueloCesped->loadFromImage("resources/suelo_cesped.jpg");
	
	int x = 0;
	int y = 0;

	while (getline(file, line)) {
		vector<char> chars(line.begin(), line.end());
		x = 0;

		for (int i = 0; i < chars.size(); i++) {
			GameObject* objetoNuevo = nullptr;

			switch (chars[i]) {
			case '0':
				objetoNuevo = new SueloCesped(texturaSueloCesped);
				break;
			case '1':
				objetoNuevo = new MuroMetal(texturaMuroCeramica);
				break;
			case '2':
				objetoNuevo = new MuroCeramica(texturaMuroMetal);
				break;
			case 'B':
				objetoNuevo = new Bomber(texturaBomberman);
				break;
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

	return false;
}

void MapGenerator::transferirObjetosJuego(vector<GameObject*>& _vectorObjetosJuegoDestino)
{
	for (int i = 0; i < vectorObjectosJuego.size(); i++) {
		_vectorObjetosJuegoDestino.push_back(vectorObjectosJuego[i]);
	}
}
