#include "utilities.h"


void show_matrix(string name, const matriz &A) {
    cout << "Matriz: " << name << endl;
    for (auto i : A) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}


void show_vector_partidos(const vector<Partido>& partidos){
    for(auto it = partidos.begin(); it != partidos.end(); ++it){
        cout << "Fecha: " << it->fecha << endl;
        cout << "Equipo1 id: " << it->equipo1 << "  - Goles Eq1: " << it->goles1 << 
                "  |  Equipo2 id: " << it->equipo2 << "  - Goles Eq2: " << it->goles2 << endl; 
    }
    cout << endl;
}


void show_map_equipos(const unordered_map<int, Equipo>& equipos){
    for(auto it = equipos.begin(); it != equipos.end(); ++it){
        cout << "Key: " << it->first << endl;
        cout << "Value: { " << endl;
        cout << "Id: " << it->second.id << " | " << "Index: " << it->second.index << endl;
        cout << "Jugados: " << it->second.jugados << " | Ganados: " << it->second. ganados << " | Perdidos: " << 
        it->second.perdidos << " | Empatados: " << it->second.empatados << endl << "}" << endl;
    }

    cout << endl;
}
