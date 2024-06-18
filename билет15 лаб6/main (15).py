# Вычисление суммы числового ряда
def series_sum(n):
    series_sum = 0
    for k in range(1, n + 1):
        term = (15 / 2**(k-1)) + ((-1)**(k-1) / (2*3**(k-1)))
        series_sum += term
    return series_sum

# Вычисляем сумму ряда для большого значения n, чтобы приблизить бесконечную сумму
approximate_sum = series_sum(1000)
print(f"Приблизительная сумма числового ряда: {approximate_sum}")