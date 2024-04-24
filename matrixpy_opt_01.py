import numpy as np
import time

def run_tests(matrix_size):
    A = np.ones((matrix_size, matrix_size), dtype=int)
    B_identity = np.eye(matrix_size)
    B_all_ones = np.ones((matrix_size, matrix_size), dtype=int)
    B_all_twos = np.ones((matrix_size, matrix_size), dtype=int) * 2
    sequential_ints = np.arange(matrix_size * matrix_size).reshape((matrix_size, matrix_size))
    sequential_floats = sequential_ints.astype(float)

    tests = [
        ("All int 1's * Identity matrix:", A, B_identity),
        ("All int 2's * Identity matrix:", B_all_twos, B_identity),
        ("Sequential integers * Identity matrix:", sequential_ints, B_identity),
        ("All float 1's * Identity matrix:", A, B_identity),  # Reusing A as all 1's matrix for floats
        ("All float 2's * Identity matrix:", B_all_twos, B_identity),
        ("Sequential floats * Identity matrix:", sequential_floats, B_identity),
        ("All Int 1's * all Int 1's:", A, B_all_ones),
        ("All int 2's * all Int 1's:", B_all_twos, B_all_ones),
        ("Sequential integers * All Int 1's:", sequential_ints, B_all_ones),
        ("All float 1's * All float 1's:", A, B_all_ones),  # Reusing A as all 1's matrix for floats
        ("All float 2's * All float 1's:", B_all_twos, B_all_ones),
        ("Sequential floats * All float 1's:", sequential_floats, B_all_ones),
        ("All Int 1's * all Int 2's:", A, B_all_twos),
        ("All int 2's * all Int 2's:", B_all_twos, B_all_twos),
        ("Sequential integers * All Int 2's:", sequential_ints, B_all_twos),
        ("All float 1's * All float 2's:", A, B_all_twos),  # Reusing A as all 1's matrix for floats
        ("All float 2's * All float 2's:", B_all_twos, B_all_twos),
        ("Sequential floats * All float 2's:", sequential_floats, B_all_twos),
    ]

    print(f"Start optimized {matrix_size} testing...\n")

    for description, matrix_A, matrix_B in tests:
        start_time = time.time()
        np.dot(matrix_A, matrix_B)
        elapsed_time = time.time() - start_time
        print(f"{description}\nMatrix Multiplication of size {matrix_size} took {elapsed_time:.5f} seconds.\n")

    print("\n\n==================================\n\n")

def benchmark(matrix_size):
    run_tests(matrix_size)

benchmark(128)
benchmark(256)
benchmark(512)

