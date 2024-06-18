#include <iostream>
#include <cmath>

// Уравнение: x * exp(x) - x - 1 = 0

double f(double x) {
    return x * exp(x) - x - 1;
}

// Метод половинного деления (дихотомии)
double bisection(double a, double b, double epsilon) {
    while ((b - a) >= epsilon) {
        double c = (a + b) / 2;
        if (f(c) == 0.0) {
            return c;
        } else if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    return (a + b) / 2;
}

// Метод итераций (итерационный метод простой итерации)
double iterative(double x0, double epsilon) {
    double x = x0;
    while (abs(f(x)) >= epsilon) {
        x = exp(-x);
    }
    return x;
}

// Метод хорд
double chord(double x0, double epsilon) {
    double x = x0;
    while (abs(f(x)) >= epsilon) {
        x = x - (f(x) * (x - exp(x)) / (f(x) - f(exp(x))));
    }
    return x;
}

// Метод Ньютона
double newton(double x0, double epsilon) {
    double x = x0;
    while (abs(f(x)) >= epsilon) {
        x = x - (f(x) / (exp(x) + x * exp(x) - 1));
    }
    return x;
}

int main() {
    double epsilon = 1e-6;

    // Нахождение корней уравнения с точностью E=10^-6
    double root_bisection = bisection(0, 1, epsilon);
    double root_iterative = iterative(0, epsilon);
    double root_chord = chord(0, epsilon);
    double root_newton = newton(0, epsilon);

    std::cout << "Корень (дихотомия): " << root_bisection << std::endl;
    std::cout << "Корень (итерации): " << root_iterative << std::endl;
    std::cout << "Корень (хорды): " << root_chord << std::endl;
    std::cout << "Корень (Ньютона): " << root_newton << std::endl;

    return 0;
}