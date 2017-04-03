#include "eg.h"
#include "tipos.h"

void gaussian_elim(matriz &A, matriz &b){
    unsigned int n = A.size();

    for (unsigned int k = 0; k != n - 1; k++) {

        for (unsigned int i = k + 1; i != n; i++) {

           double m = A[i][k]/A[k][k];

           for (unsigned int j = k; j != n; j++) {
               A[i][j] = A[i][j] - m*A[k][j];
           }

           b[i][0] = b[i][0] - m*b[k][0];
        }
    }
}
