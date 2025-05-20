//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int uint;

// Levenshtein distance matrix
uint **matrix;

// Strings to compare
char *s1;
char *s2;

// Lengths of the strings
uint m;
uint n;

// Print the Levenshtein distance matrix
void print_matrix() {
  for (uint i = 0; i <= m; i++) {
    for (uint j = 0; j <= n; j++) {
      printf("%2u ", matrix[i][j]);
    }
    printf("\n");
  }
}

// Calculate the Levenshtein distance between two strings
uint levenshtein(char *s1, char *s2) {
  // Initialize the matrix
  matrix = (uint **)malloc((m + 1) * sizeof(uint *));
  for (uint i = 0; i <= m; i++) {
    matrix[i] = (uint *)malloc((n + 1) * sizeof(uint));
  }

  // Initialize the first row
  for (uint i = 0; i <= n; i++) {
    matrix[0][i] = i;
  }

  // Initialize the first column
  for (uint i = 0; i <= m; i++) {
    matrix[i][0] = i;
  }

  // Calculate the Levenshtein distance
  for (uint j = 1; j <= n; j++) {
    for (uint i = 1; i <= m; i++) {
      uint cost = (s1[i - 1] != s2[j - 1]);
      matrix[i][j] = fmin(matrix[i - 1][j] + 1,  // Deletion
                            fmin(matrix[i][j - 1] + 1,  // Insertion
                                  matrix[i - 1][j - 1] + cost));  // Substitution
    }
  }

  // Return the Levenshtein distance
  return matrix[m][n];
}

// Main function
int main(int argc, char **argv) {
  // Check the number of arguments
  if (argc != 3) {
    printf("Usage: %s <string1> <string2>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the strings from the command line
  s1 = argv[1];
  s2 = argv[2];

  // Get the lengths of the strings
  m = strlen(s1);
  n = strlen(s2);

  // Calculate the Levenshtein distance
  uint distance = levenshtein(s1, s2);

  // Print the Levenshtein distance
  printf("Levenshtein distance: %u\n", distance);

  // Free the memory allocated for the matrix
  for (uint i = 0; i <= m; i++) {
    free(matrix[i]);
  }
  free(matrix);

  return EXIT_SUCCESS;
}