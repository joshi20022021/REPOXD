//
// Created by joshi2002 on 13/06/24.
//

#ifndef EDDFINAL_LISTADOBLEMENTEENLAZADA_H
#define EDDFINAL_LISTADOBLEMENTEENLAZADA_H

#include "GestorPasajeros.h" // Asegúrate de incluir esto si es necesario

// Definición de la estructura de un nodo para la lista doblemente enlazada
struct NodoLista {
    Pasajero pasajero;
    NodoLista* siguiente;
    NodoLista* anterior;

    NodoLista(const Pasajero& p) : pasajero(p), siguiente(nullptr), anterior(nullptr) {}
};

// Clase para la lista doblemente enlazada
class ListaDoblementeEnlazada {
public:
    ListaDoblementeEnlazada();

    void insertarAlFinal(const Pasajero& pasajero);
    bool estaVacia() const;
    void mostrarLista() const;

private:
    NodoLista* primero;
    NodoLista* ultimo;
};

#endif //EDDFINAL_LISTADOBLEMENTEENLAZADA_H
