    //
// Created by Vicente on 03-10-2026.
//

#ifndef TALLER1_VICENTETORO_EDD_USUARIO_H
#define TALLER1_VICENTETORO_EDD_USUARIO_H

#include <string>
class Usuario {
private:
    std::string idUsuario;
    std::string nombre;

    int nroRespuestas;
    int nroTemas;

public:
    Usuario(std::string idUsuario, std::string nombre);
    ~Usuario();

    std::string getNombre();
    std::string getIdUsuario();
    int getNroRespuestas();
    int getNroTemas();
    void setNroRespuestas(int nroRespuestas);
    void setNroTemas(int nroTemas);
};


#endif //TALLER1_VICENTETORO_EDD_USUARIO_H
