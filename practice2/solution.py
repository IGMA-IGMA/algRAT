def formula_simps(n: int, a: int, b: int, f) -> int:

    h = (b - a) / float(n)
    result = f(a) + f(b)

    for i in range(n):
        x: float = a + i * h
        if i % 2 == 0:
            result += 2 * f(x)
        else:
            result += 4 * f(x)
    return result * h / 3


def y1(x): return x ** 3 - 12 * x ** 2 + 4
def y2(x): return -x ** 3 + x ** 2 - 4


def area(a, b, n, f1=y1, f2=y2): return abs(
    abs(formula_simps(n, a, b, f1)) - abs(formula_simps(n, a, b, f2)))


if __name__ == "__main__":
    a, b, = 3, 6
    area = area(y1, y2, a, b, 10**10)
    print(f"Приближенное значение: {area}")
