//Gemma-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: future-proof
#include <stdio.h>
#include <string.h>

int levenshtein_distance(char *s, char *t)
{
  int m = strlen(s) + 1;
  int n = strlen(t) + 1;
  int d = 0;

  int **distance = (int *)malloc(m * n * sizeof(int));
  distance[0] = 0;
  distance[1] = 1;

  for (int i = 0; i < m; i++)
  {
    distance[i][0] = i;
  }

  for (int j = 0; j < n; j++)
  {
    distance[0][j] = j;
  }

  for (int i = 1; i < m; i++)
  {
    for (int j = 1; j < n; j++)
    {
      distance[i][j] = distance[i - 1][j] + 1;
      if (s[i - 1] == t[j - 1])
      {
        distance[i][j] = distance[i - 1][j - 1];
      }
    }
  }

  d = distance[m - 1][n - 1];

  free(distance);

  return d;
}

int main()
{
  char *s = "abc";
  char *t = "bcd";

  int distance = levenshtein_distance(s, t);

  printf("The Levenshtein distance between %s and %s is %d.\n", s, t, distance);

  return 0;
}