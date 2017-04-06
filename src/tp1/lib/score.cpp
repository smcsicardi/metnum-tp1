#include "score.h"

// Partido ganado suma 3
// Partido empatado suma 1
// Partido perdido no suma

void generarVectorScore(const map<int, Equipo>& equipos, matriz& scores){
    inicializarMatrizConVal(scores, equipos.size(), 1, 0);
    for(auto it = equipos.begin(); it != equipos.end(); ++it){
        scores[it->second.index][0] = it->second.ganados * 3 + it->second.empatados;
    }
}