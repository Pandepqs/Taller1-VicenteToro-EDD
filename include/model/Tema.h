//
// Created by Vicente on 04-10-2026.
//

#ifndef TALLER1_VICENTETORO_EDD_TEMA_H
#define TALLER1_VICENTETORO_EDD_TEMA_H
#include <string>
#include "../struct/ListaEnlazadaSimple.h"

class Tema {
private:

    std::string idTema;
    std::string Titulo;
    std::string Contenido;
    std::string idUsuario;
    int nroRespuestas;

    ListaEnlazadaSimple* respuestas;

public:
    Tema(std::string idTema, std::string Titulo, std::string Contenido, std::string idUsuario);
    ~Tema();

    std::string getIdTema();
    std::string getTitulo();
    std::string getContenido();
    std::string getIdUsuario();
    int getNroRespuestas();

    void actualizarTema(Nodo* nuevaRespuesta);

};

#endif //TALLER1_VICENTETORO_EDD_TEMA_H
