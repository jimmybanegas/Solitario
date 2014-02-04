#ifndef NODO_H
#define NODO_H
#include "carta.h"

class Nodo
{
public:
    Carta *carta;
    Nodo *siguiente;
    Nodo(char rango, char color, char palo);
};

#endif // NODO_H
