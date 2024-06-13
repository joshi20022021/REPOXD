//
// Created by joshi2002 on 13/06/24.
//

#ifndef EDDFINAL_PILA_H
#define EDDFINAL_PILA_H

#include <string>

// Clase para la pila
class Pila {
public:
    Pila();

    void apilar(const std::string& datos);
    std::string desapilar();
    bool estaVacia() const;

private:
    struct NodoPila {
        std::string datos;
        NodoPila* siguiente;

        NodoPila(const std::string& d) : datos(d), siguiente(nullptr) {}
    };

    NodoPila* tope;
};

#endif //EDDFINAL_PILA_H
