#ifndef RAND_MATH_H
#define RAND_MATH_H

#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cin;
using std::cout;

class RandMath: public Juego
{
private:
    static constexpr int min = 1;
    static constexpr int max = 6;
    int v1, v2, random, numPlayer;

protected:
    float calcularResultado(float gonzosApostar) override;

public:
    RandMath();
    RandMath(string);
    float jugar(float gonzosApostar) override;
    virtual ~RandMath();
};

#endif