#include "standard_parallel.h"

/**
 * @file standard_parallel.c
 * @brief Parallel implementation of standard matrix multiplication code.
 */

/**
 * @brief Perform parallel standard matrix multiplication.
 * 
 * This function multiplies matrices A and B in parallel and stores the result in matrix C.
 * 
 * @param A Pointer to the first matrix (m x n).
 * @param B Pointer to the second matrix (n x p).
 * @param C Pointer to the resulting matrix (m x p).
 * @param m Number of rows in matrix A.
 * @param n Number of columns in matrix A (and rows in matrix B).
 * @param p Number of columns in matrix B.
 */
void standard_parallel_multiply(double *A, double *B, double *C, int m, int n, int p) 
{
    // #pragma omp parallel for private(j, k) shared(A, B, C, m, n, p) schedule(dynamic)
    #pragma omp parallel for
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            double dot = 0.0;
            for (int k = 0; k < n; k++) {
                dot += A[i * n + k] * B[k * p + j];
            }
            C[i * p + j] = dot;
        }
    }
}