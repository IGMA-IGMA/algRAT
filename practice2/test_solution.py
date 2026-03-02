import solution

area_accuracy = 187.5

print("ТЕСТЫ СХОДИМОСТИ ФОРМУЛЫ")
print("-" * 50)

for i in range(0, 10):
    area_simp = solution.area(3, 6, 10 ** i)
    error = abs(area_accuracy - area_simp) / area_accuracy * 100

    print(
        f"Тест{i+1:2d} | шаг=10^{i:<2d} | результат={area_simp:.8f} | погрешность={error:.6f}%")

print("-" * 50)
