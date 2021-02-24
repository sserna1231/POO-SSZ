#include <iostream>
#include <cmath>

//Parte A
class Circulo
{
private:   
    float radio, PI;
public: 
    Circulo();
    Circulo(float);
    float getArea(bool = false);
    float getPerimetro(bool = false);
    float getRadio(bool = false);
};

//Parte B
Circulo::Circulo()
{
    radio = 0.0;
    PI = 3.1416;
}

Circulo::Circulo(float radio)
{
    this->radio = radio;
    PI = 3.1416;
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

//Parte C
int main()
{
    Circulo b(2.556);
    Circulo c(4.23);

    b.getArea(true);
    c.getArea(true);

    b.getRadio(true);
    c.getRadio(true);
    return 0;
}