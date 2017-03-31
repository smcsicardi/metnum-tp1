#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>


using namespace std;

#define vec vector<double>

int n = 5;

vector<vec> gaussian_elim(vector<vec> &A, vec &b){

    for (int k = 0; k != n-1; k++) {

        for (int i = k+1; i != n; i++) {

           double m = A[i][k]/A[k][k];

           for (int j = k; j != n; j++) {
               A[i][j] = A[i][j] - m*A[k][j];
           }

           b[i] = b[i] - m*b[k];
        }
    }

    return A;
}

void show_matrix(string name, vector<vec> &A) {
    cout << name;
    cout << endl;
    for (auto i : A) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main(){

    srand(time(0));

    vector<vec> A (n, vector<double>(n, 0));
    vec b (n, 0);

    // Initializing
    for (auto& i : b) {
        i = rand() % 20;
    }

    for (auto& i : A) {
        for (auto& j : i) {
            j = rand() % 20;
        }
    }

    // Intro
    cout << "b:";
    cout << endl;
    for (auto i : b) {
        cout << i << " ";
    }
    cout << endl;

    show_matrix("A:", A);

    // E.G.
    vector<vec> res = gaussian_elim(A, b);

    show_matrix("D:", A);

    return 0;
}
