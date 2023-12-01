#include "standard_sequential.h"

/*! \file standard_sequential.c
 *  \brief Implementation of standard sequential matrix multiplication.
 */

/*!
 *  \brief Perform standard sequential matrix multiplication.
 *
 *  This function multiplies matrices A and B and stores the result in matrix C.
 *
 *  \param A Pointer to the first matrix (m x n).
 *  \param B Pointer to the second matrix (n x p).
 *  \param C Pointer to the resulting matrix (m x p).
 *  \param m Number of rows in matrix A.
 *  \param n Number of columns in matrix A (and rows in matrix B).
 *  \param p Number of columns in matrix B.
 */
void standard_sequential_multiply(double *A, double *B, double *C, int m, int n, int p) 
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            double elementSum = 0.0;
            for (int k = 0; k < n; k++) {
                elementSum += A[i * n + k] * B[k * p + j];
            }
            C[i * p + j] = elementSum;
        }
    }
}