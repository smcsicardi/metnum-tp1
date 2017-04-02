#include "tipos.h"
#include "eg.h"
#include "parseo.h"


int main(int argv, char* argc[]){
    int metodo = atoi(argc[1]);

    if(metodo < 0 || metodo > 2){
        return 0;
    }

    int cantEquipos;
    int cantPartidos;
    cin >> cantEquipos;
    cin >> cantPartidos;

    if(cantEquipos <= 0 || cantPartidos <= 0){
        return 0;
    }

    vector<Partido> partidos;
    unordered_map<int, Equipo> equipos;
    partidos.resize(cantPartidos);

    levantarDatos(cantPartidos, partidos, equipos);

    matriz A;
    matriz b;

    if(metodo == 0){
        // Colley con eliminacion gausseana
        // generarMatrizColley(partidos, equipos, A, b);
    }

    return 0;
}

