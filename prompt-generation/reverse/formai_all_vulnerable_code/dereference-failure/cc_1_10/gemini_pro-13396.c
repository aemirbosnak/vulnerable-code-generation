//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int distance;
  char** alignment;
} LevenshteinResult;

LevenshteinResult levenshteinDistance(char* s1, char* s2) {
  int m = strlen(s1);
  int n = strlen(s2);

  // Create a matrix to store the Levenshtein distances
  int** matrix = malloc((m + 1) * sizeof(int*));
  for (int i = 0; i <= m; i++) {
    matrix[i] = malloc((n + 1) * sizeof(int));
  }

  // Initialize the first row and column of the matrix
  for (int i = 0; i <= m; i++) {
    matrix[i][0] = i;
  }
  for (int j = 0; j <= n; j++) {
    matrix[0][j] = j;
  }

  // Calculate the Levenshtein distance for each cell in the matrix
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
      matrix[i][j] = fmin(fmin(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1), matrix[i - 1][j - 1] + cost);
    }
  }

  // Traceback through the matrix to find the alignment of the strings
  int i = m;
  int j = n;
  int distance = matrix[m][n];
  char** alignment = malloc((distance + 1) * sizeof(char*));
  for (int k = distance; k >= 0; k--) {
    alignment[k] = malloc(2 * sizeof(char));
    if (i == 0) {
      alignment[k][0] = '-';
      alignment[k][1] = s2[j - 1];
      j--;
    } else if (j == 0) {
      alignment[k][0] = s1[i - 1];
      alignment[k][1] = '-';
      i--;
    } else if (matrix[i][j] == matrix[i - 1][j] + 1) {
      alignment[k][0] = s1[i - 1];
      alignment[k][1] = '-';
      i--;
    } else if (matrix[i][j] == matrix[i][j - 1] + 1) {
      alignment[k][0] = '-';
      alignment[k][1] = s2[j - 1];
      j--;
    } else {
      alignment[k][0] = s1[i - 1];
      alignment[k][1] = s2[j - 1];
      i--;
      j--;
    }
  }

  // Free the matrix
  for (int i = 0; i <= m; i++) {
    free(matrix[i]);
  }
  free(matrix);

  // Return the Levenshtein distance and the alignment
  LevenshteinResult result;
  result.distance = distance;
  result.alignment = alignment;
  return result;
}

int main() {
  // Get the input strings
  char s1[] = "kitten";
  char s2[] = "sitting";

  // Calculate the Levenshtein distance and alignment
  LevenshteinResult result = levenshteinDistance(s1, s2);

  // Print the results
  printf("The Levenshtein distance between '%s' and '%s' is %d.\n", s1, s2, result.distance);
  for (int i = 0; i < result.distance + 1; i++) {
    printf("%s\n", result.alignment[i]);
  }

  // Free the alignment
  for (int i = 0; i < result.distance + 1; i++) {
    free(result.alignment[i]);
  }
  free(result.alignment);

  return 0;
}