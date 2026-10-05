//
// Created by Vicente on 04-10-2026.
//

#ifndef TALLER1_VICENTETORO_EDD_ARREGLODINAMICOTEMAS_H
#define TALLER1_VICENTETORO_EDD_ARREGLODINAMICOTEMAS_H

#include "../model/Tema.h"

class ArregloDinamicoTemas {

private:

    Tema** temas;

    int capacidad;
    int nroTemas;

    void aumentar();

public:
    ArregloDinamicoTemas();
    ~ArregloDinamicoTemas();

    Tema* getTemaID(std::string idTema);
    Tema* getTemaIndice(int indice);
    int getCapacidad();
    int getNroTemas();

    bool agregarTema(Tema* temaNuevo);
    bool eliminarTema(std::string idTema);
    bool verificarTema(std::string idTema);

    void mostrarTemas();
};


#endif //TALLER1_VICENTETORO_EDD_ARREGLODINAMICOTEMAS_H
