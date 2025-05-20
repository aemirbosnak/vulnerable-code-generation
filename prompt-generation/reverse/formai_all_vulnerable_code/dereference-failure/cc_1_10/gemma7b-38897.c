//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void generate_qr_code(char *data)
{
  int i, j, k, l, n, m, r;
  n = strlen(data);
  m = n / 4;
  r = m / 2;
  k = n - 4 * r;
  int **arr = (int **)malloc(r * sizeof(int *) + 1);
  for (i = 0; i < r; i++)
  {
    arr[i] = (int *)malloc((m + 1) * sizeof(int));
  }

  for (i = 0; i < r; i++)
  {
    for (j = 0; j < m; j++)
    {
      arr[i][j] = 0;
    }
  }

  for (i = 0; i < n; i++)
  {
    l = i - k;
    if (l >= 0 && l < r)
    {
      arr[l][(i - l) / m] = 1;
    }
  }

  for (i = 0; i < r; i++)
  {
    for (j = 0; j < m; j++)
    {
      if (arr[i][j] == 1)
      {
        printf("X");
      }
      else
      {
        printf(".");
      }
    }
    printf("\n");
  }

  free(arr);
}

int main()
{
  char data[] = "This is a QR code";
  generate_qr_code(data);
  return 0;
}