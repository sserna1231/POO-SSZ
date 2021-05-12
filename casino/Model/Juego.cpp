//
// Created by lufe0 on 7/05/2021.
//

#include "Juego.h"

Juego::Juego() {}

Juego::Juego(string name): nombreJuego(name) {}

string Juego::getName() const{
    return nombreJuego;
}

Juego::~Juego() {}
