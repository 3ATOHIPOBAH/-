#include <iostream>
#include <cmath>

double calculate_series_sum(double x) {
    double sum = 0.0;
    double term = 0.0;
    int k = 1;
    do {
        term = pow(-1, k) / (sin(k * x) + 15 + pow(k, 2));
        sum += term;
        k++;
    } while (std::abs(term) >= 1e-6);

    return sum;
}

int main() {
    double x = 3.14;  // Пример значения x, можно изменить по желанию

    double series_sum = calculate_series_sum(x);

    std::cout << "Сумма числового ряда для x = " << x << " : " << series_sum << std::endl;

    return 0;
}