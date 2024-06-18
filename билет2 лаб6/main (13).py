import numpy as np

def f(x):
    return x[0] + 2*x[1] + 4*np.sqrt(1 + x[0]**2 + x[1]**2)

def grad_f(x):
    grad_x1 = (2 * x[0]) / np.sqrt(1 + x[0]**2 + x[1]**2) + 1
    grad_x2 = (2 * x[1]) / np.sqrt(1 + x[0]**2 + x[1]**2) + 2
    return np.array([grad_x1, grad_x2])

def gradient_descent():
    x = np.array([0.0, 0.0])
    learning_rate = 0.1
    epsilon = 1e-6

    while True:
        gradient = grad_f(x)
        next_x = x - learning_rate * gradient
        if np.linalg.norm(next_x - x) < epsilon:
            break
        x = next_x

    return x, f(x)

optimal_x, minimal_value = gradient_descent()
print(f"Оптимальное значение x: {optimal_x}")
print(f"Минимальное значение функции: {minimal_value}")