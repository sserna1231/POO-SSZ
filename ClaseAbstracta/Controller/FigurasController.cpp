#include "../Controller/FigurasController.h"

// Inicializacion constante estatica para elemento compartido
const int FigurasController::MAX_ITEMS = 10;

void FigurasController::agregarRectagulo(const float largo, const float ancho)
{
    if (listaRectangulo.size() < MAX_ITEMS)
    {
        cout << "Agrego rectangulo" << endl;
        Rectangulo *pRectTemp = new Rectangulo(largo, ancho);
        listaRectangulo.push_back(*pRectTemp);
        pListaFiguras.push_back(pRectTemp);
    }
    else
    {
        //FIXME agregar manejo de excepcion
        std::cout << "\nSe sobrepasa el limite\n"
                  << std::endl;
    }
}

void FigurasController::agregarCirculo(float radio)
{
    if (listaCirculo.size() < MAX_ITEMS)
    {
        cout << "Agrego circulo" << endl;
        Circulo *pcirculoTemp = new Circulo(radio);
        listaCirculo.push_back(*pcirculoTemp);
        pListaFiguras.push_back(pcirculoTemp);
    }
    else
    {
        //FIXME agregar manejo de excepcion
        std::cout << "\nSe sobrepasa el limite\n"
                  << std::endl;
    }
}

void FigurasController::agregarTriangulo(float base, float altura)
{
    if(listaTriangulo.size() < MAX_ITEMS){
        Triangulo* pTriangle = new Triangulo(base, altura);
        listaTriangulo.push_back(*pTriangle);
        pListaFiguras.push_back(pTriangle);
    } else{
        cout << "\nError agregando triangulo. Limite excedido\n\n";
    }
}

void FigurasController::agregarCuadrado(float lado)
{
    if(listaCuadrado.size() < MAX_ITEMS){
        Cuadrado* pSquare = new Cuadrado(lado);
        listaCuadrado.push_back(*pSquare);
        pListaFiguras.push_back(pSquare);
    } else{
        cout << "\nError agregando cuadrado. Limite excedido\n\n";
    }
}

void FigurasController::llenarListaTodosDummy()
{
    Circulo *pMiCirculo = new Circulo(10);
    Rectangulo *pMiRectangulo = new Rectangulo(10, 10);
    Rectangulo *pMiRectangulo2 = new Rectangulo(20, 20);
    this->pListaFiguras.push_back(pMiCirculo);
    this->pListaFiguras.push_back(pMiRectangulo);
    this->pListaFiguras.push_back(pMiRectangulo2);
}

list<Rectangulo> &FigurasController::getListaRectangulo()
{
    // Creo la  referencia
    list<Rectangulo> &lista = listaRectangulo;
    return lista;
}

list<Triangulo>& FigurasController::getListaTriangulo()
{
    return this->listaTriangulo;
}

list<Cuadrado>& FigurasController::getListaCuadrado()
{
    return this->listaCuadrado;
}

list<FiguraGeometrica *> &FigurasController::getListaFiguras()
{
    return pListaFiguras;
}

Rectangulo &FigurasController::encontrarMayorAncho()
{
    bool isFirst = true;
    int mayorAncho = 0;
    Rectangulo *pRectanguloMayor = nullptr;
    for (list<Rectangulo>::iterator it = listaRectangulo.begin(); it != listaRectangulo.end(); ++it)
    {
        if (isFirst)
        {
            // Se inicializa el mayor ancho con el primer elemento
            int mayorAncho = listaRectangulo.begin()->getAncho();
            isFirst = false;
            pRectanguloMayor = &(*it); // It es un apuntador, para acceder al rectangulo se tiene que acceder al contenido
        }
        else
        {
            if (it->getAncho() > pRectanguloMayor->getAncho())
            {
                // Actaulizar el mayor
                pRectanguloMayor = &(*it);
            }
        }
    }
    // Se obtien el contenido del apuntador para luego retorar la referencia
    // a fin de facilitar el manejo de los objetos posteriormente
    return *pRectanguloMayor;
}