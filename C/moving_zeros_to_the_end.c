// Write an algorithm that takes an array and moves all of the
// zeros to the end, preserving the order of the other elements.
//
// move_zeros(10, int [] {1, 2, 0, 1, 0, 1, 0, 3, 0, 1}); // -> int [] {1, 2, 1,
// 1, 3, 1, 0, 0, 0, 0}

#include <stddef.h>
#include <stdio.h>

// first attempt
void move_zeros(size_t len, int arr[len]) {
  int sentry = 0;
  for (size_t i = 0; i < len; i++) {
    if (arr[i] != 0) {
      arr[sentry] = arr[i];
      sentry++;
    }
  }

  for (size_t i = sentry; i < len; i++) {
    arr[i] = 0;
  }
}

// 2nd attempt, better, single pass
void move_zeroes_2(size_t len, int arr[len]) {
  int sentry = 0;
  for (size_t i = 0; i < len; i++) {
    if (arr[i] != 0) {
      // swap only if i is different than sentry
      // this means
      if (i != sentry) {
        int temp = arr[i];
        arr[i] = arr[sentry];
        arr[sentry] = temp;
      }
      sentry++;
    }
  }
}
