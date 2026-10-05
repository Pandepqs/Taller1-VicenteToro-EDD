//
// Created by Vicente on 26-09-2026.
//

#include "../include/model/Respuesta.h"
using namespace std;

Respuesta::Respuesta(string usuario,string id,string contenido) {
    this->usuario = usuario;
    this->id = id;
    this->contenido = contenido;
}

string Respuesta::getUsuario() {
    return this->usuario;
}
string Respuesta::getId() {
    return this->id;
}
string Respuesta::getContenido() {
    return this->contenido;
}
