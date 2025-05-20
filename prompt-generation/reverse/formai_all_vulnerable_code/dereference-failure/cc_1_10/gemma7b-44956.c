//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Ken Thompson
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX 100

int main() {
  int i, j, k, n, m, x, y;
  int **grid = NULL;
  int **flood = NULL;

  n = m = MAX;
  grid = (int **)malloc(n * sizeof(int *));
  flood = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    grid[i] = (int *)malloc(m * sizeof(int));
    flood[i] = (int *)malloc(m * sizeof(int));
  }

  x = y = 0;
  srand(time(NULL));
  for (k = 0; k < MAX; k++) {
    x = rand() % m;
    y = rand() % n;
    grid[y][x] = 1;
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      flood[i][j] = -1;
    }
  }

  flood[0][0] = 0;
  flood[0][1] = 0;
  flood[1][0] = 0;
  flood[1][1] = 0;

  for (k = 0; k < MAX; k++) {
    x = rand() % m;
    y = rand() % n;
    if (flood[y][x] == -1 && grid[y][x] == 1) {
      flood[y][x] = flood[y - 1][x] + 1;
    }
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("%d ", flood[i][j]);
    }
    printf("\n");
  }

  free(grid);
  free(flood);

  return 0;
}