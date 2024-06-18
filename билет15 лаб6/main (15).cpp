#include <iostream>
#include <cmath>

double f(double x) {
    return exp(-2) * sin(15 * x);
}

// Метод прямоугольников
double rectangle_method(double a, double b, int n) {
    double h = (b - a) / n;
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        result += f(a + (i + 0.5) * h);
    }
    result *= h;
    return result;
}

// Метод трапеций
double trapezoidal_method(double a, double b, int n) {
    double h = (b - a) / n;
    double result = 0.0;
    for (int i = 1; i < n; i++) {
        result += f(a + i * h);
    }
    result += (f(a) + f(b)) / 2;
    result *= h;
    return result;
}

// Метод Симпсона
double simpsons_method(double a, double b, int n) {
    double h = (b - a) / n;
    double result = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        if (i % 2 == 0) {
            result += 2 * f(a + i * h);
        } else {
            result += 4 * f(a + i * h);
        }
    }
    result *= h / 3;
    return result;
}

int main() {
    double a = 0;  // Нижний предел интегрирования
    double b = 1000;  // Бесконечность можно приблизить большим числом
    double desired_accuracy = 1e-6;  // Требуемая точность

    int n = 10;  // Начинаем с небольшого числа интервалов
    double prev_result = 0, curr_result = 0;

    // Увеличиваем количество интервалов, пока точность не достигнута
    while (true) {
        prev_result = curr_result;
        curr_result = simpsons_method(a, b, n);
        if (std::abs(curr_result - prev_result) < desired_accuracy) {
            break;
        }
        n *= 2;
    }

    std::cout << "Значение интеграла методом прямоугольников: " << rectangle_method(a, b, n) << std::endl;
    std::cout << "Значение интеграла методом трапеций: " << trapezoidal_method(a, b, n) << std::endl;
    std::cout << "Значение интеграла методом Симпсона: " << curr_result << std::endl;

    return 0;
}