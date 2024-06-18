import math

# Уравнение: x * exp(x) - x - 1 = 0

def f(x):
    return x * math.exp(x) - x - 1

# Метод половинного деления (дихотомии)
def bisection(a, b, epsilon):
    while (b - a) >= epsilon:
        c = (a + b) / 2
        if f(c) == 0.0:
            return c
        elif f(c) * f(a) < 0:
            b = c
        else:
            a = c
    return (a + b) / 2

# Метод итераций (итерационный метод простой итерации)
def iterative(x0, epsilon):
    x = x0
    while abs(f(x)) >= epsilon:
        x = math.exp(-x)
    return x

# Метод хорд
def chord(x0, epsilon):
    x = x0
    while abs(f(x)) >= epsilon:
        x = x - (f(x) * (x - math.exp(x)) / (f(x) - f(math.exp(x))))
    return x

# Метод Ньютона
def newton(x0, epsilon):
    x = x0
    while abs(f(x)) >= epsilon:
        x = x - (f(x) / (math.exp(x) + x * math.exp(x) - 1))
    return x

epsilon = 1e-6

# Нахождение корней уравнения с точностью E=10^-6
root_bisection = bisection(0, 1, epsilon)
root_iterative = iterative(0, epsilon)
root_chord = chord(0, epsilon)
root_newton = newton(0, epsilon)

print("Корень (дихотомия):", root_bisection)
print("Корень (итерации):", root_iterative)
print("Корень (хорды):", root_chord)
print("Корень (Ньютона):", root_newton)