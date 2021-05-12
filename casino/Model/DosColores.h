//
// Created by lufe0 on 8/05/2021.
//

#ifndef CASINO_DOSCOLORES_H
#define CASINO_DOSCOLORES_H

#include "Juego.h"
#include<cstdlib>
#include<ctime>


class DosColores:public Juego {

protected:
    static constexpr int numli = 1;
    static constexpr int numls = 13;
    static constexpr int colorli = 0;
    static constexpr int colorls = 1;
    int colorJugador;
    int colorCasino;
    float calcularResultado(float gonzosApostar) override;

public:
    DosColores();
    DosColores(string);
    float jugar(float gonzosApostar) override;
    virtual ~DosColores();

};


#endif //CASINO_DOSCOLORES_H
