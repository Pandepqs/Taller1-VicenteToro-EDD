//
// Created by Vicente on 03-10-2026.
//

#ifndef TALLER1_VICENTETORO_EDD_ARREGLODINAMICOUSER_H
#define TALLER1_VICENTETORO_EDD_ARREGLODINAMICOUSER_H

#include "../model/Usuario.h"
#include <string>

class ArregloDinamicoUser {

private:
    Usuario** usuarios;

    int capacidad;
    int nroUsuarios;
    int nroExpansiones;

    void aumentar();

public:

    ArregloDinamicoUser();
    ~ArregloDinamicoUser();

    Usuario* getUsuarioIndice(int indice);
    Usuario* getUsuarioID(std::string idUsuario);
    int getCapacidad();
    int getNroUsuarios();
    int getNumeroExpansiones();

    bool agregarUsuario(Usuario* usuario);
    bool eliminarUsuario(std::string idUsuario);
    bool verificarUsuario(std::string idUsuario);

    void mostrarUsuarios();

};


#endif //TALLER1_VICENTETORO_EDD_ARREGLODINAMICOUSER_H
