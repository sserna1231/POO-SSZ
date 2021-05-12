//
// Created by lufe0 on 7/05/2021.
//

#ifndef CASINO_MAYOR13_H
#define CASINO_MAYOR13_H


#include "Juego.h"
#include<cstdlib>
#include<ctime>

class Mayor13 : public Juego {
private:
    static constexpr int numli = 1;
    static constexpr int numls = 13;
    int colorJugador, colorCasino;
protected:
    float calcularResultado(float gonzosApostar) override;
public:
    Mayor13();
    Mayor13(string);
    ~Mayor13() override;
    float jugar(float gonzosApostar) override;

};


#endif //CASINO_MAYOR13_H
