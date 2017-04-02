#include "Includes.h"

void cargarAEquipos(vector<Equipo>& equipos, int eq1, int eq2, int g1, int g2);
void levantarDatos(int cantPartidos, vector<Partido>& partidos, unordered_map<int, Equipo>& equipos);
void inicializarMatriz(matriz& C, int n);
matriz generarMatrizColley(vector<Partido>& partidos, vector<Equipo>& equipos, matriz& A, matriz& b);


void levantarDatos(int cantPartidos, vector<Partido>& partidos, unordered_map<int, Equipo>& equipos){
    // OJO, no estoy agregando fecha.
    int param;
    for(int i = 0; i < cantPartidos; i++){
        Partido p;
        cin >> p.equipo1;
        cin >> p.goles1;
        cin >> p.equipo2;
        cin >> p.goles2;
        partidos.push_back(p);

        // Como tengo que hacer lo mismo por cada equipo generé esta funcion que mira al primer equipo
        // pasado por parametro con respecto del segundo
        cargarAEquipos(equipos, p.equipo1, p.equipo2, p.goles1, p.goles2);
        cargarAEquipos(equipos, p.equipo2, p.equipo1, p.goles2, p.goles1);
    }

    return;
}


void cargarAEquipos(vector<Equipo>& equipos, int eq1, int eq2, int g1, int g2){
    // Reviso si estan los equipos, si estan los modifico, sino los agrego.
    vector<Equipo>::iterator it = equipos.begin();

    // Equipo 1
    while(it != equipos.end() && (*it).id != eq1){
        ++it;
    }

    if(it != equipos.end()){
        // El equipo está agregado, le cargo los datos
        (*it).cantJugados++;
        (*it).cantGanados = g1 > g2 ? (*it).cantGanados+1 : (*it).cantGanados;
        (*it).cantPerdidos = g1 < g2 ? (*it).cantPerdidos+1 : (*it).cantPerdidos;
        (*it).cantEmpatados = g1 == g2 ? (*it).cantEmpatados+1 : (*it).cantEmpatados;
    } else {
        // El equipo no está, lo agrego.
        Equipo eq;
        eq.id = eq1;
        eq.cantJugados = 1.0;
        eq.cantGanados = g1 > g2 ? 1.0 : 0.0;
        eq.cantPerdidos = g1 < g2 ? 1.0 : 0.0;
        eq.cantEmpatados = g1 == g2 ? 1.0 : 0.0;
        equipos.push_back(eq);
    }

    return;
}

void inicializarMatriz(matriz& C, int n){
    // inicializa con ceros
    C.resize(n);
    for(int i = 0; i < n; i++){
        C[i].resize(n);
        for(int j = 0; j < n; j++){
            C[i][j] = 0.0;
        }
    }
}

matriz generarMatrizColley(vector<Partido>& partidos, vector<Equipo>& equipos, matriz& A, matriz& b){
    // Las inicializa en el orden que carga los equipos (pueden venir en cualquier orden estos)
    inicializarMatriz(A, equipos.size());
    inicializarMatriz(b, equipos.size());

    // Matriz A


}
