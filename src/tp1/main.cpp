#include "tipos.h"
#include "eg.h"
#include "parseo.h"
#include "utilities.h"


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

    levantarDatos(cantPartidos, partidos, equipos);


    // Imprimo el vector partidos
    show_vector_partidos(partidos);
    show_map_equipos(equipos);


    // Ax = b
    matriz A;
    matriz b;

    if(metodo == 0){
        // Colley con eliminacion gausseana
        // generarAMatrizCMM(partidos, equipos, A)
        generarBMatrizCMM(equipos, b);
        show_matrix("b", b);
    }

    return 0;
}

