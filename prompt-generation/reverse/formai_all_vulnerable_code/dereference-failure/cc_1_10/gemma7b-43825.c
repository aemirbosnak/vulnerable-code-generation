//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void draw_surreal_map(int **map, int w, int h)
{
  for (int y = 0; y < h; y++)
  {
    for (int x = 0; x < w; x++)
    {
      switch (map[y][x])
      {
        case 0:
          printf(" ");
          break;
        case 1:
          printf("O");
          break;
        case 2:
          printf("X");
          break;
        default:
          printf("%c", map[y][x] + 55);
          break;
      }
    }
    printf("\n");
  }
}

int main()
{
  int w = 10;
  int h = 10;
  int **map = NULL;

  map = (int **)malloc(h * sizeof(int *));
  for (int i = 0; i < h; i++)
  {
    map[i] = (int *)malloc(w * sizeof(int));
  }

  srand(time(NULL));

  for (int y = 0; y < h; y++)
  {
    for (int x = 0; x < w; x++)
    {
      map[y][x] = rand() % 3;
    }
  }

  draw_surreal_map(map, w, h);

  free(map);

  return 0;
}