cmake_minimum_required(VERSION 3.25)
project(Taller1_VicenteToro_EDD)

set(CMAKE_CXX_STANDARD 20)


add_executable(Taller1_VicenteToro_EDD
        main.cpp
        struct/Nodo.cpp
        ../include/struct/Nodo.h
        model/Respuesta.cpp
        ../include/model/Respuesta.h
        struct/ListaEnlazadaSimple.cpp
        ../include/struct/ListaEnlazadaSimple.h
        struct/ArregloDinamicoUser.cpp
        ../include/struct/ArregloDinamicoUser.h
        model/Usuario.cpp
        ../include/model/Usuario.h
        model/Tema.cpp
        ../include/model/Tema.h
        struct/ArregloDinamicoTemas.cpp
        ../include/struct/ArregloDinamicoTemas.h
        service/Sistema.cpp
        include/service/Sistema.h
)
