#include "lib/tipos.h"
#include "lib/parseo.h"
#include "lib/utilities.h"
#include "lib/eg.h"
#include "lib/cl.h"
#include "lib/wp.h"
#include "lib/score.h"


int main(int argv, char* argc[]){
    int metodo = atoi(argc[1]);

    if(metodo < 0 || metodo > 3){
        return 0;
    }

    int cantEquipos;
    int cantPartidos;
    cin >> cantEquipos;
    cin >> cantPartidos;

    if(cantEquipos <= 0 || cantPartidos <= 0){
        cout << endl << "No pueden ser negativos la cantidad de equipos ni la cantidad de partidos." << endl;
        return 1;
    }

    vector<Partido> partidos;
    map<int, Equipo> equipos;

    levantarDatos(cantPartidos, partidos, equipos);

    if(equipos.size() != cantEquipos){
        cout << endl << "La cantidad de equipos que juegan partidos es distinta al numero que se paso de cantidad de los mismos." << endl;
        return 1;
    }


    // Imprimo el vector partidos
    // show_vector_partidos(partidos);
    // show_map_equipos(equipos);

    // Ax = b
    matriz A (cantEquipos, vector<double> (cantEquipos, 0));
    matriz b (cantEquipos, vector<double> (1, 0));
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

    } else if (metodo == SCORE) {
        generarVectorScore(equipos, x);
    }

    show_result(equipos, x);

    return 0;
}
