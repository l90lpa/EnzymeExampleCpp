#include "adjoint.h"
#include "primal.h"

int enzyme_dup;
int enzyme_dupnoneed;
int enzyme_out;
int enzyme_const;

extern double __enzyme_autodiff_square(void*, ...);
extern void __enzyme_autodiff_add(void*, int, double&, double&, int, double&, double&);
extern void __enzyme_autodiff_sub(void*, ...);
extern void __enzyme_autodiff_mul(double (*) (const double&, const double&), int, double&, double&, int, double&, double&);
extern void __enzyme_autodiff_div(void*, int, double&, double&, int, double&, double&, int, double&, double&);

double grad_square(double x) {
    return __enzyme_autodiff_square((void*)square, x);
}

std::pair<double, double> grad_add(double x, double y) {
    
    auto grad = std::make_pair(0.0, 0.0);

    __enzyme_autodiff_add((void*)add, 
                            enzyme_dup, x, grad.first, 
                            enzyme_dup, y, grad.second);
    
    return grad;
}

std::pair<double, double> grad_sub(double x, double y) {
    
    auto grad = std::make_pair(0.0, 0.0);

    __enzyme_autodiff_sub((void*)sub, 
                            enzyme_dup, &x, &(grad.first), 
                            enzyme_dup, &y, &(grad.second));
    
    return grad;
}

std::pair<double, double> grad_mul(double x, double y) {
    
    auto grad = std::make_pair(0.0, 0.0);
    
    auto add_wrap = [](const double& a, const double& b) {
        return mul(a, b);
    };

    __enzyme_autodiff_mul(add_wrap, 
                        enzyme_dup, x, grad.first, 
                        enzyme_dup, y, grad.second);
    return grad;
}

std::pair<double, double> grad_div(double x, double y) {
    
    auto grad = std::make_pair(0.0, 0.0);
    double result;
    double dresult = 1.0;
    
    __enzyme_autodiff_div((void*)div, 
                            enzyme_dup, x, grad.first,  
                            enzyme_dup, y, grad.second,
                            enzyme_dupnoneed, result, dresult);
    return grad;
}