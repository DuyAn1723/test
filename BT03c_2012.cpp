#include <iostream>
#include <cmath>

// Hàm tính ??o hàm t?ng
double DeriveSum(double f(double), double g(double), double x) {
    return f(x) + g(x);
}

// Hàm tính ??o hàm tích
double DeriveProduct(double f(double), double g(double), double x) {
    return f(x) * g(x);
}

// Hàm tính ??o hàm th??ng
double DeriveQuotient(double f(double), double g(double), double x) {
    return (f(x) * g(x) - f(x) * g(x)) / std::pow(g(x), 2);
}

// Hàm tính ??o hàm h?p
double DeriveComposite(double f(double), double g(double), double x) {
    return f(g(x)) * g(x);
}

// Hàm m?u ?? minh h?a
double FunctionF(double x) {
    return x * x; // Ví d? hàm f(x) = x^2
}

// Hàm m?u ?? minh h?a
double FunctionG(double x) {
    return 2 * x; // Ví d? hàm g(x) = 2x
}

int main() {
    double x = 2.0;

    double resultSum = DeriveSum(FunctionF, FunctionG, x);
    std::cout << "Derivative of Sum: " << resultSum << std::endl;

    double resultProduct = DeriveProduct(FunctionF, FunctionG, x);
    std::cout << "Derivative of Product: " << resultProduct << std::endl;

    double resultQuotient = DeriveQuotient(FunctionF, FunctionG, x);
    std::cout << "Derivative of Quotient: " << resultQuotient << std::endl;

    double resultComposite = DeriveComposite(FunctionF, FunctionG, x);
    std::cout << "Derivative of Composite: " << resultComposite << std::endl;

    return 0;
}
