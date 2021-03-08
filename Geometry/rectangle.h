class Rectangulo
{
private:
    // Pepito es una variable que estoy usando de ejemplo para demostrar que puedo tener
    // tantas variables como necesite como parte de las varibles de instancia
    float largo, ancho, pepito; // variables de instancia o atributos de instancia

public:
    Rectangulo();
    Rectangulo(float, float); //Constructor
    Rectangulo(float, float, float);
    void calcularPerimetro();
    void calcularArea();
    float getLargo();     // Me permite ver el largo de un rectangulo
    void setLargo(float); // Me permite cambiar el valor del largo.
};