#include "triangulo.h"

//CONSTRUCTORES TRIANGULO

Triangulo::Triangulo(): base(0.0), altura(0.0) {}

Triangulo::Triangulo(float base, float altura): base(base),
    altura(altura) {}

//METODOS TRIANGULO

void Triangulo::calcularArea()
{
    this->area = (base * altura) / 2;
}

void Triangulo::calcularPerimetro()
{
    float temp = this->base / 2;
    /*Nota: la siguiente fórmula no es válida para hallar el perímetro, 
    pues con solo los atributos de esta clase, no es posible calcularlo. 
    La única forma es asumiendo que el tríangulo es equilatero*/
    //this->perimetro = 2 * ((sqrt((temp * temp)) + (altura * altura))) + base;
    this->perimetro = 3 * base;
}

void Triangulo::mostrarFigura()
{
    cout << "Triangulo\nBase: " << this->base << std::endl;
    cout << "Altura: " << this->altura << std::endl;
    if(this->area == 0.0) calcularArea();
    if(this->perimetro == 0.0) calcularPerimetro();

    cout << "Area: " << this->area << std::endl;
    cout << "Perimetro: " << this->perimetro << std::endl;
    FiguraGeometrica::mostrarFigura();
}