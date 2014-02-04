#ifndef CARTA_H
#define CARTA_H
#include <iostream>
using namespace std;

class Carta
{
private:
    char rango;
    char color;
    char palo;
    bool caraAbajo;
    bool usada;
public:
    char getRango();
    char getColor();
    char getPalo();
    bool isCaraAbajo();
    bool isUsada();
    Carta(char rango, char color, char palo);
};

#endif // CARTA_H
