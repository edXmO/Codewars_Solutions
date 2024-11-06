// Write a function that when given a number >= 0, returns an Array of ascending
// length subarrays.
//
// pyramid(0) => [ ]
// pyramid(1) => [ [1] ]
// pyramid(2) => [ [1], [1, 1] ]
// pyramid(3) => [ [1], [1, 1], [1, 1, 1] ]
// Note: the subarrays should be filled with 1s
//
// Subarrays should not overlap; this will be tested. Do not forget to
// de-allocate memory in free_pyramid(), this will be tested as well.

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int **pyramid(unsigned n) {
  int **pyramid = calloc(n, sizeof(int *));

  if (pyramid == NULL) {
    fprintf(stderr, "Allocation failure");
    exit(1);
  }

  if (n == 0) {
    return pyramid;
  };

  for (int i = 0; i < n; i++) {
    pyramid[i] = malloc(sizeof(int) * i + 1);
    if (pyramid[i] == NULL) {
      fprintf(stderr, "Allocation failure");
      exit(1);
    }

    for (int j = 0; j < i + 1; j++) {
      pyramid[i][j] = 1;
    }
  }

  return pyramid;
}

void free_pyramid(unsigned n, int *pyramid_array[n]) {
  for (int i = 0; i < n; i++) {
    free(pyramid_array[i]);
  }

  free(pyramid_array);
}
