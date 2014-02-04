#ifndef JUEGO_H
#define JUEGO_H
#include "carta.h"
#include "mazoprincipal.h"

class Juego
{
public:
    MazoPrincipal mazo;

    Carta *diamante[13];
    Carta *trebol[13];
    Carta *corazon[13];
    Carta *espada[13];

    Carta *pos1[19];
    Carta *pos2[19];
    Carta *pos3[19];
    Carta *pos4[19];
    Carta *pos5[19];
    Carta *pos6[19];
    Carta *pos7[19];

    Carta *barajeadas[3];

    void crearBaraja();
    void distribuir();
    void barajear();

    Juego();
};

#endif // JUEGO_H
