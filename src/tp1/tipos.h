#ifndef TIPOS_H
#define TIPOS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstdlib>
#include <stdio.h>
#include <ctime>

using namespace std;

#define matriz vector< vector<double> >


struct Partido{

    Partido(){
        this->equipo1 = 0;
        this->goles1 = 0;
        this->equipo2 = 0;
        this->goles2 = 0;
        this->fecha = 0;
    }

    int equipo1;
    int goles1;
    int equipo2;
    int goles2;
    int fecha;
};

struct Equipo{

    Equipo(){
        this->id = 0;
        this->index = 0;
        this->cantJugados = 0;
        this->cantGanados = 0;
        this->cantPerdidos = 0;
        this->cantEmpatados = 0;
    }

    int id;
    int index;
    double cantJugados;
    double cantGanados;
    double cantPerdidos;
    double cantEmpatados;
};

#endif
