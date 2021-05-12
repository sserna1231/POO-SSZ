//
// Created by lufe0 on 7/05/2021.
//

#include "Jugador.h"

Jugador::Jugador():cantJuegos(0) {}

// Hace llamada delegada al constructor por defecto
Jugador::Jugador(long id, string nombre, float cantGonzos): Jugador(){
    this->id = id;
    this->nombre = nombre;
    this->cantGonzos = cantGonzos;
}


/* Destructor*/
Jugador::~Jugador() {}

void Jugador::mostrarInfo() {
    cout << "Nombre: " << nombre << endl;
    cout << "Saldo gonzos: " << cantGonzos << endl;
    cout << "Juegos participados : " << cantJuegos << endl;
}

void Jugador::aumentarJuegos() {
    ++cantJuegos;
}

void Jugador::actualizarGonzos(float resultadoJuego) {
    cantGonzos += resultadoJuego;
}

string Jugador::getNombre() const {
    return nombre;
}

float Jugador::getCantGonzos() const {
    return cantGonzos;
}

long Jugador::getId() const {
    return id;
}






