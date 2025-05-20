//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void display(int **arr, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  int **arr = (int **)malloc(MAX * sizeof(int *));
  for (int i = 0; i < MAX; i++)
  {
    arr[i] = (int *)malloc(MAX * sizeof(int));
  }

  // Initialize the maze
  arr[0][0] = 1;
  arr[0][1] = 1;
  arr[1][0] = 1;
  arr[1][1] = 1;
  arr[1][2] = 1;
  arr[2][1] = 1;
  arr[2][2] = 1;
  arr[2][3] = 1;
  arr[3][2] = 1;
  arr[3][3] = 1;

  // Find the route
  int x = 0, y = 0, d = 0;
  arr[x][y] = 2;
  while (arr[x][y] != 3)
  {
    switch (d)
    {
      case 0:
        x++;
        break;
      case 1:
        y++;
        break;
      case 2:
        x--;
        break;
      case 3:
        y--;
        break;
    }

    if (arr[x][y] == 1)
    {
      arr[x][y] = 2;
    }
  }

  // Display the route
  display(arr, MAX);

  free(arr);

  return 0;
}