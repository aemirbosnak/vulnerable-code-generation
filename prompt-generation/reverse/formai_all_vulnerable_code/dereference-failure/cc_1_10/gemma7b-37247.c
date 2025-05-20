//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1024

void watermark(int **arr, int n, int w)
{
  int i, j, k;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < w; j++)
    {
      for (k = 0; k < MAX; k++)
      {
        if (arr[i][j] == k)
        {
          arr[i][j] = k + 1;
        }
      }
    }
  }
}

int main()
{
  int n, w;
  scanf("Enter the dimensions of the matrix: ", &n, &w);

  int **arr = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++)
  {
    arr[i] = (int *)malloc(w * sizeof(int));
  }

  printf("Enter the elements of the matrix: ");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < w; j++)
    {
      scanf("%d ", &arr[i][j]);
    }
  }

   watermark(arr, n, w);

  printf("The watermark embedded matrix is: ");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < w; j++)
    {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  free(arr);

  return 0;
}