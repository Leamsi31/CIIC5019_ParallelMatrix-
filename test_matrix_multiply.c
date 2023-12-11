#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "standard_sequential.h"
#include "standard_parallel.h"
#include "transposed_sequential.h"
#include "transposed_parallel.h"
#include "print_matrix.h"

/**
 * @file test_matrix_multiply.c
 * @brief Test program for matrix multiplication algorithms.
 */

/**
 * @brief Calculate speedup.
 * 
 * @param sequential_time Execution time of sequential algorithm.
 * @param parallel_time Execution time of parallel algorithm.
 * @return Speedup value.
 */
double calculate_speedup(double sequential_time, double parallel_time) {
    return sequential_time / parallel_time;
}

/**
 * @brief Calculate efficiency.
 * 
 * @param speedup Speedup value.
 * @param num_processors Number of processors used.
 * @return Efficiency value.
 */
double calculate_efficiency(double speedup, int num_processors) {
    return speedup / num_processors;
}

void test_matrix_multiplication(double *A, double *B, double *C, int m, int n, int p, void (*multiply_function)(double*, double*, double*, int, int, int), const char* algorithm_name, FILE *output_file) {
    double start_time = omp_get_wtime();
    multiply_function(A, B, C, m, n, p);
    double end_time = omp_get_wtime();
    
    // Print the result
    fprintf(output_file, "\n%s Result:\n", algorithm_name);
    fprintf(output_file, "m = %d, n = %d, p = %d\n", m, n, p);
    fprintf(output_file, "Execution Time (%s): %f seconds\n", algorithm_name, end_time - start_time);
}

/**
 * @brief Main function to test matrix multiplication algorithms.
 * 
 * @return Exit status.
 */
int main() {
    // Outputs results to a file named "matrix_multiplication_results.txt"
    FILE *output_file = fopen("matrix_multiplication_results.txt", "w");
    if (output_file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int start_size = 100;  // Rows of matrix A
    int end_size = 3000;
    int step_size = 100;
    
    for (int m = start_size; m <= end_size; m += step_size) {
        int n = m + 1;  // Columns of matrix A / Rows of matrix B
        int p = m + 2;  // Columns of matrix B

        // Allocate memory for matrices A, B, and C
        double *A = (double*)malloc(sizeof(double) * m * n);
        double *B = (double*)malloc(sizeof(double) * n * p);
        double *C = (double*)malloc(sizeof(double) * m * p);

        // Initialize matrices A and B (you can modify this part as needed)
        for (int i = 0; i < m * n; i++) A[i] = i + 1;
        for (int i = 0; i < n * p; i++) B[i] = i + 1;

        // Test standard sequential multiplication
        test_matrix_multiplication(A, B, C, m, n, p, standard_sequential_multiply, "Standard Sequential", output_file);

        // Test standard parallel multiplication
        test_matrix_multiplication(A, B, C, m, n, p, standard_parallel_multiply, "Standard Parallel", output_file);

        // Test transposed sequential multiplication
        test_matrix_multiplication(A, B, C, m, n, p, transposed_sequential_multiply, "Transposed Sequential", output_file);

        // Test transposed parallel multiplication
        test_matrix_multiplication(A, B, C, m, n, p, transposed_parallel_multiply, "Transposed Parallel", output_file);

        // Free allocated memory
        free(A);
        free(B);
        free(C);
    }

    fclose(output_file);

    return 0;
}
