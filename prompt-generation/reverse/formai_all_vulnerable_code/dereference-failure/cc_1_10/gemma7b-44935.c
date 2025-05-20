//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, m, k;
  scanf("Enter the number of rows and columns: ", &n);
  scanf("Enter the number of operations: ", &k);

  int **a = malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++)
  {
    a[i] = malloc(m * sizeof(int));
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      scanf("Enter the element at (%d, %d): ", &a[i][j]);
    }
  }

  for (int i = 0; i < k; i++)
  {
    int r, c, d;
    scanf("Enter the row, column, and direction (R/C/D): ", &r, &c, &d);

    switch (d)
    {
      case 0:
        a[r][c] = a[r][c] * 2;
        break;
      case 1:
        a[r][c] = a[r][c] - 1;
        break;
      case 2:
        a[r][c] = a[r][c] + 1;
        break;
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      printf("The element at (%d, %d) is: %d\n", i, j, a[i][j]);
    }
  }

  free(a);
  return 0;
}