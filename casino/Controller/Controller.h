//
// Created by lufe0 on 7/05/2021.
//

#ifndef CASINO_CONTROLLER_H
#define CASINO_CONTROLLER_H
#include "../Model/Jugador.h"
#include "../Model/Casino.h"


#include <iostream>
#include <list>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::list;

using std::string;

class Controller
{
private:
    Casino casino;
    static constexpr int numli = 1;
    static constexpr int win_limit = 5;
    static constexpr int numls = 10;

public:
    Controller();
    ~Controller();
    void mostrarJuegos();
    void agregarJugador(long id, string nombreJugador, double dinero);
    bool jugar(int idJuego, long idJugador, float gonzosApostar);
    bool verPuedeContinuar(int idJugador); // True si tiene saldo para jugar, false en caso contrario
    bool verPuedeContinuar(int idJugador, int gonzosApostados); // Verifica si es suficiente el saldo
    void verInfoJugador(long idJugador);
    void retirarJugador(long idJugador);
    void recargarGonzos(long idJugador, float cash);
    void recargarGonzos(long idJugador, float cash, bool bonus);
};
#endif //CASINO_CONTROLLER_H
