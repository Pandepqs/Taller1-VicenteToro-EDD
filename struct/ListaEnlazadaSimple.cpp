//
// Created by Vicente on 03-10-2026.
//

#include "../include/struct/ListaEnlazadaSimple.h"

#include <iostream>
using namespace std;

ListaEnlazadaSimple::ListaEnlazadaSimple() {
    cabeza = nullptr;
}

ListaEnlazadaSimple::~ListaEnlazadaSimple() {
    Nodo* aux1 = cabeza;
    while (aux1 != nullptr) {
        Nodo* aux2 = aux1;
        aux1 = aux1->getSigNodo();
        delete aux2; // Esto destruirá el nodo y su respuesta asociada
    }
    cabeza = nullptr;
}

bool ListaEnlazadaSimple::estaVacio() {
    if (cabeza == nullptr) {
        return true;
    }
    return false;
}

void ListaEnlazadaSimple::actualizarLista(Nodo* nodo) {
    Nodo* aux = cabeza;
    if (cabeza == nullptr) {
        cabeza = nodo;
        return;
    }
    while (aux->getSigNodo() != nullptr) {
        aux = aux->getSigNodo();
    }
    aux->setSigNodo(nodo);
}

int ListaEnlazadaSimple::getNroRespuestas() {
    Nodo* aux = cabeza;
    int contador = 0;
    while (aux != nullptr) {
        contador++;
        aux = aux->getSigNodo();
    }
    return contador;
}

void ListaEnlazadaSimple::recorrerLista() {
    Nodo* aux = cabeza;
    if (cabeza == nullptr) {
        return;
    }
    while (aux != nullptr) {
        Respuesta* respuesta = aux->getRespuesta();
        cout << "Usuario " << respuesta->getUsuario() << " responde: " << endl;
        cout << " - " << respuesta->getContenido() << "" <<  endl;
        cout << "- - - - - - - - - - - - - - - - -" << endl;
        aux = aux->getSigNodo();
    }
}