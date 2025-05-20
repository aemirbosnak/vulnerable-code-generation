//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

void cluster(int **arr, int n, int k) {
  int i, j, l, d, h;
  int **distance = (int *)malloc(n * n * sizeof(int));
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      distance[i][j] = abs(arr[i] - arr[j]);
    }
  }
  h = 0;
  for (l = 0; l < k; l++) {
    int center = -1;
    int min_distance = MAX;
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (distance[i][j] < min_distance) {
          center = i;
          min_distance = distance[i][j];
        }
      }
    }
    arr[center] = h++;
  }
  free(distance);
}

int main() {
  int n, k;
  scanf("Enter the number of data points: ", &n);
  scanf("Enter the number of clusters: ", &k);

  int **arr = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    scanf("Enter the data point: ", &arr[i]);
  }

  cluster(arr, n, k);

  printf("The clusters are:\n");
  for (int i = 0; i < n; i++) {
    printf("Data point %d is in cluster %d\n", arr[i], i);
  }

  free(arr);
  return 0;
}