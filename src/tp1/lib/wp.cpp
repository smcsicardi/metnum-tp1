#include "wp.h"


void generarVectorWP(map<int, Equipo>& equipos, matriz& wp){
    double valorWp;
    int i = 0;
    inicializarMatrizConVal(wp,equipos.size(), 1, 0);
    for ( auto it = equipos.begin(); it != equipos.end(); ++it ){
        Equipo eq = it->second;
        if (eq.jugados != 0){
            valorWp = eq.ganados/eq.jugados;
            wp[i][0] = valorWp;
        }
        i++;
    }
}