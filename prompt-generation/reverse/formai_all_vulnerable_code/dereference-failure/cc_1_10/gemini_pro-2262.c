//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calculate the Levenshtein distance between two strings.
int levenshtein(const char *s1, const char *s2) {
  // Create a matrix to store the distances.
  int m = strlen(s1) + 1;
  int n = strlen(s2) + 1;
  int d[m][n];

  // Initialize the matrix.
  for (int i = 0; i < m; i++) {
    d[i][0] = i;
  }
  for (int j = 0; j < n; j++) {
    d[0][j] = j;
  }

  // Calculate the distances.
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
      d[i][j] = minimum(d[i - 1][j] + 1,  // Deletion
                        d[i][j - 1] + 1,  // Insertion
                        d[i - 1][j - 1] + cost);  // Substitution
    }
  }

  // Return the distance.
  return d[m - 1][n - 1];
}

// Find the minimum of three integers.
int minimum(int a, int b, int c) {
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

// Print usage information.
void usage() {
  printf("Usage: levenshtein <string1> <string2>\n");
}

// Main function.
int main(int argc, char *argv[]) {
  // Check the number of arguments.
  if (argc != 3) {
    usage();
    return 1;
  }

  // Get the strings.
  char *s1 = argv[1];
  char *s2 = argv[2];

  // Calculate the Levenshtein distance.
  int distance = levenshtein(s1, s2);

  // Print the distance.
  printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, distance);

  return 0;
}