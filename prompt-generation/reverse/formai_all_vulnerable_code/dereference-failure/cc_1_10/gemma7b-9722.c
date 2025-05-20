//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX 118

void display_periodic_table(int **arr, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < MAX; j++)
    {
      if (arr[i][j] != 0)
      {
        printf("%c ", arr[i][j]);
      }
      else
      {
        printf("  ");
      }
    }

    printf("\n");
  }
}

int main()
{
  int **arr = NULL;
  int n = 0;

  printf("Enter the number of rows in the periodic table: ");
  scanf("%d", &n);

  arr = (int **)malloc(n * MAX * sizeof(int));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < MAX; j++)
    {
      arr[i][j] = 0;
    }
  }

  printf("Enter the data for the periodic table: ");

  display_periodic_table(arr, n);

  free(arr);

  return 0;
}