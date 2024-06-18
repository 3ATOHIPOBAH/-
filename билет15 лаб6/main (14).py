import numpy as np

# Функция, значение которой мы хотим проинтегрировать
def f(x):
    return x**4 / (15 + x**2)

# Метод прямоугольников
def rectangle_method(a, b, n):
    h = (b - a) / n
    result = 0
    for i in range(n):
        result += f(a + i * h + h / 2)
    result *= h
    return result

# Метод трапеций
def trapezoidal_method(a, b, n):
    h = (b - a) / n
    result = (f(a) + f(b)) / 2
    for i in range(1, n):
        result += f(a + i * h)
    result *= h
    return result

# Метод Симпсона
def simpsons_method(a, b, n):
    h = (b - a) / n
    result = f(a) + f(b)
    for i in range(1, n):
        if i % 2 == 0:
            result += 2 * f(a + i * h)
        else:
            result += 4 * f(a + i * h)
    result *= h / 3
    return result

# Интеграл от 1 до 2
a = 1
b = 2

# Желаемая точность
desired_accuracy = 1e-6

# Начинаем с небольшого числа интервалов
n = 10

# Увеличиваем количество интервалов, пока точность не достигнута
while True:
    result_rectangle = rectangle_method(a, b, n)
    result_trapezoidal = trapezoidal_method(a, b, n)
    result_simpson = simpsons_method(a, b, n)
    if abs(result_rectangle - result_simpson) < desired_accuracy and abs(result_trapezoidal - result_simpson) < desired_accuracy:
        break
    n *= 2

print(f"Значение интеграла методом прямоугольников: {result_rectangle}")
print(f"Значение интеграла методом трапеций: {result_trapezoidal}")
print(f"Значение интеграла методом Симпсона: {result_simpson}")