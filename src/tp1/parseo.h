#ifndef PARSEO_H
#define PARSEO_H

#include "tipos.h"

void cargarAEquipos(unordered_map<int, Equipo>& equipos, int eq1, int eq2, int g1, int g2, int& idxeq);

void levantarDatos(int cantPartidos, vector<Partido>& partidos, unordered_map<int, Equipo>& equipos);

void inicializarMatrizConCeros(matriz& C, int n, int m);

void generarMatrizbCMM(unordered_map<int, Equipo>& equipos, matriz& b);

void generarMatrizACMM(vector<Partido>& partidos, unordered_map<int, Equipo>& equipos, matriz& A);

#endif
