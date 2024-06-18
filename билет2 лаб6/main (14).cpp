#include <iostream>
#include <cmath>

double f(double x1, double x2) {
    return x1 + 5 * x2 + exp(x1 * x1 + x2 * x2);
}

double coordinate_descent() {
    const double epsilon = 1e-6;
    const double alpha = 0.01;  // Размер шага

    double x1 = 0.0;
    double x2 = 0.0;
    double prev_result = f(x1, x2);
    double curr_result = prev_result - 2 * epsilon;  // Гарантированный запуск цикла

    while (std::abs(curr_result - prev_result) > epsilon) {
        prev_result = curr_result;

        // Выбираем направление спуска для x1
        double direction_x1 = 1 + 2 * x1 * exp(x1 * x1 + x2 * x2);
        // Меняем x1 по направлению антиградиента
        x1 -= alpha * direction_x1;

        // Выбираем направление спуска для x2
        double direction_x2 = 5 + 2 * x2 * exp(x1 * x1 + x2 * x2);
        // Меняем x2 по направлению антиградиента
        x2 -= alpha * direction_x2;

        curr_result = f(x1, x2);
    }

    return curr_result;
}

int main() {
    double result = coordinate_descent();
    std::cout << "Оптимальное значение функции: " << result << std::endl;
    return 0;
}