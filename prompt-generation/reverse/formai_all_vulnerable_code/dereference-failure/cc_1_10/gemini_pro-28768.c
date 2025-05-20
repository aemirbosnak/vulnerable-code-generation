//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

// Cyberpunk style!
typedef struct {
  int dist;
  char *path;
} CyberpunkString;

CyberpunkString *
distance(char *a, char *b) {
  int len_a = strlen(a);
  int len_b = strlen(b);
  int **matrix = malloc(sizeof(int *) * (len_a + 1));
  for (int i = 0; i <= len_a; i++) {
    matrix[i] = malloc(sizeof(int) * (len_b + 1));
  }

  for (int i = 0; i <= len_a; i++) {
    matrix[i][0] = i;
  }
  for (int j = 0; j <= len_b; j++) {
    matrix[0][j] = j;
  }

  for (int i = 1; i <= len_a; i++) {
    for (int j = 1; j <= len_b; j++) {
      if (a[i - 1] == b[j - 1]) {
        matrix[i][j] = matrix[i - 1][j - 1];
      } else {
        matrix[i][j] = fmin(fmin(matrix[i - 1][j], matrix[i][j - 1]), matrix[i - 1][j - 1]) + 1;
      }
    }
  }

  // Backtrack to find the path
  int i = len_a;
  int j = len_b;
  char *path = malloc(sizeof(char) * (matrix[len_a][len_b] + 1));
  int path_len = matrix[len_a][len_b];
  while (i > 0 && j > 0) {
    if (a[i - 1] == b[j - 1]) {
      path[--path_len] = a[i - 1];
      i--;
      j--;
    } else if (matrix[i - 1][j] < matrix[i][j - 1] && matrix[i - 1][j] < matrix[i - 1][j - 1]) {
      path[--path_len] = a[i - 1];
      i--;
    } else if (matrix[i][j - 1] < matrix[i - 1][j] && matrix[i][j - 1] < matrix[i - 1][j - 1]) {
      path[--path_len] = b[j - 1];
      j--;
    } else {
      path[--path_len] = a[i - 1];
      i--;
      j--;
    }
  }
  path[path_len] = '\0';

  CyberpunkString *result = malloc(sizeof(CyberpunkString));
  result->dist = matrix[len_a][len_b];
  result->path = path;

  for (int i = 0; i <= len_a; i++) {
    free(matrix[i]);
  }
  free(matrix);

  return result;
}

int
main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s string1 string2\n", argv[0]);
    return 1;
  }

  CyberpunkString *result = distance(argv[1], argv[2]);

  printf("Levenshtein distance: %d\n", result->dist);
  if (result->dist != 0) {
    printf("Path: %s\n", result->path);
  }

  free(result->path);
  free(result);

  return 0;
}