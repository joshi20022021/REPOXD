// ListaDoblementeEnlazada.cpp

#include "ListaDoblementeEnlazada.h"
#include <iostream>

ListaDoblementeEnlazada::ListaDoblementeEnlazada() : primero(nullptr), ultimo(nullptr) {}

void ListaDoblementeEnlazada::insertarAlFinal(const Pasajero& pasajero) {
    NodoLista* nuevoNodo = new NodoLista(pasajero);
    if (!primero) {
        primero = ultimo = nuevoNodo;
    } else {
        ultimo->siguiente = nuevoNodo;
        nuevoNodo->anterior = ultimo;
        ultimo = nuevoNodo;
    }
}

bool ListaDoblementeEnlazada::estaVacia() const {
    return primero == nullptr;
}

void ListaDoblementeEnlazada::mostrarLista() const {
    NodoLista* actual = primero;
    while (actual) {
        std::cout << "Nombre: " << actual->pasajero.nombre << ", Destino: " << actual->pasajero.destino << std::endl;
        actual = actual->siguiente;
    }
}
