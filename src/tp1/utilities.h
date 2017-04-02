#ifndef UTILITIES_H
#define UTILITIES_H

#include "tipos.h"

void show_matrix(string name, const matriz &A);
void show_vector_partidos(const vector<Partido>& partidos);
void show_map_equipos(const unordered_map<int, Equipo>& equipos);

#endif