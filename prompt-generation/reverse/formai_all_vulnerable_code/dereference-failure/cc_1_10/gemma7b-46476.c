//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: active
#include <stdio.h>
#include <stdlib.h>

void draw_ascii_art(int width, int height, char **arr)
{
  for (int r = 0; r < height; r++)
  {
    for (int c = 0; c < width; c++)
    {
      printf("%c ", arr[r][c]);
    }
    printf("\n");
  }
}

int main()
{
  char **arr = NULL;
  int w = 10, h = 5;

  arr = (char **)malloc(h * sizeof(char *) + h);
  for (int i = 0; i < h; i++)
  {
    arr[i] = (char *)malloc(w * sizeof(char) + w);
  }

  arr[0][0] = '$';
  arr[0][1] = '$';
  arr[0][2] = '$';
  arr[1][0] = ' ';
  arr[1][1] = ' ';
  arr[1][2] = ' ';
  arr[2][0] = '*';
  arr[2][1] = '*';
  arr[2][2] = '*';
  arr[3][0] = ' ';
  arr[3][1] = ' ';
  arr[3][2] = ' ';
  arr[4][0] = '#';
  arr[4][1] = '#';
  arr[4][2] = '#';

  draw_ascii_art(w, h, arr);

  for (int i = 0; i < h; i++)
  {
    free(arr[i]);
  }
  free(arr);

  return 0;
}