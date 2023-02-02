#include "adjoint.h"
#include "primal.h"

#include <stdio.h>
#include <iostream>

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
}


