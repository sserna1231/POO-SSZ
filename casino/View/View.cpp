//
// Created by lufe0 on 7/05/2021.
//

#include "View.h"

View::View(){
    controller = Controller();
}

void View::agregarJugador()
{
    string nombreJugador;
    float dineroPesos;
    long idJugador;
    cout << "Ingrese el nombre del jugador \n";
    cin.ignore(100, '\n');
    getline(cin, nombreJugador);
    // Id del jugador
    cout << "Ingrese el id del jugador \n";
    cin >> idJugador;
    // Validacion de los datos del jugador
    do
    {
        cout << "Ingrese el dinero en pesos \n";
        cin >> dineroPesos;
    } while (dineroPesos <= 0);

    // Esta linea de codigo controla la excepcion que lanza el controller y lo muestra en pantalla
    try {
        controller.agregarJugador(idJugador, nombreJugador, dineroPesos);
    } catch (std::domain_error ex) {
        cout << "ERROR: " << ex.what();
    }
}


void View::pedirUsuario(){
    try {
        long idJugador;
        cout << "Ingrese el id del jugador que quiere jugar \n";
        cin >> idJugador;
        controller.verInfoJugador(idJugador);

        // LLama a la función que hacer toda la logica de jugar.
        jugarView(idJugador);

    }catch (std::domain_error ex){
        // Se muestra un error si el usuario no existe
        cout << ex.what();
    }
}

void View:: jugarView(long idJugador) {
    int opcion;
    float cantGonzos;
    int idJuego;
    do{
        try {
            do{
                cout << "Cuantos gonzos desea apostar \n";
                cin >> cantGonzos;
                if( cantGonzos <= 0) cout << "Cantidad invalida\n\n";
                if( !controller.verPuedeContinuar(idJugador, cantGonzos) )
                    throw std::domain_error("No tienes saldo suficiente");
                if( !controller.verPuedeContinuar() )
                    throw std::domain_error("No te queda saldo. Recarga primero");
            } while (cantGonzos <= 0);

            // Agregue el esto de la logica para el juego 1. Juego mayor a 13, 2 juego de dos colores.
            do{
                controller.mostrarJuegos();
                cout << "Digite el numero del juego [Salir -> 0]: ";
                cin >> opcion;
                bool win;
                if( opcion != 0) win = controller.jugar(opcion, idJugador, cantGonzos);
                win ? cout << "Felicidades!!!\n" : cout << "Suerte para la proxima\n";
            } while( opcion != 0);

        } catch (std::domain_error ex){
            cout << "ERROR: " << ex.what();
        }
        catch (std::out_of_range ex){
            cout << "ERROR: " << ex.what();
        }
    }while (opcion!=0);
}

int View::mostrarMenu()
{
    int opcion;
    cout << "Menu\n";
    cout << "1. Agregar jugador " << std::endl;
    cout << "2. Jugar" << std::endl;
    cout << "3. Consultar jugador" << std::endl;
    cout << "4. Eliminar jugador" << std::endl;
    cout << "5. Vender gonzos " << std::endl;
    cout << "0. Salir\n"
         << std::endl;
    cout << "Digita el numero: ";
    cin >> opcion;
    return opcion;
}

void View::verPrincipal()
{
    int opcion;
    do
    {
        opcion = mostrarMenu();
        switch (opcion){
            case 1: 
                agregarJugador();
                break;
            case 2:
                pedirUsuario();
                break;
            case 3:
                mostrarJugador();
                break;
            case 4:
                retirarJugador();
                break;
            case 5:
                recargarGonzos();
                break;
            case 0:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida\n\n";
        }
    } while (opcion != 0);
}

void View::mostrarJugador() {
    long id;
    cout << "Ingrese el id del jugador: ";
    cin >> id;
    try{
        controller.verInfoJugador(id);
    }catch(std::domain_error ex){
        cout << "ERROR: " << ex.what() << endl;
    }
}

void View::retirarJugador() {
    long id;
    cout << "Ingrese el id del jugador a retirar: ";
    cin >> id;
    try{
        controller.retirarJugador(id);
    }catch(std::domain_error ex){
        cout << "ERROR: " << ex.what() << endl;
    }
}

void View::recargarGonzos(){
    long id;
    cout << "Ingrese el id del jugador a recargar saldo: ";
    cin >> id;
    float cash;
    do{
        cout << "Inserte cantidad de efectivo [dinero]: ";
        cin >> cash;
        if(cash <= 0)
            cout << "Cifra invalida. Valor negativo o vacio\n";
    } while(cash <= 0);
    try{
        controller.recargarGonzos(id, cash, true);
    }catch(std::domain_error ex){
        cout << "ERROR: " << ex.what() << endl;
    }
}