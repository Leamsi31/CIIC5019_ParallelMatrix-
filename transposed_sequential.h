#ifndef TRANSPOSED_SEQUENTIAL_H
#define TRANSPOSED_SEQUENTIAL_H

#include "transpose.h"
#include "stdlib.h"

/**
 * @brief Perform matrix multiplication with transposition in a sequential manner.
 *
 * This function transposes matrix B, then multiplies matrices A and transposed B sequentially,
 * and stores the result in matrix C.
 *
 * @param A Pointer to the first matrix (m x n).
 * @param B Pointer to the second matrix (n x p).
 * @param C Pointer to the resulting matrix (m x p).
 * @param m Number of rows in matrix A.
 * @param n Number of columns in matrix A (and rows in matrix B).
 * @param p Number of columns in matrix B.
 */
void transposed_sequential_multiply(double *A, double *B, double *C, int m, int n, int p);

#endif // TRANSPOSED_SEQUENTIAL_H
