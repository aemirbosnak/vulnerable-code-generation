//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Initialize the variables
  int n, m, i, j, k;
  scanf("%d %d", &n, &m);
  int a[n][m];
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  // Sort the rows of the matrix in ascending order
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      for (k = j + 1; k < m; k++) {
        if (a[i][j] > a[i][k]) {
          int temp = a[i][j];
          a[i][j] = a[i][k];
          a[i][k] = temp;
        }
      }
    }
  }

  // Sort the columns of the matrix in ascending order
  for (j = 0; j < m; j++) {
    for (i = 0; i < n; i++) {
      for (k = i + 1; k < n; k++) {
        if (a[i][j] > a[k][j]) {
          int temp = a[i][j];
          a[i][j] = a[k][j];
          a[k][j] = temp;
        }
      }
    }
  }

  // Print the sorted matrix
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }

  return 0;
}