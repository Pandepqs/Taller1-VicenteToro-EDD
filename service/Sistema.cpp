//
// Created by Vicente on 04-10-2026.
//

#include "../include/service/Sistema.h"

#include "../include/model/Tema.h"
#include "../include/struct/ArregloDinamicoUser.h"
#include "../include/struct/ArregloDinamicoTemas.h"

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


Sistema::Sistema() {
    this->usuarioActual = nullptr;
}

void Sistema::inicializarSistema() {
    ifstream archivoUsuarios("../Archivos/usuarios.csv");
    if (!archivoUsuarios.is_open()) {
        cout << "Error: no se pudo abrir usuarios.csv" << endl;
        return;
    }
    string linea;

    while (getline(archivoUsuarios, linea)) {

        if (linea.empty()) {
            continue;
        }

        stringstream ss(linea);

        string idUsuario;
        string nombre;
        getline(ss, idUsuario, ';');
        std::getline(ss, nombre);

        Usuario* usuario = new Usuario(idUsuario,nombre);


        bool resultado = usuarios.agregarUsuario(usuario);

        if (!resultado) {
            cout << "NO SE AGREGO EL USUARIO" << endl;
            delete usuario;
        }
    }

    ifstream archivoTemas("../Archivos/temas.csv");


    if (!archivoTemas.is_open()) {
        return;
    }
    while (getline(archivoTemas, linea)) {

        if (linea.empty()) {
            continue;
        }

        stringstream ss(linea);

        string idTema;
        string titulo;
        string contenido;
        string idUsuario;
        string respuestas;

        getline(ss, idTema, ';');
        getline(ss, titulo, ';');
        getline(ss, contenido, ';');
        getline(ss, idUsuario, ';');
        getline(ss, respuestas);

        Tema* tema = new Tema(idTema,titulo,contenido,idUsuario);

        if (!respuestas.empty()) {

            stringstream ssRespuestas(respuestas);
            string respuestaTexto;

            while (getline(ssRespuestas, respuestaTexto, ';')) {

                if (respuestaTexto.empty()) {
                    continue;
                }

                stringstream ssRespuesta(respuestaTexto);

                string idRespuesta;
                string idUsuario;
                string contenidoRespuesta;

                getline(ssRespuesta, idRespuesta, '_');
                getline(ssRespuesta, idUsuario, '_');
                getline(ssRespuesta, contenidoRespuesta);

                Respuesta* respuesta = new Respuesta(
                    idRespuesta,
                    idUsuario,
                    contenidoRespuesta
                );

                Nodo* nodo = new Nodo(respuesta);

                tema->actualizarTema(nodo);


                Usuario* usuarioRespuesta = usuarios.getUsuarioID(idUsuario);

                if (usuarioRespuesta != nullptr) {
                    usuarioRespuesta->setNroRespuestas(
                        usuarioRespuesta->getNroRespuestas() + 1
                    );
                }
            }
        }

        if (!temas.agregarTema(tema)) {
            delete tema;
        }
    }
    archivoTemas.close();

    cout << "Sistema inicializado correctamente." << endl;

    cout << "Usuarios cargados: "
         << usuarios.getNroUsuarios() << endl;

    cout << "Temas cargados: "
         << temas.getNroTemas() << endl;
    cout << "1" << endl;
    cout << "2" << endl;
    return;
}

void Sistema::verificarInicioSesion() {


    string idUsuario;

    cout << "\n[---------- Foro Comunitario ----------]" << endl;

    cout << "Ingrese su ID: ";
    cin >> idUsuario;

    while (!usuarios.verificarUsuario(idUsuario)) {

        cout << "El usuario no existe. Intente nuevamente." << endl;
        cout << "Ingrese su ID: ";
        cin >> idUsuario;
    }

    usuarioActual = usuarios.getUsuarioID(idUsuario);

    cout << "Bienvenido/a "
         << usuarioActual->getNombre()
         << endl;
}

void Sistema::mostrarMenu() {

    cout << "\n[---------- Foro Comunitario ----------]" << endl;

    cout << "Temas:" << endl;

    for (int i = 0; i < temas.getNroTemas(); i++) {

        Tema* tema = temas.getTemaIndice(i);

        if (tema != nullptr) {
            cout << tema->getIdTema()
                 << ". "
                 << tema->getTitulo()
                 << endl;
        }
    }

    cout << endl;

    cout << "A) Revisar un tema" << endl;
    cout << "B) Eliminar usuario" << endl;
    cout << "C) Publicar" << endl;
    cout << "D) Estadisticas" << endl;
    cout << "E) Salir" << endl;
}