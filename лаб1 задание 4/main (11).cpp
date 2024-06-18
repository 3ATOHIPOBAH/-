#include <iostream>
#include <complex>

int main() {
    std::complex<double> z1(-1, 1);
    std::complex<double> z2(-4, -2);

    // Сумма
    std::complex<double> sum = z1 + z2;
    std::cout << "Сумма: " << sum << std::endl;

    // Разность
    std::complex<double> diff = z1 - z2;
    std::cout << "Разность: " << diff << std::endl;

    // Произведение
    std::complex<double> prod = z1 * z2;
    std::cout << "Произведение: " << prod << std::endl;

    // Частное
    std::complex<double> quot = z1 / z2;
    std::cout << "Частное: " << quot << std::endl;

    return 0;
}