#ifndef EG_H
#define EG_H

#include "tipos.h"

void upper_triangulate(matriz &A, matriz &b);

matriz backwards_substitution(matriz &A, matriz &b);

matriz gaussian_elim(matriz &A, matriz &b);

#endif
