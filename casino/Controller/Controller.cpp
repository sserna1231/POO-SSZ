//
// Created by lufe0 on 7/05/2021.
//

#include "Controller.h"
#include "../Model/Mayor13.h"
#include "../Model/DosColores.h"

Controller::Controller() {
    this->casino = Casino();
    // Se agregan los juegos disponibles para el casino
    Mayor13* juego1 = new Mayor13();
    DosColores* juego2 = new DosColores();
    GuessNum* juego3 = new GuessNum();
    RandMath* juego4 = new RandMath();
    casino.agregarJuego(juego1);
    casino.agregarJuego(juego2);
    casino.agregarJuego(juego3);
    casino.agregarJuego(juego4);
}

void Controller::mostrarJuegos(){
    vector<Juego*> gamePool( casino.consultarJuegos() );
    int i = 1;
    for( auto it = gamePool.begin(); it != gamePool.end(); ++it, ++i)
        cout << i << ". " << (*it)->getName() << endl;
    cout << endl;
}

void Controller::agregarJugador(long id, string nombreJugador, double dinero)
{
    // Se agrega jugador solo si no existe con anticipacion
    if (casino.verExisteJugador(id) == false){
        // Se convierte el dinero a Gonzos
        //float cantGonzos = casino.convertirPesosAGonzos(dinero);
        Jugador* pJugador = new Jugador(id, nombreJugador, 0.0);
        casino.agregarJugador(pJugador);
        recargarGonzos( id, casino.convertirPesosAGonzos(dinero) );
    }else {
        throw std::domain_error("El jugador con la identificacion recibida ya existe\n");
    }
}

bool Controller::jugar(int idJuego, long idJugador, float gonzosApostar) {
    if (casino.verExisteJugador(idJugador) == false){
        throw std::domain_error("El jugador con la identificacion recibida NO existe, no es posible jugar\n");
    }
    if (idJuego > casino.consultarJuegos().size()){
        throw std::domain_error("NO existe el juego que desea jugar\n");
    }
    if (verPuedeContinuar(idJugador)== false){
        throw std::domain_error("No tienes saldo suficiente para jugar\n");
    }
    // Si no hay errores se inicia el juego
    int posJuego = idJuego - 1; // Se corrige la posicion para acceder al juego
    Juego* pJuegoAJugar = casino.consultarJuegos().at(idJuego-1);

    // Consulta al jugador, consulta los gonzos iniciales, juega y obtiene el resultado
    Jugador* player = casino.consultarJugador(idJugador);    
    player->mostrarInfo();
    int gonzos2play;
    cout << "Digite la cantidad de gonzos a apostar: ";
    cin >> gonzos2play;
    if ( gonzos2play > player->getCantGonzos() ){
        throw std::domain_error("No tienes saldo suficiente para jugar\n");
    }
    // Actualiza el saldo del jugador con el resultado
    float gonzosBefore = player->getCantGonzos();
    player->actualizarGonzos(-gonzos2play);
    float balanceApuesta = pJuegoAJugar->jugar(gonzos2play);
    player->actualizarGonzos(balanceApuesta);

    // Actualiza la cantidad de juegos jugados
    player->aumentarJuegos();

    // Retorna verdadero si el jugador ganó y false si el jugador perdio
    if( gonzosBefore >= player->getCantGonzos() ) return false;
    else return true;
}

void Controller::verInfoJugador(long idJugador){
    // En teoría esta excepción no debería salir nunca pero se pone como táctica de programación segura.
    if (casino.verExisteJugador(idJugador) == false){
        throw std::domain_error("El jugador con la identificacion recibida NO existe\n");
    }
    Jugador * pJugador = casino.consultarJugador(idJugador);
    pJugador->mostrarInfo();
}

bool Controller::verPuedeContinuar(int idJugador) {
    // En teoría esta excepción no debería salir nunca pero se pone como táctica de programación segura.
    if (casino.verExisteJugador(idJugador) == false) {
        throw std::domain_error("El jugador con la identificacion recibida NO existe");
    }
    Jugador *pJugador = casino.consultarJugador(idJugador);
    if (pJugador->getCantGonzos() == 0) {
        return false;
    }
    return true;
}

void Controller::retirarJugador(long idJugador) {
    if (casino.verExisteJugador(idJugador) == false){
        throw std::domain_error("El jugador con la identificacion recibida NO existe\n");
    }
    try{
        Jugador* player = casino.consultarJugador(idJugador);
    } catch(std::domain_error ex){
        cout << "ERROR: " << ex.what() << endl;
        throw std::domain_error("Eliminacion fallida\n");
    }
    pJugador->mostrarInfo();
    casino.retirarJugador(idJugador);
}

void Controller::recargarGonzos(long idJugador, float cash) {
    try{
        Jugador* player = casino.consultarJugador(idJugador);
    } catch(std::domain_error ex){
        cout << "ERROR: " << ex.what() << endl;
        throw std::domain_error("Recarga fallida\n");
    }
    player->actualizarGonzos( casino.convertirPesosAGonzos(cash) );
}

void Controller::recargarGonzos(long idJugador, float cash, bool bonus)
{
    srand(time(NULL));
    int random = numli + rand() % (numls + 1);
    try{
        Jugador* player = casino.consultarJugador(idJugador);
    } catch(std::domain_error ex){
        cout << "ERROR: " << ex.what() << endl;
        throw std::domain_error("Recarga fallida\n");
    }
    if( random > win_limit )
        player->actualizarGonzos( casino.convertirPesosAGonzos(2.0*cash) );
    else 
        player->actualizarGonzos( casino.convertirPesosAGonzos(cash) );
}

Controller::~Controller(){
    delete(&casino.consultarJuegos());
}