#include "dsquare.h"
#include "square.h"

extern double __enzyme_autodiff(void*, double);

double dsquare(double x) {
    // This returns the derivative of square or 2 * x
    return __enzyme_autodiff((void*) square, x);
}