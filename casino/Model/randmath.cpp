#include "randmath"

RandMath::RandMath() {}

RandMath::RandMath(string name): Juego(name) {}

float RandMath::calcularResultado(float gonzosApostar){
    if(numPlayer == random) {
        cout << "Enhorabuena! Ganaste\n";
        return 2.0 * gonzosApostar;
    }
    cout << "Suerte para la proxima\n";
    return 0.0;
}

float RandMath::jugar(float gonzosApostar){
    srand(time(NULL));
    v1 = min + rand() % (max + 1);
    cout << "Aleatorio 1: " << v1 << endl;
    v2 = min + rand() % (max + 1);
    cout << "Aleatorio 2: " << v2 << endl;

    random = 1 + rand() % 3 //Random between 1 and 2
    random == 1 ? random = v1 + v2 : random = v1 * v2;
    cout << "Aleatorio1 * Aleatorio2 = " << v1 * v2 << endl;
    cout << "Aleatorio1 + Aleatorio2 = " << v1 + v2 << endl;
    cout << "\nCual crees que sera el resultado?\n> ";
    cin >> numPlayer;

    float gonzosResultantes = calcularResultado(gonzosApostar);
    return gonzosResultantes;
}

RandMath::~RandMath() {}