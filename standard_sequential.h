#ifndef STANDARD_SEQUENTIAL_H
#define STANDARD_SEQUENTIAL_H

/*! \file standard_sequential.h
 *  \brief Header file for standard sequential matrix multiplication.
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
void standard_sequential_multiply(double *A, double *B, double *C, int m, int n, int p);

#endif // STANDARD_SEQUENTIAL_H