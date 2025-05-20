//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Levenshtein distance is a measure of the similarity between two strings.
// It is defined as the minimum number of edits (insertions, deletions, or substitutions)
// required to transform one string into the other.

// This function calculates the Levenshtein distance between two strings.
int levenshtein(char *s1, char *s2) {
  // Create a matrix to store the Levenshtein distances.
  int m = strlen(s1) + 1;
  int n = strlen(s2) + 1;
  int d[m][n];

  // Initialize the first row and column of the matrix.
  for (int i = 0; i < m; i++) {
    d[i][0] = i;
  }
  for (int j = 0; j < n; j++) {
    d[0][j] = j;
  }

  // Calculate the Levenshtein distances.
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        d[i][j] = d[i - 1][j - 1];
      } else {
        d[i][j] = 1 + min(d[i - 1][j], min(d[i][j - 1], d[i - 1][j - 1]));
      }
    }
  }

  // Return the Levenshtein distance.
  return d[m - 1][n - 1];
}

// This function finds the minimum of three integers.
int min(int a, int b, int c) {
  if (a < b) {
    if (a < c) {
      return a;
    } else {
      return c;
    }
  } else {
    if (b < c) {
      return b;
    } else {
      return c;
    }
  }
}

// This is a simple test program.
int main() {
  char *s1 = "kitten";
  char *s2 = "sitting";

  // Calculate the Levenshtein distance between the two strings.
  int distance = levenshtein(s1, s2);

  // Print the Levenshtein distance.
  printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, distance);

  return 0;
}