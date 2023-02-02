#pragma once
#include <utility>
#include <vector>

double grad_square(double x);

std::pair<double, double> grad_add(double x, double y);

std::pair<double, double> grad_sub(double x, double y);

std::pair<double, double> grad_mul(double x, double y);

std::pair<double, double> grad_div(double x, double y);

std::vector<double> grad_dot(const std::vector<double>& c, const std::vector<double>& x);

std::vector<double> grad_gemv(double alpha, 
            const std::vector<std::vector<double>>& A, 
            const std::vector<double>& x, 
            double beta, 
            std::vector<double>& y, std::vector<double>& dy);