#ifndef PARSEO_H
#define PARSEO_H

#include "tipos.h"

void cargarAEquipos(unordered_map<int, Equipo>& equipos, int eq1, int eq2, int g1, int g2, int& idxeq);

void levantarDatos(int cantPartidos, vector<Partido>& partidos, unordered_map<int, Equipo>& equipos);

void inicializarMatriz(matriz& C, int n);
matriz generarMatrizColley(vector<Partido>& partidos, vector<Equipo>& equipos, matriz& A, matriz& b);

#endif
