#ifndef MAZOPRINCIPAL_H
#define MAZOPRINCIPAL_H
#include <iostream>
using namespace std;
#include "carta.h"

class MazoPrincipal
{
public:
    int cont;

    Carta *cartas[50];

    void generarCartas();
    bool insertar(int pos, Carta *carta);
    Carta* inicio();
    Carta* fin();
    Carta* siguiente(int pos);
    Carta * recuperar(int pos);
    bool eliminar(int pos);
    bool mover(int from, int to);
    void imprimir();

    MazoPrincipal();
};

#endif // MAZOPRINCIPAL_H
