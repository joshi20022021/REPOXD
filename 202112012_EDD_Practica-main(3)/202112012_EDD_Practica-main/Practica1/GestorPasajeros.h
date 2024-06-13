// GestorPasajeros.h

#ifndef GESTOR_PASAJEROS_H
#define GESTOR_PASAJEROS_H

#include <string>
#include "NodoPasajero.h"
#include "ListaDoblementeEnlazada.h" // Asegúrate de incluir ListaDoblementeEnlazada.h aquí
#include "Pila.h"

class GestorPasajeros {
public:
    GestorPasajeros() : frente(nullptr), fin(nullptr), listaEquipajeCero() {}

    void cargarPasajerosDesdeArchivo(const std::string& rutaArchivo);
    void mostrarColaPasajeros();
    void procesarIngresoPasajero();

private:
    NodoPasajero* frente;
    NodoPasajero* fin;
    ListaDoblementeEnlazada listaEquipajeCero; // Ahora el compilador debería reconocer ListaDoblementeEnlazada
    Pila pilaEquipajeMayorCero;
};

#endif // GESTOR_PASAJEROS_H
