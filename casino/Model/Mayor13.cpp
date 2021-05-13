//
// Created by lufe0 on 7/05/2021.
//

#include "Mayor13.h"

Mayor13::Mayor13() {}

Mayor13::Mayor13(string name): Juego(name) {}

float Mayor13::jugar(float gonzosApostar) {
    srand(time(NULL));
    int opc;
    do {
        cout << "Que desea hacer?\n\n1. Rendirse [perderá la mitad de lo apostado]\n";
        cout << "2. Jugar\n\n> ";
        cin >> opc;

        switch (opc) {
            case 1:
                return gonzosApostar / 2.0;
            case 2:
                do {
                    cout << "Digite su numero: ";
                    cin >> numeroJugador;
                    if (numeroJugador < numli || numeroJugador > numls)
                        cout << "Numero invalido. Debe estar en [" << numli << ", " << numls << "]\n";
                } while (numeroJugador < numli || numeroJugador > numls);
                numeroCasino = numli + rand() % (numls + numli);// numeros de 1 a 13

                cout << "Tu numero aleatorio es: " << numeroJugador << "\n" << "Tu color: " << colorJugador << "\n";
                cout << "Numero casino: " << numeroCasino << "\n" << "Color casino: " << colorCasino << "\n";
                break;
            default:
                cout << "Opcion incorrecta\n\n";
        }
    } while( opc < 1 || opc > 2);
    float resultadoJuego = calcularResultado( gonzosApostar );
    return resultadoJuego;
}

float Mayor13::calcularResultado(float gonzosApostar) {
    if( numeroJugador > numeroCasino ) return 2.0 * gonzosApostar;
    return 0;
}

Mayor13::~Mayor13() {}
