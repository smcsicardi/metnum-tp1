#include "wp.h"


matriz generarVectorWP(map<int, Equipo>& equipos){
    double valorWp;
    int i = 0;
    matriz wp(equipos.size(), vector<double> (1));
    for ( auto it = equipos.begin(); it != equipos.end(); ++it ){
        Equipo eq = it->second;
        if (eq.jugados != 0){
            valorWp = eq.ganados/eq.jugados;
            wp[i][0] = valorWp;
        }
        i++;
    }
    return wp;
}