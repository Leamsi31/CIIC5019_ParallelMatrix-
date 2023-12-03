#ifndef TRANSPOSED_PARALLEL_H
#define TRANSPOSED_PARALLEL_H

#include "transpose.h"
#include "stdlib.h"
#include "omp.h"

/**
 * @file transposed_parallel.h
 * @brief Header file for transposed parallel matrix multiplication.
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
void transposed_parallel_multiply(double *A, double *B, double *C, int m, int n, int p);

#endif /* TRANSPOSED_PARALLEL_H */

