#include <iostream>
#include "rectangle.h"

Rectangulo::Rectangulo()
{
    largo = ancho = 0.0;
}

// Versión favorita :), usa el operador this para diferenciar las
// variables de instancia de las variables locales que tienen el mismo nombre
Rectangulo::Rectangulo(float largo, float ancho)
{
    // Inicializar las varibles de instancia.
    //Todo lo que tenga que inicializar
    this->largo = largo;
    this->ancho = ancho;
}

// Ejemplo de constructor con tres arametros. Busca ilustrar qe puedo tener varios contructores
// si cambio el número de parametros o el tipo de datos entre los parametros
Rectangulo::Rectangulo(float largo, float ancho, float pepito)
{
    // Inicializar las varibles de instancia.
    //Todo lo que tenga que inicializar
    this->largo = largo;
    this->ancho = ancho;
    this->pepito = pepito;
    std::cout << "Entre y me cree" << std::endl
              << "el valor de pepito es " << pepito;
}

// TO-DO pedir los datos al usuario.

void Rectangulo::setLargo(float largo)
{
    this->largo = largo;
}

float Rectangulo::getLargo()
{
    return this->largo;
}

void Rectangulo::calcularPerimetro()
{
    float perimetro; // variable local
    perimetro = (2 * largo) + (2 * ancho);
    pepito++;
    std::cout << "El perimetro es: " << perimetro << std::endl;
}

void Rectangulo::calcularArea()
{
    float area;           // variable local
    area = largo * ancho; // son variables de instancia
    std::cout << "El area es: " << area << std::endl;
}