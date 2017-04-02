#ifndef PARSEO_H
#define PARSEO_H

#include "Includes.h"

void cargarAEquipos(vector<Equipo>& equipos, int eq1, int eq2, int g1, int g2);
void levantarDatos(int cantPartidos, vector<Partido>& partidos, vector<Equipo>& equipos);
void inicializarMatriz(matriz& C, int n);
matriz generarMatrizColley(vector<Partido>& partidos, vector<Equipo>& equipos, matriz& A, matriz& b);

#endif
