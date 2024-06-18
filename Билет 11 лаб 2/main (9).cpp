#include <iostream>
#include <cmath>
#include <random>
#include <vector>

// Структура для представления точки на плоскости
struct Point {
    double x;
    double y;
};

// Структура для представления уравнения гиперболы
struct Hyperbola {
    double a; // Параметр уравнения гиперболы
    double b; // Параметр уравнения гиперболы
    double h; // Координата центра гиперболы
    double k; // Координата центра гиперболы
};

// Функция для проверки принадлежности точки гиперболе
bool isPointOnHyperbola(const Point& point, const Hyperbola& hyperbola) {
    return pow((point.x - hyperbola.h), 2) / pow(hyperbola.a, 2) - pow((point.y - hyperbola.k), 2) / pow(hyperbola.b, 2) == 1;
}

// Функция для вычисления фокусов гиперболы
std::vector<Point> calculateFoci(const Hyperbola& hyperbola) {
    std::vector<Point> foci;
    double c = sqrt(pow(hyperbola.a, 2) + pow(hyperbola.b, 2));
    foci.push_back({ hyperbola.h + c, hyperbola.k });
    foci.push_back({ hyperbola.h - c, hyperbola.k });
    return foci;
}

// Функция для вычисления длины действительной полуоси
double calculateRealSemiAxis(const Hyperbola& hyperbola) {
    return fabs(hyperbola.a);
}

// Функция для вычисления длины мнимой полуоси
double calculateImaginarySemiAxis(const Hyperbola& hyperbola) {
    return fabs(hyperbola.b);
}

// Функция для вычисления эксцентриситета
double calculateEccentricity(const Hyperbola& hyperbola) {
    return sqrt(1 + pow(hyperbola.b, 2) / pow(hyperbola.a, 2));
}

// Функция для вычисления расстояния между диссектриссами гиперболы
double calculateDistanceBetweenDirectrices(const Hyperbola& hyperbola) {
    return 2 * fabs(hyperbola.a) / calculateEccentricity(hyperbola);
}

int main() {
    // Создаём генератор случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-10.0, 10.0); // Случайные числа в диапазоне [-10.0, 10.0]

    // Генерируем параметры гиперболы
    Hyperbola hyperbola;
    hyperbola.a = dis(gen);
    hyperbola.b = dis(gen);
    hyperbola.h = dis(gen);
    hyperbola.k = dis(gen);

    // Генерируем случайную точку
    Point point;
    point.x = dis(gen);
    point.y = dis(gen);

    // Проверяем принадлежность точки гиперболе
    bool pointOnHyperbola = isPointOnHyperbola(point, hyperbola);

    // Вычисляем фокусы гиперболы
    std::vector<Point> foci = calculateFoci(hyperbola);

    // Вычисляем остальные параметры гиперболы
    double realSemiAxis = calculateRealSemiAxis(hyperbola);
    double imaginarySemiAxis = calculateImaginarySemiAxis(hyperbola);
    double eccentricity = calculateEccentricity(hyperbola);
    double distanceBetweenDirectrices = calculateDistanceBetweenDirectrices(hyperbola);

    // Выводим результаты
    std::cout << "Точка принадлежит гиперболе: " << (pointOnHyperbola ? "Да" : "Нет") << std::endl;
    std::cout << "Фокусы гиперболы: (" << foci[0].x << ", " << foci[0].y << ") и (" << foci[1].x << ", " << foci[1].y << ")" << std::endl;
    std::cout << "Длина действительной полуоси: " << realSemiAxis << std::endl;
    std::cout << "Длина мнимой полуоси: " << imaginarySemiAxis << std::endl;
    std::cout << "Эксцентриситет гиперболы: " << eccentricity << std::endl;
    std::cout << "Расстояние между диссектриссами: " << distanceBetweenDirectrices << std::endl;

    return 0;
}