//
// Created by Vicente on 04-10-2026.
//

#include "../include/model/Tema.h"
#include "../include/struct/ListaEnlazadaSimple.h"
using namespace std;


Tema::Tema(string idTema, string Titulo, string Contenido, string idUsuario) {
    this->idTema = idTema;
    this->Titulo = Titulo;
    this->Contenido = Contenido;
    this->idUsuario = idUsuario;

    this->respuestas = new ListaEnlazadaSimple();
}

Tema::~Tema() {
    delete respuestas;
}

string Tema::getIdTema() {
    return this->idTema;
}

string Tema::getTitulo() {
    return this->Titulo;
}

string Tema::getContenido() {
    return this->Contenido;
}

string Tema::getIdUsuario() {
    return this->idUsuario;
}

void Tema::actualizarTema(Nodo* nuevaRespuesta) {
    respuestas->actualizarLista(nuevaRespuesta);
}

int Tema::getNroRespuestas() {
    return respuestas->getNroRespuestas();
}
