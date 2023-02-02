#include "primal.h"
#include <cstddef>
#include <cassert>

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

double dot(const std::vector<double>& c, const std::vector<double>& x) {
    assert(c.size() == x.size());

    double y = 0;
    for(size_t i = 0; i < c.size(); ++i) {
        y += c[i] * x[i];
    }
    return y;
}

void gemv(double alpha, 
        const std::vector<std::vector<double>>& A, 
        const std::vector<double>& x, 
        double beta, 
        std::vector<double>& y) {
    assert(A.size() == y.size() && A.size() > 1 && A[0].size() == x.size());

    for(size_t i = 0; i < A.size(); ++i) {
        y[i] = alpha * dot(A[i], x) + beta * y[i];
    }
}