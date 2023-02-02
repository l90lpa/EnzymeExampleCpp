#pragma once
#include <vector>

double square(double x);

double add(const double& x, const double& y);

double sub(const double* x, const double* y);

double mul(double x, double y);

void div(const double& x, const double& y, double& result);

double dot(const std::vector<double>& c, const std::vector<double>& x);

void gemv(double alpha, 
        const std::vector<std::vector<double>>& A, 
        const std::vector<double>& x, 
        double beta, 
        std::vector<double>& y);