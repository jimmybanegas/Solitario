#ifndef CARTA_H
#define CARTA_H
#include <iostream>
using namespace std;

class Carta
{
private:
    int numero;
    string color;
    string palo;
public:
    int getNumero();
    string getColor();
    string getPalo();
    Carta(int numero, string color, string palo);
};

#endif // CARTA_H
