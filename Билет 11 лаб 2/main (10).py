import numpy as np

def vector_length(vector):
    return np.linalg.norm(vector)

def angle_between_vectors(vector1, vector2):
    cos_angle = np.dot(vector1, vector2) / (np.linalg.norm(vector1) * np.linalg.norm(vector2))
    angle_in_radians = np.arccos(np.clip(cos_angle, -1.0, 1.0))
    return np.degrees(angle_in_radians)

def vector_sum(vector1, vector2):
    return vector1 + vector2

def vector_difference(vector1, vector2):
    return vector1 - vector2

def are_parallel(vector1, vector2):
    return np.all(np.isclose(vector1 / np.linalg.norm(vector1), vector2 / np.linalg.norm(vector2)))

def are_coplanar(vector1, vector2, vector3):
    matrix = np.vstack((vector1, vector2, vector3))
    return np.isclose(np.linalg.det(matrix), 0)


# Генерируем случайные векторы в трёхмерном пространстве
vector1 = np.random.rand(3)
vector2 = np.random.rand(3)
vector3 = np.random.rand(3)

# Находим длины векторов
lengths = [vector_length(vector1), vector_length(vector2), vector_length(vector3)]

# Находим углы между векторами попарно
angles = [angle_between_vectors(vector1, vector2),
          angle_between_vectors(vector1, vector3),
          angle_between_vectors(vector2, vector3)]

# Находим сумму и разность векторов попарно
sums = [vector_sum(vector1, vector2),
        vector_sum(vector1, vector3),
        vector_sum(vector2, vector3)]

differences = [vector_difference(vector1, vector2),
               vector_difference(vector1, vector3),
               vector_difference(vector2, vector3)]

# Проверяем параллельность векторов
parallel_pairs = [(1, 2) if are_parallel(vector1, vector2) else None,
                  (1, 3) if are_parallel(vector1, vector3) else None,
                  (2, 3) if are_parallel(vector2, vector3) else None]

# Проверяем, лежат ли вектора в одной плоскости
coplanar = are_coplanar(vector1, vector2, vector3)

print("Длины векторов:", lengths)
print("Углы между векторами (в градусах):", angles)
print("Суммы векторов:", sums)
print("Разности векторов:", differences)
print("Параллельные вектора:", [pair for pair in parallel_pairs if pair is not None])
print("Вектора лежат в одной плоскости:", coplanar)