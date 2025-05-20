//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*
 * Levenshtein Distance Calculator
 *
 * Usage:
 *   ./levenshtein <string1> <string2>
 *
 * Example:
 *   ./levenshtein hello world
 *   3
 */
int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <string1> <string2>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the length of the strings
  int len1 = strlen(argv[1]);
  int len2 = strlen(argv[2]);

  // Create a matrix to store the Levenshtein distances
  int matrix[len1 + 1][len2 + 1];

  // Initialize the first row and column of the matrix
  for (int i = 0; i <= len1; i++) {
    matrix[i][0] = i;
  }
  for (int j = 0; j <= len2; j++) {
    matrix[0][j] = j;
  }

  // Calculate the Levenshtein distances
  for (int i = 1; i <= len1; i++) {
    for (int j = 1; j <= len2; j++) {
      int cost = (argv[1][i - 1] == argv[2][j - 1]) ? 0 : 1;
      matrix[i][j] = min(
          matrix[i - 1][j] + 1, // Deletion
          matrix[i][j - 1] + 1, // Insertion
          matrix[i - 1][j - 1] + cost // Substitution
      );
    }
  }

  // Print the Levenshtein distance
  printf("%d\n", matrix[len1][len2]);

  return EXIT_SUCCESS;
}

// Helper function to find the minimum of three integers
int min(int a, int b, int c) {
  int min = a;
  if (b < min) {
    min = b;
  }
  if (c < min) {
    min = c;
  }
  return min;
}