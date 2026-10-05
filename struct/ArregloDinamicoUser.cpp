//
// Created by Vicente on 03-10-2026.
//

#include "../include/struct/ArregloDinamicoUser.h"
#include <iostream>
using namespace std;


ArregloDinamicoUser::ArregloDinamicoUser() {
    this->capacidad = 4;

    this->nroExpansiones = 0;
    this->nroUsuarios = 0;

    this->usuarios = (Usuario**) malloc(capacidad * sizeof(Usuario*));
}

ArregloDinamicoUser::~ArregloDinamicoUser() {
    for (int i = 0; i < this->nroUsuarios; i++) {
        delete this->usuarios[i];
    }
    free(this->usuarios);
    this->usuarios = nullptr;
}

void ArregloDinamicoUser::aumentar() {
    this->capacidad += 3;
    Usuario** aux = (Usuario**) realloc(this->usuarios,this->capacidad * sizeof(Usuario*));

    if (aux !=nullptr) {
        this->usuarios = aux;
        this->nroExpansiones++;
    }
}

Usuario* ArregloDinamicoUser::getUsuarioIndice(int indice) {
if (indice >= 0 && indice < this->nroUsuarios) {
        return this->usuarios[indice];
    }
    return nullptr;
}


Usuario* ArregloDinamicoUser::getUsuarioID(string idUsuario) {
    for (int i = 0; i < this->nroUsuarios; i++) {
        if (this->usuarios[i] != nullptr && this->usuarios[i]->getIdUsuario() == idUsuario) {
            return this->usuarios[i];
        }
    }
    return nullptr;
}

int ArregloDinamicoUser::getNumeroExpansiones() {
    return this->nroExpansiones;
}

int ArregloDinamicoUser::getNroUsuarios() {
    return this->nroUsuarios;
}

int ArregloDinamicoUser::getCapacidad() {
    return this->capacidad;
}


bool ArregloDinamicoUser::agregarUsuario(Usuario* usuario) {
    if (usuario == nullptr) {
        return false;
    }
    if (this->verificarUsuario(usuario->getIdUsuario()) == true) {
        return false;
    }

    if (this->nroUsuarios == this->capacidad) {
        aumentar();
    }

    this->usuarios[this->nroUsuarios] = usuario;
    this->nroUsuarios++;

    return true;
}

bool ArregloDinamicoUser::eliminarUsuario(string idUsuario) {
    if (this->verificarUsuario(idUsuario) == false) {
        return false;
    }
    for (int i = 0; i < this->nroUsuarios; i++) {
        if (this->usuarios[i]->getIdUsuario() == idUsuario) {
            delete this->usuarios[i];
            for (int j = i; j < this->nroUsuarios - 1; j++) {
                this->usuarios[j] = this->usuarios[j + 1];
            }
        this->nroUsuarios--;
        this->usuarios[this->nroUsuarios] = nullptr;

        return true;
        }
    }
    return false;
}

bool ArregloDinamicoUser::verificarUsuario(string idUsuario) {
    for (int i = 0; i < this->nroUsuarios; i++) {
        if (this->usuarios[i] != nullptr && this->usuarios[i]->getIdUsuario() == idUsuario) {
            return true;
        }
    }
    return false;
}

void ArregloDinamicoUser::mostrarUsuarios() {
    for (int i = 0; i < this->nroUsuarios; i++) {
        cout << this->usuarios[i]->getIdUsuario() << " + " << this->usuarios[i]->getNombre() << endl;
    }
}