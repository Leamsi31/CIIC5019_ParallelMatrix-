#include "transposed_parallel.h"

/**
 * @file transposed_parallel.c
 * @brief Implementation of transposed parallel matrix multiplication.
 */

/**
 * @brief Perform transposed parallel matrix multiplication.
 * 
 * This function multiplies matrices A and B and stores the result in matrix C using parallelization.
 * 
 * @param A Pointer to the first matrix (m x n).
 * @param B Pointer to the second matrix (n x p).
 * @param C Pointer to the resulting matrix (m x p).
 * @param m Number of rows in matrix A.
 * @param n Number of columns in matrix A (and rows in matrix B).
 * @param p Number of columns in matrix B.
 */
void transposed_parallel_multiply(double *A, double *B, double *C, int m, int n, int p)
{	
    // Allocate memory for the transposed matrix
    double *B_transposed = (double*)malloc(sizeof(double) * n * p);

    // Transpose matrix B
    transpose(B, B_transposed, n, p);

    // Perform matrix multiplication with parallelization
    // #pragma omp parallel for private(j, k) shared(A, B_transposed, C, m, n, p) schedule(dynamic)
    #pragma omp parallel for
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            double dot = 0.0;
            for (int k = 0; k < n; k++) {
                dot += A[i * n + k] * B_transposed[j * n + k];
            }
            C[i * p + j] = dot;
        }
    }

    // Free allocated memory
    free(B_transposed);
}