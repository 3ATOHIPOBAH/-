#include <iostream>
#include <cmath>
#include <random>

struct Point {
    double x, y, z;
};

struct HyperbolicCylinder {
    double a, b, c, r;  // уравнение гиперболического цилиндра: (x/a)^2 - (y/b)^2 = (z/c)^2 - r^2
};

struct Plane {
    double A, B, C, D;  // уравнение плоскости: Ax + By + Cz + D = 0
};

struct Line {
    Point point;
    Point direction;
};

// Проверяем, пересекает ли плоскость заданный гиперболический цилиндр
bool doesIntersect(const HyperbolicCylinder& cylinder, const Plane& plane) {
    // Вычисляем значение левой части уравнения гиперболического цилиндра в точке (0, 0, 0)
    double value = -cylinder.r * cylinder.r;
    
    // Вычисляем значение левой части уравнения гиперболического цилиндра на пересечении с плоскостью
    value += (plane.A * plane.A * cylinder.a * cylinder.a) - (plane.B * plane.B * cylinder.b * cylinder.b) + (plane.C * plane.C * cylinder.c * cylinder.c);

    return value >= 0;
}

// Проверяем, принадлежит ли точка заданному гиперболическому цилиндру
bool isPointOnCylinder(const Point& point, const HyperbolicCylinder& cylinder) {
    double value = (point.x * point.x) / (cylinder.a * cylinder.a) - (point.y * point.y) / (cylinder.b * cylinder.b) - (point.z * point.z) / (cylinder.c * cylinder.c);
    return std::abs(value - cylinder.r * cylinder.r) < 1e-10;  // используем эпсилон для проверки равенства чисел с плавающей точкой
}

int main() {
    // Создаём генератор случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-10.0, 10.0); // Случайные числа в диапазоне [-10.0, 10.0]

    // Генерируем параметры гиперболического цилиндра
    HyperbolicCylinder cylinder;
    cylinder.a = dis(gen);
    cylinder.b = dis(gen);
    cylinder.c = dis(gen);
    cylinder.r = dis(gen);

    // Генерируем параметры плоскости
    Plane plane;
    plane.A = dis(gen);
    plane.B = dis(gen);
    plane.C = dis(gen);
    plane.D = dis(gen);

    // Генерируем параметры прямой (для простоты, будем использовать только точку и направляющий вектор)
    Line line;
    line.point.x = dis(gen);
    line.point.y = dis(gen);
    line.point.z = dis(gen);
    line.direction.x = dis(gen);
    line.direction.y = dis(gen);
    line.direction.z = dis(gen);

    // Генерируем случайную точку
    Point point;
    point.x = dis(gen);
    point.y = dis(gen);
    point.z = dis(gen);

    // Проверяем пересечение плоскости с гиперболическим цилиндром
    bool doesIntersectPlane = doesIntersect(cylinder, plane);

    // Проверяем, принадлежит ли точка заданному гиперболическому цилиндру
    bool pointOnCylinder = isPointOnCylinder(point, cylinder);

    // Выводим результаты
    std::cout << "Плоскость пересекает гиперболический цилиндр: " << (doesIntersectPlane ? "Да" : "Нет") << std::endl;
    std::cout << "Точка принадлежит гиперболическому цилиндру: " << (pointOnCylinder ? "Да" : "Нет") << std::endl;

    return 0;
}