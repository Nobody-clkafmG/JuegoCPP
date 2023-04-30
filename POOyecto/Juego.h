#pragma once

#include "Estado.h"

class Juego {
private:
	// Variables
	sf::RenderWindow *ventana; // Puntero a un 'objeto' Ventana 
	sf::Event evento;

	sf::Clock dtClock;
	float dt; //dt o deltaTime nos ayuda a llevar un conteo del tiempo que toma cada actualización

	// Funciones Inicializadoras
	void iniciarVentana();
public:
	// Constructores y Destructores
	Juego();
	virtual ~Juego();

	// Funciones
	void actualizarDt();
	void actualizarEventosSFML();
	void actualizar();
	void renderizar();
	void ejecutar();

};