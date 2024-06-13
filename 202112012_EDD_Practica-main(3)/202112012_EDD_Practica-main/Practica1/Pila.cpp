#include "Pila.h"

Pila::Pila() : tope(nullptr) {}

void Pila::apilar(const std::string& datos) {
    NodoPila* nuevoNodo = new NodoPila(datos);
    if (!tope) {
        tope = nuevoNodo;
    } else {
        nuevoNodo->siguiente = tope;
        tope = nuevoNodo;
    }
}

std::string Pila::desapilar() {
    if (!tope) {
        return ""; // Pila vacía
    }

    NodoPila* nodoEliminar = tope;
    std::string datos = nodoEliminar->datos;
    tope = tope->siguiente;
    delete nodoEliminar;
    return datos;
}

bool Pila::estaVacia() const {
    return tope == nullptr;
}
