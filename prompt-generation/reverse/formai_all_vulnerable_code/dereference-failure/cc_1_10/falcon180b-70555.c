//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

/* Ada Lovelace style memory management program */

int main() {
  int *ptr;
  /* Allocate memory dynamically */
  ptr = (int *) malloc(10 * sizeof(int));
  if (ptr == NULL) {
    printf("Error: Memory allocation failed!\n");
    exit(1);
  }

  /* Initialize the allocated memory */
  for (int i = 0; i < 10; i++) {
    *ptr = i;
    ptr++;
  }

  /* Print the initialized memory */
  printf("Initialized memory:\n");
  for (int i = 0; i < 10; i++) {
    printf("%d ", *(ptr - i));
  }
  printf("\n");

  /* Reallocate memory dynamically */
  ptr = (int *) realloc(ptr, 20 * sizeof(int));
  if (ptr == NULL) {
    printf("Error: Memory reallocation failed!\n");
    exit(1);
  }

  /* Initialize the newly allocated memory */
  for (int i = 10; i < 20; i++) {
    *ptr = i;
    ptr++;
  }

  /* Print the reallocated memory */
  printf("Reallocated memory:\n");
  for (int i = 0; i < 20; i++) {
    printf("%d ", *(ptr - i));
  }
  printf("\n");

  /* Free the dynamically allocated memory */
  free(ptr);

  return 0;
}