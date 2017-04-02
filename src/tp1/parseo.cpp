#include "tipos.h"
#include "parseo.h"


void levantarDatos(int cantPartidos, vector<Partido>& partidos, unordered_map<int, Equipo>& equipos){
    int idxeq = 0;
    for(int i = 0; i < cantPartidos; i++){
        Partido p;
        cin >> p.fecha;
        cin >> p.equipo1;
        cin >> p.goles1;
        cin >> p.equipo2;
        cin >> p.goles2;
        partidos.push_back(p);

        // Como tengo que hacer lo mismo por cada equipo generé esta funcion que mira al primer equipo
        // pasado por parametro con respecto del segundo
        cargarAEquipos(equipos, p.equipo1, p.equipo2, p.goles1, p.goles2, idxeq);
        cargarAEquipos(equipos, p.equipo2, p.equipo1, p.goles2, p.goles1, idxeq);
    }

    return;
}


void cargarAEquipos(unordered_map<int, Equipo>& equipos, int eq1, int eq2, int g1, int g2, int& idxeq){
    // Reviso si estan los equipos, si estan los modifico, sino los agrego.
    
    auto it = equipos.find(eq1);
    if(it != equipos.end()){
        // El equipo está agregado, le cargo los datos
        (*it).second.jugados++;
        (*it).second.ganados = g1 > g2 ? (*it).second.ganados+1 : (*it).second.ganados;
        (*it).second.perdidos = g1 < g2 ? (*it).second.perdidos+1 : (*it).second.perdidos;
        (*it).second.empatados = g1 == g2 ? (*it).second.empatados+1 : (*it).second.empatados;

    } else {
        // El equipo no está, lo agrego.
        Equipo eq;
        eq.id = eq1;
        eq.index = idxeq;
        idxeq++;
        eq.jugados = 1.0;
        eq.ganados = g1 > g2 ? 1.0 : 0.0;
        eq.perdidos = g1 < g2 ? 1.0 : 0.0;
        eq.empatados = g1 == g2 ? 1.0 : 0.0;

        equipos.insert({eq1, eq});
    }

    return;
}


void inicializarMatriz(matriz& C, int n, int m){
    // inicializa con ceros
    C.resize(n);
    for(int i = 0; i < n; i++){
        C[i].resize(m);
        for(int j = 0; j < n; j++){
            C[i][j] = 0.0;
        }
    }

    return;
}


void generarBMatrizCMM(unordered_map<int, Equipo>& equipos, matriz& b){
    // Las inicializa en el orden que carga los equipos (pueden venir en cualquier orden estos)
    int idx;
    inicializarMatriz(b, equipos.size(), 1);

    // Matriz b
    for(auto it = equipos.begin(); it != equipos.end(); ++it){
        b[it->second.index][0] = 1 + ((it->second.ganados - it->second.perdidos)/2);
    }

}
