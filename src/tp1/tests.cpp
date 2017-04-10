#include <chrono>
#include <thread>
#include "lib/tipos.h"
#include "lib/parseo.h"
#include "lib/utilities.h"
#include "lib/eg.h"
#include "lib/cl.h"
#include "lib/wp.h"

#define TIEMPO chrono::high_resolution_clock::now

int main(int argv, char* argc[]){
    int reps = atoi(argc[1]);
    int cantEquipos;
    int cantPartidos;
    cin >> cantEquipos;
    cin >> cantPartidos;

    vector<Partido> partidos;
    map<int, Equipo> equipos;

    levantarDatos(cantPartidos, partidos, equipos);


    // Ax = b
    matriz A;
    matriz b;
    matriz x;
    // A = (L') * (L)^t
    matriz L1; //ti
    matriz L2; //ts
    matriz y;

    generarMatrizACMM(partidos, equipos, A);
    generarMatrizbCMM(equipos, b);

    /*** Gaussian Elim ***/
    vector<double> resultados_eg (reps);
    for (int i = 0; i < reps; ++i)
    {
        auto inicio = TIEMPO();
        x = gaussian_elim(A, b);
        auto fin = TIEMPO();
        double t = (double) chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();
        resultados_eg[i] = t;
        this_thread::sleep_for(chrono::milliseconds(2));
    }

    /*** Cholesky ***/
    vector<double> resultados_ch (reps);
    for (int i = 0; i < reps; ++i)
    {
        auto inicio = TIEMPO();
        factorizacionDeCholesky(A, L1, L2);
        y = forward_substitution(L1, b);
        x = backwards_substitution(L2, y);
        auto fin = TIEMPO();
        double t = (double) chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();
        resultados_ch[i] = t;
        this_thread::sleep_for(chrono::milliseconds(2));
    }

    cout << "eg,ch" << endl;
    cout << fixed << setprecision(0);
    for (int i = 0; i < reps; ++i){
        cout << resultados_eg[i] << "," << resultados_ch[i] << endl;
    }

    return 0;
}
