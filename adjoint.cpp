#include "adjoint.h"
#include "primal.h"

extern double __enzyme_autodiff_square(void*, ...);

double grad_square(double x) {
    return __enzyme_autodiff_square((void*)square, x);
}