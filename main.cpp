#include "adjoint.h"
#include "primal.h"
#include "utils.h"

#include <stdio.h>

int main() {

    for(double i=1; i<4; i++) {
        printf("square(%f)=%f, grad_square(%f)=%f \n", i, square(i), i, grad_square(i));
    }
    std::cout << "\n";

    for(double i=1; i<4; i++) {
        double j = i + 1;
        auto grad = grad_add(i, j);
        printf("add(%f, %f)=%f, grad_add(%f, %f)=(%f,%f) \n", i, j, add(i, j), i, j, grad.first, grad.second);
    }
    std::cout << "\n";

    for(double i=1; i<4; i++) {
        double j = i + 1;
        auto grad = grad_sub(i, j);
        printf("sub(%f, %f)=%f, grad_sub(%f, %f)=(%f,%f) \n", i, j, sub(&i, &j), i, j, grad.first, grad.second);
    }
    std::cout << "\n";

    for(double i=1; i<4; i++) {
        double j = i + 1;
        auto grad = grad_mul(i, j);
        printf("mul(%f, %f)=%f, grad_mul(%f, %f)=(%f,%f) \n", i, j, mul(i, j), i, j, grad.first, grad.second);
    }
    std::cout << "\n";

    for(double i=1; i<4; i++) {
        double j = i + 1;
        double result;
        div(i, j, result);
        auto grad = grad_div(i, j);
        printf("div(%f, %f)=%f, grad_div(%f, %f)=(%f,%f) \n", i, j, result, i, j, grad.first, grad.second);
    }
    std::cout << "\n";

        {
        std::vector<double> c{1, 2, 3};
        std::vector<double> x{2, 3, 4};
        auto y = dot(c, x);
        auto dx = grad_dot(c, x);
        std::cout << "c=" << c << "\n";
        std::cout << "x=" << x << "\n";
        std::cout << "dot(c, x)=" << y << ", grad_dot(c, x, dx)=" << dx << "\n";
    }
    std::cout << "\n";

    {
        double alpha = 1;
        double beta = 1;
        std::vector<std::vector<double>> A(2);
        A[0] = std::vector<double>{1, 2, 3};
        A[1] = std::vector<double>{4, 5, 6};

        std::vector<double> x{2, 3, 4};
        std::vector<double> y{7, 8};
        std::vector<double> dy{0, 1};

        std::cout << "alpha=" << alpha << "\n";
        std::cout << "beta=" << beta << "\n";
        std::cout << "A=\n" << A << "\n";
        std::cout << "x=" << x << "\n"; 
        std::cout << "y=" << y << "\n";
        std::cout << "dy=" << dy << "\n"; 
        
        auto y_copy = y;
        gemv(alpha, A, x, beta, y);
        auto dx = grad_gemv(alpha, A, x, beta, y_copy, dy);

        std::cout << "gemv(alpha, A, x, beta, y)=" << y << ", grad_gemv(alpha, A, x, dx, beta, y, dy)=" << dx << "\n";
        std::cout << "dy=" << dy << "\n"; 
    }
}


