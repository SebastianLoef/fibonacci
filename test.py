from my_c_module import fib
import time
from typing import Callable, Any

def time_taken(func: Callable[[int], int], *args: Any):
    start = time.time()
    res = func(*args)
    time_taken = (time.time() - start) * 1000
    print(f"Time taken: {time_taken} ms")
    return res
def fib_py(n: int) -> int:
    a,b,c = 0,1,0
    for _ in range(n):
        c = a+b
        a,b = b,c
    return c

def main(n: int = 10000000):
    print(f"Calculating fibonnaci number n={n} using Python")
    res = time_taken(fib_py, n)
    print(f"Calculating fibonnaci number n={n} using C")
    res = time_taken(fib, n)

if __name__ == '__main__':
    main()