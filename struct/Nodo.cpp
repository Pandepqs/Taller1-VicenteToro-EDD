//
// Created by Vicente on 26-09-2026.
//

#include "../include/struct/Nodo.h"
using namespace std;


Nodo::Nodo(Respuesta* resp) {
    this->sigNodo = nullptr;
    this->respuesta = resp;
}

Nodo::~Nodo() {
    delete respuesta;
}

Respuesta* Nodo::getRespuesta() {
    return this->respuesta;
}

Nodo* Nodo::getSigNodo() {
    return sigNodo;
}

void Nodo::setSigNodo(Nodo* sigNodo) {
    this->sigNodo = sigNodo;
}




