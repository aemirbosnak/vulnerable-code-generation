//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Levenshtein distance calculation function
int levenshtein(const char *s1, const char *s2) {
  // Initialize the distance matrix
  int m = strlen(s1) + 1;
  int n = strlen(s2) + 1;
  int **d = malloc(m * sizeof(int *));
  for (int i = 0; i < m; i++) {
    d[i] = malloc(n * sizeof(int));
  }

  // Initialize the first row and column of the distance matrix
  for (int i = 0; i < m; i++) {
    d[i][0] = i;
  }
  for (int j = 0; j < n; j++) {
    d[0][j] = j;
  }

  // Calculate the Levenshtein distance
  for (int j = 1; j < n; j++) {
    for (int i = 1; i < m; i++) {
      if (s1[i - 1] == s2[j - 1]) {
        d[i][j] = d[i - 1][j - 1];  // No cost for matching characters
      } else {
        d[i][j] = fmin(fmin(d[i - 1][j], d[i][j - 1]), d[i - 1][j - 1]) + 1;  // Cost for substitution, insertion, or deletion
      }
    }
  }

  // Return the Levenshtein distance
  int distance = d[m - 1][n - 1];
  for (int i = 0; i < m; i++) {
    free(d[i]);
  }
  free(d);
  return distance;
}

// Example usage
int main() {
  char *s1 = "kitten";
  char *s2 = "sitting";

  // Calculate the Levenshtein distance
  int distance = levenshtein(s1, s2);

  // Print the Levenshtein distance
  printf("The Levenshtein distance between \"%s\" and \"%s\" is %d\n", s1, s2, distance);

  return 0;
}