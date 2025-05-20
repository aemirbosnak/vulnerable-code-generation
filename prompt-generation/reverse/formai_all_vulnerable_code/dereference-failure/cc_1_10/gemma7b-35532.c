//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10

void cluster(int **arr, int n, int k) {
  int i, j, l, d, minDist, clusterSize = 0, **distances = NULL;

  distances = (int *)malloc(n * sizeof(int));
  for (i = 0; i < n; i++) {
    distances[i] = MAX;
  }

  for (i = 0; i < n; i++) {
    for (j = i; j < n; j++) {
      d = abs(arr[i] - arr[j]);
      if (distances[j] > d) {
        distances[j] = d;
      }
    }
  }

  for (l = 0; l < k; l++) {
    minDist = MAX;
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (distances[i] == distances[j] && distances[i] != MAX) {
          if (minDist > distances[i]) {
            minDist = distances[i];
            clusterSize = 1;
          } else if (minDist == distances[i]) {
            clusterSize++;
          }
        }
      }
    }

    printf("Cluster %d: ", l + 1);
    for (i = 0; i < n; i++) {
      if (distances[i] == minDist) {
        printf("%d ", arr[i]);
      }
    }
    printf("\n");

    distances[clusterSize] = MAX;
  }

  free(distances);
}

int main() {
  int n, k;
  int **arr;

  printf("Enter the number of elements: ");
  scanf("%d", &n);

  arr = (int *)malloc(n * sizeof(int));

  printf("Enter the elements: ");
  for (k = 0; k < n; k++) {
    scanf("%d", &arr[k]);
  }

  printf("Enter the number of clusters: ");
  scanf("%d", &k);

  cluster(arr, n, k);

  return 0;
}