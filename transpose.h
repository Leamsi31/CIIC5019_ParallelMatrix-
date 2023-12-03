#ifndef TRANSPOSE_H
#define TRANSPOSE_H

/**
 * @file transpose.h
 * @brief Header file for matrix transpose operation.
 */

/**
 * @brief Perform matrix transpose.
 * 
 * This function transposes matrix A and stores the result in matrix B.
 * 
 * @param A Matrix to be transposed.
 * @param B Resulting transposed matrix.
 * @param m Number of rows in matrix A.
 * @param n Number of columns in matrix A (and rows in matrix B).
 */
void transpose(double *A, double *B, int m, int n);

#endif // TRANSPOSE_H
