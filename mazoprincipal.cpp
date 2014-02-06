#include "mazoprincipal.h"

void MazoPrincipal::generarCartas()
{
    char rangos[] = {'A','2','3','4','5','6','7','8','9','0','J','Q','K'};

    for(int i=0;i<13;i++)
    {
        Nodo *d=new Nodo(rangos[i],'R','D');
        insertar(i,d);
    }
    for(int i=0;i<13;i++)
    {
        Nodo *t=new Nodo(rangos[i],'N','T');
        insertar(i+13,t);
    }
    for(int i=0;i<13;i++)
    {
        Nodo *e = new Nodo(rangos[i],'N','E');
        insertar(i+26,e);
    }
    for(int i=0;i<13;i++)
    {
        Nodo *c = new Nodo(rangos[i],'R','C');
        insertar(i+39,c);
    }
}

bool MazoPrincipal::insertar(int pos, Nodo *nodo)
{
    if(pos<0  || pos>cont )
            return false;

        if(pos==0)
        {
           Nodo *tem=inicio;
           nodo->siguiente=tem;
           inicio=nodo;
        }
        else
        {
           int i=0;
            Nodo *tem=inicio;
            while(i!=pos-1){
                tem=tem->siguiente;
                i++;
            }
            nodo->siguiente=tem->siguiente;
            tem->siguiente=nodo;
        }
        cont++;
        return true;
}

Nodo *MazoPrincipal::fin()
{
    return recuperar(cont-1);
}

Nodo *MazoPrincipal::siguiente(int pos)
{
    if(pos>=cont-1 || pos<0)
         return NULL;

    return recuperar(pos)->siguiente;
}

Nodo *MazoPrincipal::recuperar(int pos)
{
    if(pos>=cont || pos<0)
           return NULL;
       int i=0;

          Nodo *tem=inicio;
           while(i!=pos){
               tem=tem->siguiente;
               i++;
           }
           return tem;
}

bool MazoPrincipal::eliminar(int pos)
{
    if(pos<0 || pos>=cont)
            return false;
        if(pos==0)
        {
            Nodo *temp=inicio;
            inicio=temp->siguiente;
        }
        else
        {
            Nodo *temp=recuperar(pos);
            if(temp!=NULL)
            {
               Nodo *temp2=recuperar(pos-1);
               temp2->siguiente=temp->siguiente;
            }
        }
        cont--;
        return true;
}

bool MazoPrincipal::mover(int to, int from)
{
    Nodo *temp=recuperar(from);

       if(temp!=NULL)
       {
           if(eliminar(from))
             if(insertar(to,temp))
                return true;
       }

       return false;
}

void MazoPrincipal::imprimir()
{
    cout<<"\nContador: "<<cont<<endl;
      Nodo *tem=inicio;
      for(int i=0;i<cont;i++){
        cout<<tem->carta->isCaraAbajo() ;
        cout<<tem->carta->nombre().toStdString()<<endl;
        tem=tem->siguiente;
      }
}


MazoPrincipal::MazoPrincipal()
{
     this->cont=0;
     inicio=NULL;
}
