#ifndef MAZOPRINCIPAL_H
#define MAZOPRINCIPAL_H
#include <iostream>
using namespace std;
#include "carta.h"
#include "nodo.h"

class MazoPrincipal
{
public:
    int cont;
    Nodo *inicio;

    bool insertar(int pos, Nodo *nodo);
    Nodo* fin();
    Nodo* siguiente(int pos);
    Nodo* recuperar(int pos);
    bool eliminar(int pos);
    bool mover(int to, int from);
    void imprimir();
    void generarCartas();
    MazoPrincipal();
};

#endif // MAZOPRINCIPAL_H