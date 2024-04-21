public class Java_Basic_Imp {
    public static int[][] createMatrixA(int size, int type) {
        int[][] A = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                switch (type) {
                    case 1: // All 1s
                        A[i][j] = 1;
                        break;
                    case 2: // All 2s
                        A[i][j] = 2;
                        break;
                    default: // Increment by 1
                        A[i][j] = i + j + 1;
                        break;
                }
            }
        }
        return A;
    }

    public static int[][] createMatrixB(int size, int type) {
        int[][] B = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                switch (type) {
                    case 1: // All 1s
                        B[i][j] = 1;
                        break;
                    case 2: // All 2s
                        B[i][j] = 2;
                        break;
                    default: // Identity matrix
                        B[i][j] = (i == j) ? 1 : 0;
                        break;
                }
            }
        }
        return B;
    }

    public static void matrixMultiply(int[][] A, int[][] B, int size, String caseDescription, int runs) {
        int[][] C = new int[size][size];
        long startTime = System.nanoTime();
        
        for (int r = 0; r < runs; r++) {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    C[i][j] = 0;
                    for (int k = 0; k < size; k++) {
                        C[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
        }
        
        long endTime = System.nanoTime();
        long durationNano = endTime - startTime;
        double durationMilli = Math.round((durationNano / 1e6) * 1000) / 1000.0;
        double durationSec = Math.round((durationMilli / 1e3) * 1000) / 1000.0;
        System.out.println("Runs:" + runs);
        System.out.println("Execution time in milliseconds: " + durationMilli);
        System.out.println("Execution time in seconds: " + durationSec);
        System.out.println();
    }

    public static void main(String[] args) {
        int[] sizes = {128, 256, 512};
        String[] caseDescriptionsA = {"Increment by 1", "All 1s", "All 2s"};
        String[] caseDescriptionsB = {"Identity matrix", "All 1s", "All 2s"};
        int[] runs = {1, 5, 10, 20};

        for (int size : sizes) {
            for (int type = 0; type < 3; type++) {
                int[][] A = createMatrixA(size, type);
                int[][] B = createMatrixB(size, type);
                String caseDescription = "Matrix A (" + caseDescriptionsA[type] + "), Matrix B (" + caseDescriptionsB[type] + ")";
                System.out.println("Case: " + caseDescription);
                System.out.println("Size: " + size + "x" + size + "\n");
                for (int run : runs) {
                    matrixMultiply(A, B, size, caseDescription, run);
                }
                System.out.println("\n======================================\n");
            }
        }
    }
}
