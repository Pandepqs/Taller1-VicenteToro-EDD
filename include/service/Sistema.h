#ifndef TALLER1_VICENTETORO_EDD_SISTEMA_H
#define TALLER1_VICENTETORO_EDD_SISTEMA_H

#include <string>

#include "../model/Usuario.h"
#include "../model/Tema.h"
#include "../model/Respuesta.h"
#include "../struct/Nodo.h"
#include "../struct/ArregloDinamicoUser.h"
#include "../struct/ArregloDinamicoTemas.h"


class Sistema {

private:

    ArregloDinamicoUser usuarios;
    ArregloDinamicoTemas temas;

    Usuario* usuarioActual;


    void cargarUsuarios();
    void cargarTemas();

    void guardarUsuarios();
    void guardarTemas();

    void guardarCambios();


public:
    Sistema();
    ~Sistema();

    ArregloDinamicoUser* getUsuarios();
    ArregloDinamicoTemas* getTemas();
    Usuario* setUsuarioActual();
    Usuario* getUsuarioActual();

    void inicializarSistema();
    void verificarInicioSesion();
    void mostrarMenu();
    void ejecutarMenu();
    void revisarTema();
    void comentarTema();
    void publicarTema();
    void mostrarEstadisticas();
    void finalizarSistema();
};


#endif //TALLER1_VICENTETORO_EDD_SISTEMA_H
