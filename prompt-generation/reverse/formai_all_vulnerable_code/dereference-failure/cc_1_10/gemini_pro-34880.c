//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char *s, *p;
  int i, j, k;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s string\n", argv[0]);
    return 1;
  }

  s = argv[1];

  // Count the number of characters in the string
  i = 0;
  while (s[i] != '\0') {
    i++;
  }

  // Allocate an array of pointers to characters
  p = (char *)malloc(i * sizeof(char *));

  // Initialize the array of pointers to characters
  for (j = 0; j < i; j++) {
    p[j] = s + j;
  }

  // Sort the array of pointers to characters
  for (j = 0; j < i - 1; j++) {
    for (k = j + 1; k < i; k++) {
      if (strcmp(p[j], p[k]) > 0) {
        char *tmp = p[j];
        p[j] = p[k];
        p[k] = tmp;
      }
    }
  }

  // Print the sorted string
  for (j = 0; j < i; j++) {
    printf("%s", p[j]);
  }

  printf("\n");

  // Free the array of pointers to characters
  free(p);

  return 0;
}