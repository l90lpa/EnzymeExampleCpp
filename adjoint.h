#pragma once
#include <utility>

double grad_square(double x);

std::pair<double, double> grad_add(double x, double y);

std::pair<double, double> grad_sub(double x, double y);

std::pair<double, double> grad_mul(double x, double y);

std::pair<double, double> grad_div(double x, double y);