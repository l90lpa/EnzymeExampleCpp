#include "adjoint.h"
#include "primal.h"

#include <stdio.h>

int main() {

    for(double i=1; i<4; i++) {
        printf("square(%f)=%f, grad_square(%f)=%f \n", i, square(i), i, grad_square(i));
    }
}


