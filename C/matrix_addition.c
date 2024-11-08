// Description:
// Write a function that accepts two square matrices (N x N two dimensional
// arrays), and return the sum of the two. Both matrices being passed into the
// function will be of size N x N (square), containing only integers.
//
// How to sum two matrices:
//
// Take each cell [n][m] from the first matrix, and add it with the same [n][m]
// cell from the second matrix. This will be cell [n][m] of the solution matrix.
// (Except for C where solution matrix will be a 1d pseudo-multidimensional
// array).
//
// Visualization:
//
// |1 2 3|     |2 2 1|     |1+2 2+2 3+1|     |3 4 4|
// |3 2 1|  +  |3 2 3|  =  |3+3 2+2 1+3|  =  |6 4 4|
// |1 1 1|     |1 1 3|     |1+1 1+1 1+3|     |2 2 4|
//
// Example
// matrixAddition(
//   [ [1, 2, 3],
//     [3, 2, 1],
//     [1, 1, 1] ],
// //      +
//   [ [2, 2, 1],
//     [3, 2, 3],
//     [1, 1, 3] ] )
//
// // returns:
//   [ [3, 4, 4],
//     [6, 4, 4],
//     [2, 2, 4] ]
//

// ###### Notes

// ### Observations
// - In matrix addition we achieve the resulting matrix by
//  summing every A_ith,jth term from matrix A to every B_ith,jth term from
//  matrix B

// #### Constraints
// - Both matrices will be always square of size NxN (determined by n param)
// - The return value will be

#include <stdlib.h>

int *matrix_addition(size_t n, const int matrix_a[n][n],
                     const int matrix_b[n][n]) {
  int *result = malloc(n * n * sizeof(int));
  if (result == NULL) {
    return NULL;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      result[i * n + j] = matrix_a[i][j] + matrix_b[i][j];
    };
  };
  return result;
}
