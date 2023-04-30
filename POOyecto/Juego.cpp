#include "Juego.h"

// Funciones Est�ticas


// Funciones Inicializadoras

void Juego::iniciarVentana()
{
    // Cargando el archivo de configuraci�n ventana
    std::ifstream ifs("Config/window.ini");

    // Configuraciones por default
    std::string tituloVentana = "POOyecto";
    sf::VideoMode tamanioVentana(800, 600);
    unsigned limiteFrames = 120;
    bool vSyncActivado = false;

    if (ifs.is_open()) // Si el archivo config est� abierto, 
    {
        // Leer cada una de las configuraciones guardadas
        std::getline(ifs, tituloVentana);
        ifs >> tamanioVentana.width >> tamanioVentana.height;
        ifs >> limiteFrames;
        ifs >> vSyncActivado;
    }

    ifs.close(); // Cerrar el archivo

    // Cargar la ventana con las configuraciones
	this->ventana = new sf::RenderWindow(tamanioVentana, tituloVentana);
    this->ventana->setFramerateLimit(limiteFrames); 
    this->ventana->setVerticalSyncEnabled(vSyncActivado);
}


// Constructores y Destructores

Juego::Juego()
{
    this->iniciarVentana();
}

Juego::~Juego()
{
	// Eliminar punteros para que no RIPee la memoria
	delete this->ventana; 

}


// Funciones

void Juego::actualizarDt()
{
    // Actualizar dt con el tiempo que tom� para actualizar y renderizar un frame
    this->dt = this->dtClock.restart().asSeconds();
}

void Juego::actualizarEventosSFML()
{
    while (this->ventana->pollEvent(this->evento)) // Revisar si Evento est� siendo 'usado'
    {
        if (this->evento.type == sf::Event::Closed) // Si evento est� cerrado, 
            this->ventana->close(); // cerrar ventana tambi�n
    }
}

void Juego::actualizar()
{
    this->actualizarEventosSFML();
}

void Juego::renderizar()
{
    this->ventana->clear();

    // Renderizar Items

    this->ventana->display();
}

void Juego::ejecutar()
{
    while (this->ventana->isOpen()) // Mientras ventana est� abierta
    {
        this->actualizarDt();
		this->actualizar();
		this->renderizar();
    }
}
