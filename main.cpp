#include <iostream>
#include <string>

#include "include/model/Respuesta.h"
#include "include/model/Tema.h"
#include "include/model/Usuario.h"
#include "include/struct/ArregloDinamicoTemas.h"
#include "include/struct/ArregloDinamicoUser.h"
#include "include/struct/Nodo.h"
#include "include/struct/ListaEnlazadaSimple.h"
#include "include/service/Estadistica.h"
#include "include/service/Sistema.h"

using namespace std;

int main() {


    Sistema* s = new Sistema();

    s->inicializarSistema();

    s->verificarInicioSesion();

    s->mostrarMenu();

}