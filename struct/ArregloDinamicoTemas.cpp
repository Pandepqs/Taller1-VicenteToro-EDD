//
// Created by Vicente on 04-10-2026.
//

#include "../include/struct/ArregloDinamicoTemas.h"

#include <iostream>
using namespace std;

ArregloDinamicoTemas::ArregloDinamicoTemas() {

    this->capacidad = 4;
    this->nroTemas = 0;

    this->temas = (Tema**) malloc(capacidad * sizeof(Tema*));
}

ArregloDinamicoTemas::~ArregloDinamicoTemas() {
    for(int i = 0; i < this->nroTemas; i++) {
        delete this->temas[i];
    }
    free(this->temas);
    this->temas = nullptr;
}

Tema* ArregloDinamicoTemas::getTemaIndice(int indice) {
    if (indice <= this->nroTemas) {
        return this->temas[indice];
    }
    return nullptr;
}

Tema* ArregloDinamicoTemas::getTemaID(string idTema) {
    for (int i = 0; i < this->nroTemas; i++) {
        if (this->temas[i]->getIdTema() == idTema && this->temas[i] != nullptr) {
            return this->temas[i];
        }
    }
    return nullptr;
}

void ArregloDinamicoTemas::aumentar() {
    this->capacidad += 3;
    Tema** aux = (Tema**) realloc(this->temas,this->capacidad * sizeof(Tema*));

    if (aux != nullptr) {
        this->temas = aux;
    }
}


int ArregloDinamicoTemas::getCapacidad() {
    return this->capacidad;
}

int ArregloDinamicoTemas::getNroTemas() {
    return this->nroTemas;
}

bool ArregloDinamicoTemas::agregarTema(Tema* tema) {
    if (tema == nullptr) {
        return false;
    }
    if (this->nroTemas == this->capacidad) {
        this->aumentar();
    }

    for (int i = this->nroTemas; i > 0; i--) {
        this->temas[i] = this->temas[i - 1];
    }
    this->temas[0] = tema;
    this->nroTemas++;

    return true;
}

bool ArregloDinamicoTemas::eliminarTema(string idTema) {
    if (this->verificarTema(idTema) == false) {
        return false;
    }
    for (int i = 0; i < this->nroTemas; i++) {
        if (this->temas[i]->getIdTema() == idTema) {
            delete this->temas[i];

            for (int j = i; j < this->nroTemas - 1; j++) {
                this->temas[j] = this->temas[j + 1];
            }

            this->nroTemas--;
            this->temas[this->nroTemas] = nullptr;

            return true;
        }
    }
    return false;
}

bool ArregloDinamicoTemas::verificarTema(string idTema) {
    for (int i = 0; i < this->nroTemas; i++) {
        if (this->temas[i]->getIdTema() == idTema && this->temas[i] != nullptr) {
            return true;
        }
    }
    return false;
}

void ArregloDinamicoTemas::mostrarTemas() {
    for (int i = 0; i < this->nroTemas; i++) {
        cout << this->temas[i]->getIdTema() << " + " << this->temas[i]->getTitulo() << endl;
    }
}
