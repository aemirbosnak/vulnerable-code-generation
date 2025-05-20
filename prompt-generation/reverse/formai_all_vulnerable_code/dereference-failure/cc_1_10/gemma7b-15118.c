//Gemma-7B DATASET v1.0 Category: Data mining ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000

int main() {
  int i, j, k, lines = 0, n, m, **a = NULL, **b = NULL, **c = NULL;

  a = (int**)malloc(MAX_LINES * sizeof(int*));
  b = (int**)malloc(MAX_LINES * sizeof(int*));
  c = (int**)malloc(MAX_LINES * sizeof(int*));

  FILE *fp = fopen("data.txt", "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  char line[MAX_LINES];
  while (fgets(line, MAX_LINES, fp) != NULL) {
    lines++;
    a[lines - 1] = atoi(line);
  }

  fclose(fp);

  n = lines;
  m = lines / 2;

  for (i = 0; i < m; i++) {
    for (j = i + 1; j < n; j++) {
      for (k = 0; k < lines; k++) {
        if (a[k] > a[i] && a[k] < a[j]) {
          c[k] = 1;
        }
      }
    }
  }

  for (i = 0; i < lines; i++) {
    if (c[i] == 1) {
      printf("%d ", a[i]);
    }
  }

  printf("\n");

  free(a);
  free(b);
  free(c);

  return 0;
}