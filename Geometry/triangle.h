class Triangulo
{
private: 
    float lado_a, lado_b, lado_c;
public: 
    Triangulo();
    Triangulo(float, float, float);
    float getArea();
    float getPerimeter();
    float getMediana(float, float, float);
};