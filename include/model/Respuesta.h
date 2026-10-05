//
// Created by Vicente on 26-09-2026.
//

#ifndef TALLER1_VICENTETORO_EDD_RESPUESTA_H
#define TALLER1_VICENTETORO_EDD_RESPUESTA_H
#include <string>
class Respuesta {

    private:
    std::string usuario;
    std::string id;
    std::string contenido;

    public:
    Respuesta(std::string usuario, std::string id, std::string contenido);

    std::string getUsuario();
    std::string getId();
    std::string getContenido();
};


#endif //TALLER1_VICENTETORO_EDD_RESPUESTA_H
