#include "cuadrado.h"

Cuadrado::Cuadrado(): lado(0.0) {}

Cuadrado::Cuadrado(float lado): lado(lado) {}

void Cuadrado::calcularArea()
{
    this->area = lado * lado;
}

void Cuadrado::calcularPerimetro()
{
    this->perimetro = 4 * lado;
}

void Cuadrado::mostrarFigura()
{
    cout << "Cuadrado\nLado: " << this->lado;
    if(this->area == 0.0) calcularArea();
    if(this->perimetro == 0.0) calcularPerimetro();

    cout << "Area: " << this->area << std::endl;
    cout << "Perimetro: " << this->perimetro << std::endl;
    FiguraGeometrica::mostrarFigura();
}

float Cuadrado::getArea() const
{
    return this->area;
}

float Cuadrado::getPerimeter() const
{
    return this->perimetro;
}

void Cuadrado::setSide(float lado)
{
    this->lado = lado;
}