#include "GestorPasajeros.h"
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include "ListaDoblementeEnlazada.h"
#include "Pila.h"


using namespace std;
using json = nlohmann::json;

void GestorPasajeros::procesarIngresoPasajero() {
    if (!frente) {
        cout << "No hay pasajeros en la cola." << endl;
        return;
    }

    // Sacar el primer pasajero de la cola
    NodoPasajero* nodoPasajero = frente;
    frente = frente->siguiente;

    // Verificar el equipaje facturado
    Pasajero pasajero = nodoPasajero->pasajero;
    if (pasajero.equipajeFacturado > 0) {
        // Agregar a la pila de equipaje facturado
        string datos = pasajero.nombre + ", " + pasajero.numeroPasaporte + ", " + to_string(pasajero.equipajeFacturado);
        pilaEquipajeMayorCero.apilar(datos);
    } else {
        // Agregar a la lista de pasajeros con equipaje facturado = 0
        listaEquipajeCero.insertarAlFinal(pasajero);
    }

    delete nodoPasajero; // Liberar memoria del nodo sacado de la cola
}

void GestorPasajeros::cargarPasajerosDesdeArchivo(const std::string& rutaArchivo) {
    ifstream file(rutaArchivo);
    if (!file) {
        cout << "Error al abrir el archivo: " << rutaArchivo << endl;
        return;
    }

    json data;
    try {
        file >> data;
    } catch (const json::parse_error& e) {
        cout << "Error al parsear el archivo JSON: " << e.what() << endl;
        return;
    }

    for (const auto& pasajeroData : data) {
        Pasajero pasajero;
        try {
            pasajero.nombre = pasajeroData.at("nombre").get<string>();
            pasajero.nacionalidad = pasajeroData.at("nacionalidad").get<string>();
            pasajero.numeroPasaporte = pasajeroData.at("numero_de_pasaporte").get<string>();
            pasajero.vuelo = pasajeroData.at("vuelo").get<string>();
            pasajero.asiento = pasajeroData.at("asiento").get<string>();
            pasajero.destino = pasajeroData.at("destino").get<string>();
            pasajero.origen = pasajeroData.at("origen").get<string>();
            pasajero.equipajeFacturado = pasajeroData.at("equipaje_facturado").get<int>();

            // Encolar el pasajero
            NodoPasajero* nuevoNodo = new NodoPasajero(pasajero);
            if (!frente) {
                frente = fin = nuevoNodo;
            } else {
                fin->siguiente = nuevoNodo;
                nuevoNodo->anterior = fin;
                fin = nuevoNodo;
            }

        } catch (const json::out_of_range& e) {
            cout << "Error al acceder a los datos del pasajero: " << e.what() << endl;
            continue;
        }
    }

    cout << "Pasajeros cargados a la cola correctamente." << endl;
}

void GestorPasajeros::mostrarColaPasajeros() {
    cout << "Cola de pasajeros:" << endl;
    NodoPasajero* actual = frente;
    int i = 1;
    while (actual) {
        cout << "Pasajero " << i << ": " << actual->pasajero.nombre << " - Destino: " << actual->pasajero.destino << endl;
        actual = actual->siguiente;
        i++;
    }
}
