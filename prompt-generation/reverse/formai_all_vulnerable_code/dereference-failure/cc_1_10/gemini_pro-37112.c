//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calculate the Levenshtein distance between two strings.
int levenshtein_distance(const char *s, const char *t) {
  // Create a matrix to store the distances.
  int **matrix = malloc((strlen(s) + 1) * sizeof(int *));
  for (int i = 0; i < strlen(s) + 1; i++) {
    matrix[i] = malloc((strlen(t) + 1) * sizeof(int));
  }

  // Initialize the first row and column of the matrix.
  for (int i = 0; i < strlen(s) + 1; i++) {
    matrix[i][0] = i;
  }
  for (int j = 0; j < strlen(t) + 1; j++) {
    matrix[0][j] = j;
  }

  // Calculate the distances for the rest of the matrix.
  for (int i = 1; i < strlen(s) + 1; i++) {
    for (int j = 1; j < strlen(t) + 1; j++) {
      int cost = (s[i - 1] != t[j - 1]) ? 1 : 0;
      matrix[i][j] = min(matrix[i - 1][j] + 1,
                           matrix[i][j - 1] + 1,
                           matrix[i - 1][j - 1] + cost);
    }
  }

  // Return the distance.
  return matrix[strlen(s)][strlen(t)];
}

// Free the memory allocated for the matrix.
void free_matrix(int **matrix, int rows) {
  for (int i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

// Print the matrix.
void print_matrix(int **matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

// Get the minimum of three integers.
int min(int a, int b, int c) {
  if (a < b && a < c) {
    return a;
  } else if (b < c) {
    return b;
  } else {
    return c;
  }
}

int main() {
  // Get the two strings from the user.
  char s[100], t[100];
  printf("Enter the first string: ");
  scanf("%s", s);
  printf("Enter the second string: ");
  scanf("%s", t);

  // Calculate the Levenshtein distance.
  int distance = levenshtein_distance(s, t);

  // Print the distance.
  printf("The Levenshtein distance between '%s' and '%s' is %d.\n", s, t, distance);

  return 0;
}