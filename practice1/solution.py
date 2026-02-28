import tracemalloc
import time
from functools import wraps
from typing import Callable
import array


def measure_performance(func):
    def wrapper(*args, **kwargs):
        tracemalloc.start()
        
        start = time.time()
        result = func(*args, **kwargs)
        end = time.time()
        
        current, peak = tracemalloc.get_traced_memory()
        tracemalloc.stop()
        
        size = len(args[0]) if args and hasattr(args[0], '__len__') else 0
        
        print(f"Функция: {func.__name__}")
        print(f"Размер данных: {size}")
        print(f"Время: {(end - start) * 1000:.2f} мс")
        print(f"Память: {current / 1024:.2f} KB (пик: {peak / 1024:.2f} KB)")
        print(f"Результат: {result}")
        print("-" * 40)
        
        return result
    
    return wrapper


@measure_performance
def len_massive(arr: array.array) -> int:
    i = 0
    for _ in arr:
        i += 1
    return i
