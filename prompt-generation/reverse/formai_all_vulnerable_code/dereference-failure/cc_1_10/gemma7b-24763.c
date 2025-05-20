//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: genius
#include <stdio.h>
#include <stdlib.h>

void traverse(int **arr, int n, int target) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i][j] == target) {
        printf("Target found at (%d, %d)\n", i, j);
        exit(0);
      }
    }
  }

  printf("Target not found\n");
  exit(1);
}

int main() {
  int n = 5;
  int target = 10;
  int **arr = (int **)malloc(n * sizeof(int *));
  arr[0] = (int *)malloc(n * sizeof(int));
  arr[1] = (int *)malloc(n * sizeof(int));
  arr[2] = (int *)malloc(n * sizeof(int));
  arr[3] = (int *)malloc(n * sizeof(int));
  arr[4] = (int *)malloc(n * sizeof(int));

  arr[0][0] = 1;
  arr[0][1] = 2;
  arr[0][2] = 3;
  arr[0][3] = 4;
  arr[0][4] = 5;

  arr[1][0] = 6;
  arr[1][1] = 7;
  arr[1][2] = 8;
  arr[1][3] = 9;
  arr[1][4] = 10;

  arr[2][0] = 11;
  arr[2][1] = 12;
  arr[2][2] = 13;
  arr[2][3] = 14;
  arr[2][4] = 15;

  arr[3][0] = 16;
  arr[3][1] = 17;
  arr[3][2] = 18;
  arr[3][3] = 19;
  arr[3][4] = 20;

  arr[4][0] = 21;
  arr[4][1] = 22;
  arr[4][2] = 23;
  arr[4][3] = 24;
  arr[4][4] = 25;

  traverse(arr, n, target);

  return 0;
}