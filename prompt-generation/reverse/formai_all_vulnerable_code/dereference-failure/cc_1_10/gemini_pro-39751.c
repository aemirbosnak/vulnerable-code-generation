//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(x, y) (((x) < (y)) ? (x) : (y))

int levenshtein(char *s1, char *s2) {
  int **matrix;
  int s1_len = strlen(s1);
  int s2_len = strlen(s2);
  int i, j;

  matrix = malloc(sizeof(int *) * (s1_len + 1));
  for (i = 0; i <= s1_len; i++) {
    matrix[i] = malloc(sizeof(int) * (s2_len + 1));
  }

  for (i = 0; i <= s1_len; i++) {
    matrix[i][0] = i;
  }
  for (j = 0; j <= s2_len; j++) {
    matrix[0][j] = j;
  }

  for (i = 1; i <= s1_len; i++) {
    for (j = 1; j <= s2_len; j++) {
      int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
      int del = matrix[i - 1][j] + 1;
      int ins = matrix[i][j - 1] + 1;
      int sub = matrix[i - 1][j - 1] + cost;
      matrix[i][j] = min(del, min(ins, sub));
    }
  }

  int distance = matrix[s1_len][s2_len];

  for (i = 0; i <= s1_len; i++) {
    free(matrix[i]);
  }
  free(matrix);

  return distance;
}

int main() {
  char *s1 = "Wherefore art thou, Romeo?";
  char *s2 = "Call me but love, and I'll be new baptiz'd";

  int distance = levenshtein(s1, s2);
  printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, distance);

  return 0;
}