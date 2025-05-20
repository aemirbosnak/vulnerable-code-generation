//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Levenshtein distance is a measure of the similarity between two strings.
// It is defined as the minimum number of edits (insertions, deletions, or substitutions)
// required to transform one string into the other.

// This function calculates the Levenshtein distance between two strings.
int levenshtein_distance(const char *s1, const char *s2) {
  // Create a matrix to store the Levenshtein distances between the prefixes of s1 and s2.
  int n = strlen(s1);
  int m = strlen(s2);
  int matrix[n + 1][m + 1];

  // Initialize the first row and column of the matrix.
  for (int i = 0; i <= n; i++) {
    matrix[i][0] = i;
  }
  for (int j = 0; j <= m; j++) {
    matrix[0][j] = j;
  }

  // Calculate the Levenshtein distances for the remaining cells of the matrix.
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
      matrix[i][j] = min(matrix[i - 1][j] + 1,  // Deletion
                            min(matrix[i][j - 1] + 1,  // Insertion
                                 matrix[i - 1][j - 1] + cost));  // Substitution
    }
  }

  // Return the Levenshtein distance between the two strings.
  return matrix[n][m];
}

// This function finds the minimum of three integers.
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

// This is a simple test program.
int main() {
  // Calculate the Levenshtein distance between two strings.
  int distance = levenshtein_distance("kitten", "sitting");

  // Print the Levenshtein distance.
  printf("The Levenshtein distance between \"kitten\" and \"sitting\" is %d.\n", distance);

  return 0;
}