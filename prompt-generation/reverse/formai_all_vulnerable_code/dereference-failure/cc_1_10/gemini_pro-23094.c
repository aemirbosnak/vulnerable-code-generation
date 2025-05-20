//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int levenshtein(char *s, char *t) {
  int m = strlen(s);
  int n = strlen(t);

  int **d = malloc((m + 1) * sizeof(int *));
  for (int i = 0; i <= m; i++) {
    d[i] = malloc((n + 1) * sizeof(int));
  }

  for (int i = 0; i <= m; i++) {
    d[i][0] = i;
  }

  for (int j = 0; j <= n; j++) {
    d[0][j] = j;
  }

  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= m; i++) {
      int cost = (s[i - 1] == t[j - 1]) ? 0 : 1;
      d[i][j] = MIN(MIN(d[i - 1][j] + 1, d[i][j - 1] + 1), d[i - 1][j - 1] + cost);
    }
  }

  int result = d[m][n];

  for (int i = 0; i <= m; i++) {
    free(d[i]);
  }
  free(d);

  return result;
}

int main() {
  char s[] = "kitten";
  char t[] = "sitting";

  int distance = levenshtein(s, t);

  printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s, t, distance);

  return 0;
}