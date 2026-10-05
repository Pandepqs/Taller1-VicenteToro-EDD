//
// Created by Vicente on 04-10-2026.
//

#ifndef TALLER1_VICENTETORO_EDD_ESTADISTICA_H
#define TALLER1_VICENTETORO_EDD_ESTADISTICA_H

class ArregloDinamicoUser;
class ArregloDinamicoTemas;

class Estadistica {
private:

    ArregloDinamicoTemas* temasRegistrados;
    ArregloDinamicoUser* usuariosRegistrados;

public:
    Estadistica(ArregloDinamicoTemas* temasRegistrados, ArregloDinamicoUser* usuariosRegistrados);

    void usuarioConMasRespuestas();
    void temaConMasRespuestas();
    void numeroExpansiones();
};


#endif //TALLER1_VICENTETORO_EDD_ESTADISTICA_H
