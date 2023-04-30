#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

class Estado
{
private:
	std::vector<sf::Texture> textures;
public:
	Estado();
	virtual ~Estado();

	// Las siguientes funciones son 'puramente virtuaes'
	virtual void actualizar() = 0;
	virtual void renderizar() = 0;
	// Significa que sólo se implementarán en las clases hijas de la clase Estado
};

