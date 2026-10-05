//
// Created by Vicente on 03-10-2026.
//

#include "../include/model/Usuario.h"
using namespace std;

Usuario::Usuario(string idUsuario, string nombre) {
    this->idUsuario = idUsuario;
    this->nombre = nombre;
    this->nroRespuestas = 0;
    this->nroTemas = 0;
}

Usuario::~Usuario() {}

string Usuario::getIdUsuario() {
    return this->idUsuario;
}

string Usuario::getNombre() {
    return this->nombre;
}

int Usuario::getNroRespuestas() {
    return this->nroRespuestas;
}

int Usuario::getNroTemas() {
    return this->nroTemas;
}

void Usuario::setNroRespuestas(int nro) {
    this->nroRespuestas = nro;
}

void Usuario::setNroTemas(int nro) {
    this->nroTemas = nro;
}

