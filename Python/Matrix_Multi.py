import time

def matrix_multiply(A, B, size):
    C = [[0 for _ in range(size)] for _ in range(size)]
    
    for i in range(size):
        for j in range(size):
            for k in range(size):
                C[i][j] += A[i][k] * B[k][j]
    
    return C

def print_matrix(matrix):
    for row in matrix:
        print(" ".join(str(element) for element in row))

if __name__ == "__main__":
    sizes = [128, 256, 512]
    
    for size in sizes:
        # Multiplicand matrices
        A_ones = [[1 + j + size*i for j in range(size)] for i in range(size)]
        A_twos = [[2 + j + size*i for j in range(size)] for i in range(size)]
        
        # Multiplier matrices
        B_identity = [[1 if i == j else 0 for j in range(size)] for i in range(size)]
        B_ones = [[1 for _ in range(size)] for _ in range(size)]
        B_twos = [[2 for _ in range(size)] for _ in range(size)]
        
        multiplicand_matrices = [A_ones, A_twos]
        multiplier_matrices = [B_identity, B_ones, B_twos]
        
        for A in multiplicand_matrices:
            for B in multiplier_matrices:
                start_time = time.time()
                result = matrix_multiply(A, B, size)
                end_time = time.time()
                
                print("Size:", size, "x", size)
                print("Multiplicand matrix:")
                print_matrix(A)
                print("Multiplier matrix:")
                print_matrix(B)
                print("Result:")
                print_matrix(result)
                print("\n \n Execution time:", end_time - start_time, "seconds")
                print()
