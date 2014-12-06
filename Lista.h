#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "Nodo.h"
using namespace std;
//trabajo hecho en grupo con Maynor Morales, kevin Lanza e Iveth Sabillon

template <typename Tipo>
class Lista
{
public:
    Nodo<Tipo>* inicio;

    Lista()
    {
        inicio = NULL;
    }

    void imprimir()
    {
        for(Nodo<Tipo>* temp = inicio;
            temp!=NULL;
            temp = temp->sig)
        {
            cout<<temp->num<<endl;
        }
    }

    void agregarAlInicio(Tipo valor_nuevo)
    {
        Nodo<Tipo> *nuevo = new Nodo<Tipo>(valor_nuevo);

        if(inicio == NULL)
        {
            inicio = nuevo;
        }else
        {
            nuevo->sig = inicio;
            inicio = nuevo;
        }
    }

    void agregarAlFinal(Tipo valor_nuevo)
    {
        Nodo<Tipo> *nuevo = new Nodo<Tipo>(valor_nuevo);

        if(inicio == NULL)
        {
            inicio = nuevo;
        }else
        {
            Nodo<Tipo>*temp = inicio;
            while(temp->sig!=NULL)
            {
                temp=temp->sig;
            }
            temp->sig = nuevo;
        }
    }

    void borrar(Tipo valor_a_borrar)
    {
        if(inicio->num == valor_a_borrar)
        {
            Nodo<Tipo>* borrar = inicio;
            inicio = inicio->sig;
            delete borrar;
        }else
        {
            Nodo<Tipo>* temp = inicio;
            while(temp->sig->num!=valor_a_borrar)
            {
                temp=temp->sig;
                if(temp->sig==NULL)
                    return;
            }
            Nodo<Tipo>* borrar = temp->sig;
            temp->sig = temp->sig->sig;
            delete temp->sig;
        }
    }

    //Devuelve true si la lista esta vacia, de lo contrario devuelve false
    bool estaVacia()
    {
        if(inicio==NULL)//evalua si el inicio de la lista es null
        return true ;//si la condicion se cumple devulve true sino
        else
        return false;//devuelve false
    }

    //Devuelve el valor almacenado en el primer nodo de la lista
    Tipo obtenerPrimerValor()
    {
        return inicio->valor;//devuelve el valor del inicio de la lista


    }

    //Devuelve el valor almacenado en el ultimo nodo de la lista
    Tipo obtenerUltimoValor()
    {
     Nodo<Tipo>*temp=inicio;//se crea un nuevo nodo para evaluar
        while(temp->sig!=NULL)// se inicio el ciclo para recorrer la lista
        {
        temp=temp->sig;// se le asigna a temp el valor del siguiente
        }
    return temp->valor;//devuelve el  valor del ultimo nodo


    }

    //Devuelve el valor mayor almacenado en la lista
    Tipo obtenerMayor()
    {
        Nodo<Tipo>*temp=inicio;//se crea un nuevo nodo
    int mayor=-999;//se inicializa la variable en la que se define cual es el mayor
    while(temp!=NULL)// se recorre la lista
    {
    if(mayor<temp->valor)// se evalua si la variable mayor es menor que el valor del nodo creado
            {
    mayor=temp->valor;//si se cumple igualamos la variable mayor al valor del nodo
        }
      temp=temp->sig;//se asigna el valor del siguiente a el nodo temp
      }

    return mayor;//devuelve la variable mayor
    }

};
#endif // LISTA_H
