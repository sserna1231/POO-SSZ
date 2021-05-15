#include "guessnum.h"

GuessNum::GuessNum() {}

GuessNum::GuessNum(string name): Juego(name) {}

float GuessNum::calcularResultado(float gonzosApostar)
{
    if(numPlayer == numRandom) return 2.0 * gonzosApostar;
    return 0.0;
}

float GuessNum::jugar(float gonzosApostar)
{
    srand(time(NULL));
    numRandom = minrange + rand() % (maxrange + 1);
    int t = 1;
    bool win = false;
    do{
        cout << "Ingrese el numero: ";
        cin >> numPlayer;
        if( numPlayer < numRandom )
            cout << "Un poco mas arriba\n";
        if( numPlayer > numRandom )
            cout << "Un poco mas abajo\n";
        if( numPlayer == numRandom ){
            cout << "Le atinaste!\n";
            win = true;
        }
        ++t;
    }while( t <= tries && win == false );
    cout << "El numero es: " << numRandom << endl;

    float gonzosResultado = calcularResultado(gonzosApostar);
    return gonzosResultado;
}

GuessNum::~GuessNum() {}