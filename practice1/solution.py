import tracemalloc
import time
from functools import wraps
from typing import Callable


def measure_performance(func: Callable) -> Callable:
    """
    Декоратор для измерения времени выполнения и использования памяти
    """
    @wraps(func)
    def wrapper(*args, **kwargs):
        tracemalloc.clear_traces()

        tracemalloc.start()

        start_time = time.time()

        result = func(*args, **kwargs)

        end_time = time.time()

        current, peak = tracemalloc.get_traced_memory()
        tracemalloc.stop()

        input_size = len(args[0]) if args and hasattr(
            args[0], '__len__') else 'N/A'

        print(f"\n{'='*60}")
        print(f"ФУНКЦИЯ: {func.__name__}")
        print(f"{'='*60}")
        print(f"📦 Размер входных данных: {input_size} элементов")
        print(f"⏱️  Время выполнения: {end_time - start_time:.8f} сек")
        print(f"⏱️  Время выполнения: {(end_time - start_time) * 1000:.3f} мс")
        print(
            f"💾 Память (текущая): {current / 1024:.3f} KB ({current / (1024*1024):.6f} MB)")
        print(
            f"💾 Память (пик): {peak / 1024:.3f} KB ({peak / (1024*1024):.6f} MB)")
        print(f"📊 Результат: {result}")
        print(f"{'='*60}\n")

        return result

    return wrapper


def len_massive(lst: list) -> int:
    i = 0
    for _ in lst:
        i += 1
    return i
