//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// A function to swap two elements
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// A function to print an array
void print_array(int *array, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

// A function to sort an array using the Knuth-Morris-Pratt algorithm
void knuth_morris_pratt(int *array, int size) {
  int *lps = malloc(size * sizeof(int));

  // Preprocess the pattern (calculate lps[] array)
  lps[0] = 0;
  int len = 0;
  int i = 1;
  while (i < size) {
    if (array[i] == array[len]) {
      len++;
      lps[i] = len;
      i++;
    } else {
      if (len != 0) {
        len = lps[len - 1];
      } else {
        lps[i] = 0;
        i++;
      }
    }
  }

  // Find the pattern in the text
  int j = 0;
  i = 0;
  while (i < size) {
    if (array[i] == array[j]) {
      i++;
      j++;
    }

    if (j == size) {
      printf("Pattern found at index %d\n", i - j);
      j = lps[j - 1];
    } else if (i < size && array[i] != array[j]) {
      if (j != 0) {
        j = lps[j - 1];
      } else {
        i++;
      }
    }
  }

  free(lps);
}

int main() {
  int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int size = sizeof(array) / sizeof(array[0]);

  print_array(array, size);
  knuth_morris_pratt(array, size);

  return 0;
}