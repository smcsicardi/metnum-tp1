#include <chrono>
#include "lib/tipos.h"
#include "lib/parseo.h"
#include "lib/utilities.h"
#include "lib/eg.h"
#include "lib/cl.h"
#include "lib/wp.h"

#define TIEMPO chrono::high_resolution_clock::now
#define MEDICIONES 1000
#define REPETICIONES 1000

int main(int argv, char* argc[]){

    int cantEquipos;
    int cantPartidos;
    cin >> cantEquipos;
    cin >> cantPartidos;

    vector<Partido> partidos;
    unordered_map<int, Equipo> equipos;

    levantarDatos(cantPartidos, partidos, equipos);


    // Ax = b
    matriz A;
    matriz b;
    matriz x;
    // A = (L') * (L)^t
    matriz L1; //ti
    matriz L2; //ts
    matriz y;

    auto inicio = TIEMPO();
    for (int i = 0; i < REPETICIONES; ++i)
    {
        generarMatrizACMM(partidos, equipos, A);
        generarMatrizbCMM(equipos, b);
        x = gaussian_elim(A, b);
    }

    auto fin = TIEMPO();
    double t = (double) chrono::duration_cast<std::chrono::nanoseconds>(fin-inicio).count();

    cout << t/REPETICIONES << endl;

    return 0;
}
