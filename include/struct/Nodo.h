//
// Created by Vicente on 26-09-2026.
//

#ifndef TALLER1_VICENTETORO_EDD_NODO_H
#define TALLER1_VICENTETORO_EDD_NODO_H

#include "../model/Respuesta.h"

class Nodo {
private:
    Respuesta* respuesta;
    Nodo* sigNodo;

public:

    Nodo(Respuesta* resp);
    ~Nodo();
    Respuesta* getRespuesta();

    Nodo* getSigNodo();
    void setSigNodo(Nodo* sigNodo);
};


#endif //TALLER1_VICENTETORO_EDD_NODO_H
