#include <cmath>
#include <iostream>
#include "circle.h"

Circulo::Circulo()
{
    radio = 0.0;
    PI = 3.1416;
}

Circulo::Circulo(float radio)
{
    this->radio = radio;
    this->PI = 3.1416;
}

float Circulo::getArea(bool prompt)
{
    if(prompt)
        std::cout << "Area: " << PI * pow(radio, 2) << std::endl;
    return PI * pow(radio, 2);
}

float Circulo::getPerimetro(bool prompt)
{
    if(prompt)
        std::cout << "Perimetro:" << 2 * PI * radio << std::endl;
    return 2 * PI * radio;
}

float Circulo::getRadio(bool prompt)
{   
    if(prompt)
        std::cout << "Radio:" << radio << std::endl;
    return radio;
}

