#include <cmath>
#include "triangle.h"

Triangulo::Triangulo()
{
    lado_a = lado_b = lado_c = 0.0;
}

Triangulo::Triangulo(float lado_a, float lado_b, float lado_c)
{
    this->lado_a = lado_a;
    this->lado_b = lado_b;
    this->lado_c = lado_c;
}

float Triangulo::getArea()
{
    return lado_c * getMediana(lado_a, lado_b, lado_c) / 2.0;
}

float Triangulo::getPerimeter()
{
    return lado_a + lado_b + lado_c;
}

float Triangulo::getMediana(float lado_a, float lado_b, float lado_c)
{
    float mediana;
    mediana = sqrt(2 * (pow(lado_a, 2) + pow(lado_b, 2)) - pow(lado_c, 2));
    return mediana;
}