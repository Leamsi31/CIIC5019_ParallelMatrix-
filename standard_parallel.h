#ifndef STANDARD_PARALLEL_H
#define STANDARD_PARALLEL_H

/**
 * @brief Perform parallel standard matrix multiplication.
 * 
 * This function multiplies matrices A and B and stores the result in matrix C in parallel.
 * 
 * @param A Pointer to the first matrix (m x n).
 * @param B Pointer to the second matrix (n x p).
 * @param C Pointer to the resulting matrix (m x p).
 * @param m Number of rows in matrix A.
 * @param n Number of columns in matrix A (and rows in matrix B).
 * @param p Number of columns in matrix B.
 */
void standard_parallel_multiply(double *A, double *B, double *C, int m, int n, int p);

#endif  // STANDARD_PARALLEL_H
