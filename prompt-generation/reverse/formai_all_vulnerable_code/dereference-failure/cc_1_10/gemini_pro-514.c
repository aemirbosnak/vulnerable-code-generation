//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A curious way to calculate the Levenshtein distance
int main(int argc, char *argv[]) {
  // Check if we have enough arguments
  if (argc < 3) {
    printf("Usage: %s string1 string2\n", argv[0]);
    return 1;
  }

  // Get the two strings
  char *string1 = argv[1];
  char *string2 = argv[2];

  // Create a matrix to store the Levenshtein distances
  int **matrix = malloc((strlen(string1) + 1) * sizeof(int *));
  for (int i = 0; i < strlen(string1) + 1; i++) {
    matrix[i] = malloc((strlen(string2) + 1) * sizeof(int));
  }

  // Initialize the first row and column of the matrix
  for (int i = 0; i < strlen(string1) + 1; i++) {
    matrix[i][0] = i;
  }
  for (int j = 0; j < strlen(string2) + 1; j++) {
    matrix[0][j] = j;
  }

  // Calculate the Levenshtein distances
  for (int i = 1; i < strlen(string1) + 1; i++) {
    for (int j = 1; j < strlen(string2) + 1; j++) {
      if (string1[i - 1] == string2[j - 1]) {
        matrix[i][j] = matrix[i - 1][j - 1];
      } else {
        matrix[i][j] = fmin(fmin(matrix[i - 1][j], matrix[i][j - 1]), matrix[i - 1][j - 1]) + 1;
      }
    }
  }

  // Print the Levenshtein distance
  printf("The Levenshtein distance between \"%s\" and \"%s\" is %d\n", string1, string2, matrix[strlen(string1)][strlen(string2)]);

  // Free the matrix
  for (int i = 0; i < strlen(string1) + 1; i++) {
    free(matrix[i]);
  }
  free(matrix);

  return 0;
}