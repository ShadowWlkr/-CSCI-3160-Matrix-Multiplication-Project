public class Java_Basic_Imp {
    
    public static float[][] matrixMultiply(float[][] A, float[][] B, int size) {
        float[][] C = new float[size][size];
        
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                C[i][j] = 0;
                for (int k = 0; k < size; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        
        return C;
    }
    
    public static void printMatrix(float[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int[] sizes = {128, 256, 512};
        
        for (int size : sizes) {
            float[][] A = new float[size][size];
            float[][] B = new float[size][size];
            
            // Initialize multiplicand matrices
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    A[i][j] = i + j + 1;
                }
            }
            
            // Initialize multiplier matrices
            // Identity matrix
            for (int i = 0; i < size; i++) {
                B[i][i] = 1;
            }
            
            System.out.println("Matrix A:");
            printMatrix(A);
            System.out.println("Matrix B (Identity):");
            printMatrix(B);
            
            float[][] result = matrixMultiply(A, B, size);
            System.out.println("Result:");
            printMatrix(result);
        }
    }
}
