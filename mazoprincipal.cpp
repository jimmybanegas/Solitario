#include "mazoprincipal.h"

void MazoPrincipal::generarCartas()
{
    static char rangos[] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};

    for(int i=0;i<13;i++)
    {
        insertar(i,new Carta(rangos[i],'R','D'));
    }
    for(int i=0;i<13;i++)
    {
        insertar(i+13,new Carta(rangos[i],'N','T'));
    }
    for(int i=0;i<13;i++)
    {
        insertar(i+26,new Carta(rangos[i],'N','E'));
    }
    for(int i=0;i<13;i++)
    {
        insertar(i+39,new Carta(rangos[i],'R','C'));
    }
}

bool MazoPrincipal::insertar(int pos, Carta *carta)
{
    if(pos<0 || pos>51 || pos>cont )
        return false;

    //if(cont>51)
      // return false;

    int i=cont;

    do
    {
      cartas[i]=cartas[i-1];
      i--;
    }while(i>pos);

    cartas[pos]=carta;
    cont++;
    return true;
}

void MazoPrincipal::imprimir()
{
    cout<<"\nContador: "<<cont<<endl;
    if(cont>0)
    {
        for(int i=0;i<cont;i++)
        {
            cout<<"-"<<cartas[i]->getColor()<<" "<<cartas[i]->getPalo()<<endl;
            cout<<"-"<<cartas[i]->getRango()<<" "<<cartas[i]->isCaraAbajo()<<endl;
        }

    }
}



MazoPrincipal::MazoPrincipal()
{
     this->cont=0;
}
