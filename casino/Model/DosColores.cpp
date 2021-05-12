//
// Created by lufe0 on 8/05/2021.
//

#include "DosColores.h"

DosColores::DosColores() {}

DosColores::DosColores(string name): Juego(name) {}

float DosColores::jugar(float gonzosApostar) {
    srand(time(NULL));
    // para calcular numero aleatorio variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
    do{
        cout << "Digite su numero: ";
        cin >> numeroJugador;
        if(numeroJugador < numli || numeroJugador > numls)
            cout << "Numero invalido. Debe estar en [" << numli << ", " << numls << "]\n";
    } while( numeroJugador < numli || numeroJugador > numls);
    numeroCasino = 1+rand()%(numls+1);// numeros de 1 a 13

    do{
        cout << "Digite su numero: ";
        cin >> colorJugador;
        if(colorJugador < colorli || colorJugador > colorls)
            cout << "Numero invalido. Debe estar en [" << colorli << ", " << colorls << "]\n";
    } while(colorJugador < colorli || colorJugador > colorls);
    colorCasino = rand()%(colorls+1); // Numero entre 0 y 1

    cout << "Tu numero aleatorio es: "<< numeroJugador <<"\n" << "Tu color: " <<colorJugador << "\n";
    cout << "Numero casino: "<< numeroCasino <<"\n" << "Color casino: " <<colorCasino << "\n";
    float gonzosResultado = calcularResultado(gonzosApostar);
    return gonzosResultado;
}

float DosColores::calcularResultado(float gonzosApostar) {
    // Si coincide tanto el valor del dado como el color, el usuario ganará 4 veces lo apostado
    if( numeroJugador == numeroCasino && colorJugador == colorCasino )
        return gonzosApostar * 4.0;
    // coincide sólo con el valor del dado ganará 0.5 veces lo apostado
    if( numeroJugador == numeroCasino ) return gonzosApostar / 2.0;
    // no gana ni pierde
    if( colorJugador == colorCasino ) return gonzosApostar;
    //Pierde todo
    return 0;
}

DosColores::~DosColores() {}
