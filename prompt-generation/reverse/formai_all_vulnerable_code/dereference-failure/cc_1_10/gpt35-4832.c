//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int x, int y, int z) {
  if (x <= y && x <= z)
    return x;
  else if (y <= x && y <= z)
    return y;
  else
    return z;
}

int distance(char* s1, char* s2, int len1, int len2) {
  int cost;
  int **d = malloc((len1 + 1) * sizeof(int *));
  for (int i = 0; i <= len1; i++)
    d[i] = malloc((len2 + 1) * sizeof(int));

  for (int i = 0; i <= len1; i++)
    d[i][0] = i;

  for (int j = 0; j <= len2; j++)
    d[0][j] = j;

  for (int i = 1; i <= len1; i++) {
    for (int j = 1; j <= len2; j++) {
      if (s1[i - 1] == s2[j - 1])
        cost = 0;
      else
        cost = 1;

      d[i][j] = min(d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + cost);
    }
  }

  int result = d[len1][len2];
  for (int i = 0; i <= len1; i++)
    free(d[i]);
  free(d);
  return result;
}

int main() {
  char s1[] = "Hello World";
  char s2[] = "Halo Wold";
  int len1 = strlen(s1);
  int len2 = strlen(s2);
  int dist = distance(s1, s2, len1, len2);
  printf("The Levenshtein distance between '%s' and '%s' is %d\n", s1, s2, dist);

  return 0;
}