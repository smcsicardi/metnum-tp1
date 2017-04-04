#include "tipos.h"
#include "parseo.h"
#include "utilities.h"
#include "eg.h"
#include "cl.h"
#include "wp.h"


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
    // show_vector_partidos(partidos);
    // show_map_equipos(equipos);


    // Ax = b
    matriz A;
    matriz b;
    matriz x;
    // A = (L') * (L)^t
    matriz L1; //ti
    matriz L2; //ts

    if(metodo == CMM_EG){
        // Colley con eliminacion gausseana
        generarMatrizACMM(partidos, equipos, A);
        show_matrix("A", A);
        generarMatrizbCMM(equipos, b);
        show_matrix("b", b);

        x = gaussian_elim(A,b);
        show_matrix("x", x);

    } else if (metodo == CMM_CL){
        // Colley con factorizacion de Cholesky
        generarMatrizACMM(partidos, equipos, A);
        show_matrix("A", A);
        generarMatrizbCMM(equipos, b);
        show_matrix("b", b);

        factorizacionDeCholesky(A, L1, L2);
        show_matrix("L1", L1);
        show_matrix("L2", L2);

        return 0;
    
    } else if (metodo == WP) {
        generarVectorWP(equipos, A);
        show_matrix("WP", A);
    }

    return 0;
}
