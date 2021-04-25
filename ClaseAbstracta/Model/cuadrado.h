#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include "FiguraGeometrica.h"
using std::cin;

class Cuadrado : public FiguraGeometrica
{
private:
    float lado;

public:
    Cuadrado();
    Cuadrado(float);
    virtual void calcularArea() override;
    virtual void calcularPerimetro() override;
    virtual void mostrarFigura() override;
    float getArea() const;
    float getPerimeter() const;
    void setSide(float);
};

#endif