//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 80

void draw_ascii_art(char **arr, int w, int h)
{
  int i, j;
  for (i = 0; i < h; i++)
  {
    for (j = 0; j < w; j++)
    {
      printf("%c ", arr[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  char **arr = NULL;
  int w = MAX_WIDTH;
  int h = 5;

  arr = malloc(h * w * sizeof(char));

  // Fill the array with ASCII art data
  arr[0][0] = 'H';
  arr[0][1] = 'O';
  arr[0][2] = 'R';
  arr[0][3] = 'A';
  arr[0][4] = 'C';

  arr[1][0] = 'S';
  arr[1][1] = 'O';
  arr[1][2] = 'M';
  arr[1][3] = 'E';
  arr[1][4] = 'R';

  arr[2][0] = 'A';
  arr[2][1] = 'R';
  arr[2][2] = 'C';
  arr[2][3] = 'H';
  arr[2][4] = 'A';

  arr[3][0] = 'N';
  arr[3][1] = 'E';
  arr[3][2] = 'R';
  arr[3][3] = 'G';
  arr[3][4] = 'A';

  arr[4][0] = 'M';
  arr[4][1] = 'A';
  arr[4][2] = 'R';
  arr[4][3] = 'C';
  arr[4][4] = 'H';

  draw_ascii_art(arr, w, h);

  free(arr);

  return 0;
}