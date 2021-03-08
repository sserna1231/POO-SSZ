#include <iostream>
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

constexpr int SIZE = 3;

/*Valida el tamanio de arreglos para evitar accesos
ilegales en memoria o seg. faults*/
bool validateMemory(int tam)
{
    if(tam + 1 > SIZE) 
        throw std::out_of_range("Capacidad de arreglo excedida\n");
    return true;
}

int main()
{
    Circulo circles[SIZE];
    Rectangulo rects[SIZE];
    Triangulo triangles[SIZE];
    int c_pos = 0, r_pos = 0, t_pos = 0; //registros en arreglos

    char opc;

    do{
        std::cout << "Inserte la opcion correspondiente:\n1. Circulo\n";
        std::cout << "2. Rectangulo\n3. Triangulo\n\n";
        std::cout << "Cualquier tecla para salir.\n> ";
        std::cin >> opc;

        switch(opc){
            case '1':
                float radio;
                std::cout << "Inserte el radio: ";
                std::cin >> radio;
                /*Declarar objetos o variables en switch no es buena
                práctica, dado que los cases no están diseñados para
                soportar una declaración en estos. Los scopes petan y
                se generan errores de compilación
                Circulo nuevo(radio);*/
                try{
                    if(validateMemory(c_pos))
                        circles[c_pos++] = Circulo(radio);
                }
                catch(const std::exception &e){
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            case '2':
                float largo, ancho;
                std::cout << "Inserte el largo y ancho [en orden]: ";
                std::cin >> largo >> ancho;
                //Rectangulo nuevo(largo, ancho);
                try{
                    if(validateMemory(r_pos))
                        rects[r_pos++] = Rectangulo(largo, ancho);
                }
                catch(const std::exception &e){
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            case '3':
                float a, b, c;
                //Figura demostrativo de input

                std::cout << "      /\\" << std::endl;
                std::cout << " a-> /  \\ <-b" << std::endl;
                std::cout << "    /    \\" << std::endl;
                std::cout << "   /------\\" << std::endl;
                std::cout << "      c\n\n";

                std::cout << "Digite los valores en orden [ver Fig.]: ";
                std::cin >> a >> b >> c;
                try{
                    if(validateMemory(t_pos))
                        triangles[t_pos++] = Triangulo(a, b, c);
                }
                catch(const std::exception &e){
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            default:
                std::cout << "Saliendo...\n";
                opc = 's'; //s de salir :v
        }
    } while(opc != 's');
    
    return 0;
}