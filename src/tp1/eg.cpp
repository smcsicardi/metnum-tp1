#include "Includes.h"


void gaussian_elim(matriz &A, matriz &b){

    for (int k = 0; k != A.size()-1; k++) {

        for (int i = k+1; i != A.size(); i++) {

           double m = A[i][k]/A[k][k];

           for (int j = k; j != A.size(); j++) {
               A[i][j] = A[i][j] - m*A[k][j];
           }

           b[i][0] = b[i][0] - m*b[k][0];
        }
    }
}


void show_matrix(string name, matriz &A) {
    cout << name;
    cout << endl;
    for (auto i : A) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}


// int main(){

//     srand(time(0));


//     int n = 5;
//     matriz A (n, vector<double>(n, 0));
//     vec b (n, 0);

//     // Initializing
//     for (auto& i : b) {
//         i = rand() % 20;
//     }

//     for (auto& i : A) {
//         for (auto& j : i) {
//             j = rand() % 20;
//         }
//     }

//     // Intro
//     cout << "b:";
//     cout << endl;
//     for (auto i : b) {
//         cout << i << " ";
//     }
//     cout << endl;

//     show_matrix("A:", A);

//     // E.G.
//     vector<vec> res = gaussian_elim(A, b);

//     show_matrix("D:", A);

//     return 0;
// }
