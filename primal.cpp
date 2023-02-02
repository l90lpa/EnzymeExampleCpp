#include "primal.h"

double square(double x) {
    return x * x;
}

double add(const double& x, const double& y) {
    return x + y;
}

double sub(const double* x, const double* y) {
    return (*x) - (*y);
}

double mul(double x, double y) {
    return x * y;
}

void div(const double& x, const double& y, double& result) {
    result = x / y;
}