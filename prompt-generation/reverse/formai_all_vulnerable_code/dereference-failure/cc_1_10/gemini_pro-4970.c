//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calculate the Levenshtein distance between two strings.
int levenshtein(char *s1, char *s2) {
  // Create a matrix to store the Levenshtein distances.
  int **matrix = malloc((strlen(s1) + 1) * sizeof(int *));
  for (int i = 0; i <= strlen(s1); i++) {
    matrix[i] = malloc((strlen(s2) + 1) * sizeof(int));
  }

  // Initialize the first row and column of the matrix.
  for (int i = 0; i <= strlen(s1); i++) {
    matrix[i][0] = i;
  }
  for (int j = 0; j <= strlen(s2); j++) {
    matrix[0][j] = j;
  }

  // Calculate the Levenshtein distances.
  for (int i = 1; i <= strlen(s1); i++) {
    for (int j = 1; j <= strlen(s2); j++) {
      int cost = s1[i - 1] == s2[j - 1] ? 0 : 1;
      matrix[i][j] = min(matrix[i - 1][j] + 1,  // Deletion
                           matrix[i][j - 1] + 1,  // Insertion
                           matrix[i - 1][j - 1] + cost);  // Substitution
    }
  }

  // Return the Levenshtein distance between the two strings.
  return matrix[strlen(s1)][strlen(s2)];
}

// Find the minimum of three integers.
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

// Print the usage information.
void usage() {
  printf("Usage: levenshtein <string1> <string2>\n");
  exit(1);
}

// Main function.
int main(int argc, char **argv) {
  if (argc != 3) {
    usage();
  }

  // Calculate the Levenshtein distance between the two strings.
  int distance = levenshtein(argv[1], argv[2]);

  // Print the Levenshtein distance.
  printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", argv[1], argv[2], distance);

  return 0;
}