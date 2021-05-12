//
// Created by lufe0 on 7/05/2021.
//

#include "Casino.h"

// Constructor que inicializa las ganancias y perdidas en cero
Casino::Casino() {}

void Casino::agregarJuego(Juego * juego) {
    juegosDisponibles.push_back(juego);
}

void Casino::agregarJugador(Jugador *pJugador) {
    // Se agrega el jugador al mapa de jugadores del casino
    jugadoresMap.emplace(pJugador->getId(), pJugador);
}

bool Casino::verExisteJugador(long id) {
    // Si el jugador se encuentra en el mapa retorna true, de lo contrario retorna false
    if( jugadoresMap.count(id) ) return true;
    else return false;
}

Jugador* Casino::consultarJugador(long id) {
    if(verExisteJugador(id) == false)
        throw std::domain_error("El jugador con la identificacion recibida NO existe\n");
    return jugadoresMap[id]; // Retorna el apuntador a jugador.
}

double Casino::convertirPesosAGonzos(double dinero) {
    return dinero / gonzos2dinero;
}

vector<Juego*>& Casino::consultarJuegos() {
    return juegosDisponibles;
}

void Casino::retirarJugador(long id) {
    jugadoresMap.erase( id );
}

double Casino::convertirGonzosPesos(float gonzos) {
    return gonzos2dinero * gonzos;
}

Casino::~Casino() {}