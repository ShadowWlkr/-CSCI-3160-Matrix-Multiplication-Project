import time

def naive_matrix_multiply_int(A, B, size):
    C = [[0 for _ in range(size)] for _ in range(size)]
    for i in range(size):
        for j in range(size):
            for k in range(size):
                C[i][j] += A[i][k] * B[k][j]
    return C

def naive_matrix_multiply_float(A, B, size):
    C = [[0.0 for _ in range(size)] for _ in range(size)]
    for i in range(size):
        for j in range(size):
            for k in range(size):
                C[i][j] += A[i][k] * B[k][j]
    return C

def run_tests(matrix_size):
    A = [[1 for _ in range(matrix_size)] for _ in range(matrix_size)]
    B_identity = [[1 if i == j else 0 for i in range(matrix_size)] for j in range(matrix_size)]
    B_all_ones = [[1 for _ in range(matrix_size)] for _ in range(matrix_size)]
    B_all_twos = [[2 for _ in range(matrix_size)] for _ in range(matrix_size)]
    sequential_ints = [[i for i in range(matrix_size)] for _ in range(matrix_size)]
    sequential_floats = [[float(i) for i in range(matrix_size)] for _ in range(matrix_size)]

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

    print(f"Start unoptimized {matrix_size} testing...\n")

    for description, matrix_A, matrix_B in tests:
        start_time = time.time()
        if isinstance(matrix_A[0][0], int):
            naive_matrix_multiply_int(matrix_A, matrix_B, matrix_size)
        else:
            naive_matrix_multiply_float(matrix_A, matrix_B, matrix_size)
        elapsed_time = time.time() - start_time
        print(f"{description}\nMatrix Multiplication of size {matrix_size} took {elapsed_time:.5f} seconds.\n")

    print("\n\n==================================\n\n")

def benchmark(matrix_size):
    run_tests(matrix_size)

benchmark(128)
benchmark(256)
benchmark(512)

