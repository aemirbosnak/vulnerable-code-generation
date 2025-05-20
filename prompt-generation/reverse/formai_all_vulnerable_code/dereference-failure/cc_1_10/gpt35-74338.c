//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef min
# define min(x,y) ((x) < (y) ? (x) : (y))
#endif

int levenshtein_distance(char *string1, char *string2) {
  int len1 = strlen(string1);
  int len2 = strlen(string2);
  int i, j, k;
  int dist, ins, del, sub, last;

  if (len1 == 0)
    return len2;
  else if (len2 == 0)
    return len1;

  int *costs = calloc(sizeof(int), len2 + 1);
  for (i = 0; i <= len2; i++)
    costs[i] = i;

  for (i = 0; i < len1; i++) {
    costs[0] = i + 1;
    last = i;
    for (j = 0; j < len2; j++) {
      if (string1[i] == string2[j]) {
        dist = last;
      } else {
        ins = costs[j] + 1;
        del = last + 1;
        sub = costs[j] + 1;
        dist = min(min(ins, del), sub);
      }
      last = costs[j];
      costs[j] = dist;
    }
    costs[len2] = last + 1;
  }

  int result = costs[len2];
  free(costs);
  return result;
}

int main() {
  char *s1 = "kitten";
  char *s2 = "sitting";
  int ld = levenshtein_distance(s1, s2);
  printf("%d\n", ld);
  return 0;
}