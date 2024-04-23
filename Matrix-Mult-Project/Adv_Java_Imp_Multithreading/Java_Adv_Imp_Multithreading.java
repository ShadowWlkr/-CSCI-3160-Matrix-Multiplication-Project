import java.io.FileWriter;
import java.io.IOException;

public class Java_Adv_Imp_Multithreading {
    // Method to create an integer matrixA with specified size and type
    public static int[][] createIntMatrixA(int size, int type) {
        int[][] A = new int[size][size];
        int num = 1;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                switch (type) {
                    case 0: // All 1s
                        A[i][j] = 1;
                        break;
                    case 1: // All 2s
                        A[i][j] = 2;
                        break;
                    case 2: // Increment by 1
                        A[i][j] = num++;
                        break;
                }
            }
        }
        return A;
    }

    // Method to create an integer matrixB with specified size and type
    public static int[][] createIntMatrixB(int size, int type) {
        int[][] B = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                switch (type) {
                    case 0: // All 1s
                        B[i][j] = 1;
                        break;
                    case 1: // All 2s
                        B[i][j] = 2;
                        break;
                    case 2: // Identity matrix
                        B[i][j] = (i == j) ? 1 : 0;
                        break;
                }
            }
        }
        return B;
    }

    // Method to create an float matrixA with specified size and type
    public static float[][] createFloatMatrixA(int size, int type) {
        float[][] A = new float[size][size];
        float num = 1.0f;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                switch (type) {
                    case 0: // All 1s
                        A[i][j] = 1.0f;
                        break;
                    case 1: // All 2s
                        A[i][j] = 2.0f;
                        break;
                    case 2: // Increment by 1
                        A[i][j] = num++;
                        break;
                }
            }
        }
        return A;
    }

    // Method to create an float matrixB with specified size and type
    public static float[][] createFloatMatrixB(int size, int type) {
        float[][] B = new float[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                switch (type) {
                    case 0: // All 1s
                        B[i][j] = 1.0f;
                        break;
                    case 1: // All 2s
                        B[i][j] = 2.0f;
                        break;
                    case 2: // Identity matrix
                        B[i][j] = (i == j) ? 1.0f : 0.0f;
                        break;
                }
            }
        }
        return B;
    }

    // Method to multiply integer matrices A and B and write the result to a txt file based on each test case
    public static void matrixMultiplyInt(int[][] A, int[][] B, int size, String caseDescription, int runs) {
         long startTime = System.nanoTime(); // Timer start, used later in calculations
        String fileName = "product_matrix_int_" + caseDescription + "_" + size + ".txt"; // File name created unique to each case

        try (FileWriter writer = new FileWriter(fileName)) { // Try catch for creation of file after every new test case
            for (int r = 0; r < runs; r++) { // Runs used to benchmark every 1, 5, 10, 20 times
                int[][] result = new int[size][size];
                Thread[] threads = new Thread[size]; 
                for (int i = 0; i < size; i++) {
                    final int row = i;
                    threads[i] = new Thread(() -> { // Create a new thread to handle matrix multiplication
                        for (int j = 0; j < size; j++) {
                            for (int k = 0; k < size; k++) {
                                result[row][j] += A[row][k] * B[k][j];
                            }
                        }
                    });
                    threads[i].start();
                }
                for (int i = 0; i < size; i++) { // Ensure all threads complete before proceeding
                    threads[i].join();
                }
                for (int[] row : result) { // Write result to file
                    for (int num : row) {
                        writer.append(Integer.toString(num));
                        writer.append(",");
                    }
                    writer.append("\n");
                }
            }
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }

        // Calculates time taken
        long endTime = System.nanoTime();
        double durationMilli = Math.round((endTime - startTime) / (double) runs / 1e6 * 1000.0) / 1000.0;
        double durationSec = Math.round(durationMilli / 1000.0 * 1000.0) / 1000.0;

        // Prints time taken
        System.out.println("Runs: " + runs);
        System.out.println("Execution time in milliseconds: " + durationMilli);
        System.out.println("Execution time in seconds: " + durationSec);
        System.out.println();
    }

    // Method to multiply integer matrices A and B and write the result to a txt file based on each test case
    public static void matrixMultiplyFloat(float[][] A, float[][] B, int size, String caseDescription, int runs) {
        long startTime = System.nanoTime(); // Timer start, used later in calculations
        String fileName = "product_matrix_float_" + caseDescription + "_" + size + ".txt"; // File name created unique to each case

        try (FileWriter writer = new FileWriter(fileName)) { // Try catch for creation of file after every new test case
            for (int r = 0; r < runs; r++) { // Runs used to benchmark every 1, 5, 10, 20 times
                float[][] result = new float[size][size];
                Thread[] threads = new Thread[size];
                for (int i = 0; i < size; i++) {
                    final int row = i;
                    threads[i] = new Thread(() -> { // Create a new thread to handle matrix multiplication
                        for (int j = 0; j < size; j++) {
                            for (int k = 0; k < size; k++) {
                                result[row][j] += A[row][k] * B[k][j];
                            }
                        }
                    });
                    threads[i].start();
                }
                for (int i = 0; i < size; i++) { // Ensure all threads complete before proceeding
                    threads[i].join();
                }
                for (float[] row : result) { // Write result to file
                    for (float num : row) {
                        writer.append(Float.toString(num));
                        writer.append(",");
                    }
                    writer.append("\n");
                }
            }
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }

        // Calculates time taken
        long endTime = System.nanoTime();
        double durationMilli = Math.round((endTime - startTime) / (double) runs / 1e6 * 1000.0) / 1000.0;
        double durationSec = Math.round(durationMilli / 1000.0 * 1000.0) / 1000.0;

        // Prints time taken
        System.out.println("Runs: " + runs);
        System.out.println("Execution time in milliseconds: " + durationMilli);
        System.out.println("Execution time in seconds: " + durationSec);
        System.out.println();
    }

    // Main method to perform matrix multiplication for various sizes and types of matrices
    public static void main(String[] args) {
        int[] sizes = {128, 256, 512};
        String[] caseDescriptionsA = {"Increment by 1", "All 1s", "All 2s"};
        String[] caseDescriptionsB = {"Identity matrix", "All 1s", "All 2s"};
        int[] runs = {1, 5, 10, 20};

        // Loop through matrix sizes
        for (int size : sizes) {
            // Loop through types of matrix A
            for (int typeA = 0; typeA < 3; typeA++) {
                // Loop through types of matrix A
                for (int typeB = 0; typeB < 3; typeB++) {
                    // Create matrices A and B for both integer and float types
                    int[][] AInt = createIntMatrixA(size, typeA);
                    int[][] BInt = createIntMatrixB(size, typeB);
                    float[][] AFloat = createFloatMatrixA(size, typeA);
                    float[][] BFloat = createFloatMatrixB(size, typeB);
                    // Describe the current case
                    String caseDescription = "Matrix A (" + caseDescriptionsA[typeA] + "), Matrix B (" + caseDescriptionsB[typeB] + ")";
                    System.out.println("Case: " + caseDescription);
                    System.out.println("Size: " + size + "x" + size + "\n");
                    System.out.println("Integer Matrices:\n");
                    // Multiply integer matrices and measure execution time
                    for (int run : runs) {
                        matrixMultiplyInt(AInt, BInt, size, caseDescription, run);
                    }
                    System.out.println("===================\n");
                    System.out.println("Float Matrices:\n");
                    // Multiply float matrices and measure execution time
                    for (int run : runs) {
                        matrixMultiplyFloat(AFloat, BFloat, size, caseDescription, run);
                    }
                    System.out.println("======================================\n");
                }
            }
        }
        try {
            // Run a shell script after the matrix multiplications to order the txt files into corresponding directories
            Process process = Runtime.getRuntime().exec(new String[]{"./Txt_File_Manager.sh"});
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

