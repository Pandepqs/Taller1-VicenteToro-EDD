//
// Created by Vicente on 03-10-2026.
//

#ifndef TALLER1_VICENTETORO_EDD_LISTAENLAZADASIMPLE_H
#define TALLER1_VICENTETORO_EDD_LISTAENLAZADASIMPLE_H

#include "../struct/Nodo.h"

class ListaEnlazadaSimple {

private:
    Nodo* cabeza;

public:
    ListaEnlazadaSimple();
    ~ListaEnlazadaSimple();

    bool estaVacio();
    void actualizarLista(Nodo* nodo);
    int getNroRespuestas();
    void recorrerLista();
};


#endif //TALLER1_VICENTETORO_EDD_LISTAENLAZADASIMPLE_H
