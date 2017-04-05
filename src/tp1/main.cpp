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
        return 1;
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
    matriz y;

    if(metodo == CMM_EG || metodo == CMM_CL){
        // Genero la matriz de Colley
        generarMatrizACMM(partidos, equipos, A);
        show_matrix("A", A);
        generarMatrizbCMM(equipos, b);
        show_matrix("b", b);

        if(metodo == CMM_EG){
            // ELIMINACION GAUSSEANA
            x = gaussian_elim(A,b);
        } else {
            // FACTORIZACION DE CHOLESKY
            factorizacionDeCholesky(A, L1, L2);
            show_matrix("L1", L1);
            show_matrix("L2", L2);

            // Resuelvo L1 * y = b
            y = forward_substitution(L1, b);
            show_matrix("y", y);
            // Resuelvo L2 * x = y
            x = backwards_substitution(L2, y);
        }

    } else if (metodo == WP) {
        generarVectorWP(equipos, x);
    }
    show_result(x);

    return 0;
}
