#ifndef GUESS_NUM_H
#define GUESS_NUM_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Juego.h"

using std::cout;
using std::cin;
using std::endl;

class GuessNum: public Juego
{
private:
    static constexpr int minrange = 1;
    static constexpr int manrange = 15;
    static constexpr int tries = 3;
    int numRandom, numPlayer;

protected:
    float calcularResultado(float gonzosApostar) override;

public:
    GuessNum();
    GuessNum(string);
    float jugar(float gonzosApostar) override;
    virtual ~GuessNum();
};

#endif