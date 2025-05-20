//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

void cluster(int **arr, int n, int k) {
  int i, j, d, minDist, clusterSize, center[k];
  for (i = 0; i < k; i++) {
    center[i] = rand() % n;
  }

  for (i = 0; i < n; i++) {
    minDist = MAX;
    for (j = 0; j < k; j++) {
      d = abs(arr[i] - center[j]);
      if (d < minDist) {
        minDist = d;
      }
    }

    arr[i] = clusterSize = minDist;
  }

  for (i = 0; i < k; i++) {
    printf("Center %d: %d\n", i, center[i]);
  }

  for (i = 0; i < n; i++) {
    printf("Point %d: %d\n", i, arr[i]);
  }
}

int main() {
  int n, k, **arr;
  printf("Enter the number of points: ");
  scanf("%d", &n);

  printf("Enter the number of clusters: ");
  scanf("%d", &k);

  arr = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    arr[i] = rand() % MAX;
  }

  cluster(arr, n, k);

  return 0;
}