//
// Created by Vicente on 04-10-2026.
//

#include "../include/service/Estadistica.h"
#include "../include/struct/ArregloDinamicoTemas.h"
#include "../include/struct/ArregloDinamicoUser.h"
#include "../include/model/Usuario.h"
#include "../include/model/Tema.h"
#include <iostream>
using namespace std;

Estadistica::Estadistica(ArregloDinamicoUser* arregloUsuarios, ArregloDinamicoTemas* arregloTemas) {
    this->usuariosRegistrados = arregloUsuarios;
    this->temasRegistrados = arregloTemas;
}


void Estadistica::usuarioConMasRespuestas() {
    if (usuariosRegistrados->getNroUsuarios() == 0) {
        cout << "No hay usuarios registrados." <<  endl;
        return;
    }
    int nroRespMax = -1;
    for (int i = 0; i < this->usuariosRegistrados->getNroUsuarios(); i++) {
        Usuario* aux = usuariosRegistrados->getUsuarioIndice(i);
        if(aux != nullptr && aux->getNroRespuestas() > nroRespMax) {
            nroRespMax = aux->getNroRespuestas();
        }
    }
    if (nroRespMax > 0) {
        cout << "Usuario/s con mayor numero de respuestas (" << nroRespMax << ")." << endl;

        for (int i = 0; i < this->usuariosRegistrados->getNroUsuarios(); i++) {
            Usuario* aux = usuariosRegistrados->getUsuarioIndice(i);
            if (aux != nullptr && nroRespMax == aux->getNroRespuestas()) {
                cout << " - " << aux->getNombre() << "." << endl;
            }
        }
    }
    return;
}

void Estadistica::temaConMasRespuestas() {
    if (temasRegistrados->getNroTemas() == 0) {
        cout << "No hay temas registrados en el foro." <<  endl;
        return;
    }
    int nroRespMax = -1;
    for (int i = 0; i < this->temasRegistrados->getNroTemas(); i++) {
        Tema* aux = temasRegistrados->getTemaIndice(i);
        if(aux != nullptr && aux->getNroRespuestas() > nroRespMax) {
            nroRespMax = aux->getNroRespuestas();
        }
    }
    if (nroRespMax > 0) {
        cout << "Tema/s con mayor numero de respuestas (" << nroRespMax << ")." << endl;

        for (int i = 0; i < this->usuariosRegistrados->getNroUsuarios(); i++) {
            Tema* aux = temasRegistrados->getTemaIndice(i);
            if (aux != nullptr && nroRespMax == aux->getNroRespuestas()) {
                cout << " - " << aux->getTitulo() << "." << endl;
            }
        }
    }
    return;
}

void Estadistica::numeroExpansiones() {
    cout << "El numero de expansiones registradas en usuarios es de " << usuariosRegistrados->getNumeroExpansiones() << " expansiones." << endl;
}