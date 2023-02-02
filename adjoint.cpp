#include "adjoint.h"
#include "primal.h"
#include <cassert>

int enzyme_dup;
int enzyme_dupnoneed;
int enzyme_out;
int enzyme_const;

extern double __enzyme_autodiff_square(void*, ...);
extern void __enzyme_autodiff_add(void*, int, double&, double&, int, double&, double&);
extern void __enzyme_autodiff_sub(void*, ...);
extern void __enzyme_autodiff_mul(double (*) (const double&, const double&), int, double&, double&, int, double&, double&);
extern void __enzyme_autodiff_div(void*, int, double&, double&, int, double&, double&, int, double&, double&);
extern void __enzyme_autodiff_dot(void*, int, const std::vector<double>&, int, const std::vector<double>&, std::vector<double>&);
extern void __enzyme_autodiff_gemv(void*, 
                                int, double,
                                int, const std::vector<std::vector<double>>&,
                                int, const std::vector<double>&, std::vector<double>&,
                                int, double,
                                int, std::vector<double>&, std::vector<double>&);

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

// grad_dot is treating 'c' as a constant vector so in effect, dot(c,x)=f(x)=<c,x>
std::vector<double> grad_dot(const std::vector<double>& c, const std::vector<double>& x) {
    assert(c.size() == x.size());

    std::vector<double> dx(x.size(), 0);

    __enzyme_autodiff_dot((void*)dot, 
                        enzyme_const, c, 
                        enzyme_dup, x, dx);
    
    return dx;
}

std::vector<double> grad_gemv(double alpha, 
            const std::vector<std::vector<double>>& A, 
            const std::vector<double>& x, 
            double beta, 
            std::vector<double>& y, std::vector<double>& dy) {
    assert(A.size() == y.size() && A.size() > 1 && A[0].size() == x.size());

    std::vector<double> dx(x.size(), 0);

    __enzyme_autodiff_gemv((void*)gemv, 
                    enzyme_const, alpha, 
                    enzyme_const, A, 
                    enzyme_dup, x, dx,
                    enzyme_const, beta, 
                    enzyme_dupnoneed, y, dy);

    return dx;
}
