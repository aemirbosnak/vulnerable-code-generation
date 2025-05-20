//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 80

void draw_ascii_art(char **art, int w, int h)
{
  for (int r = 0; r < h; r++)
  {
    for (int c = 0; c < w; c++)
    {
      printf("%c ", art[r][c]);
    }
    printf("\n");
  }
}

int main()
{
  char **art = NULL;
  int w = MAX_WIDTH;
  int h = 5;

  art = (char **)malloc(h * sizeof(char *) + w * sizeof(char));
  for (int r = 0; r < h; r++)
  {
    art[r] = (char *)malloc(w * sizeof(char));
  }

  // Create ASCII art
  art[0][0] = '$';
  art[0][1] = ' ';
  art[0][2] = ' ';
  art[0][3] = '$';

  art[1][0] = ' ';
  art[1][1] = ' ';
  art[1][2] = '$';
  art[1][3] = ' ';

  art[2][0] = ' ';
  art[2][1] = '$';
  art[2][2] = '$';
  art[2][3] = ' ';

  art[3][0] = ' ';
  art[3][1] = ' ';
  art[3][2] = ' ';
  art[3][3] = '$';

  art[4][0] = '$';
  art[4][1] = ' ';
  art[4][2] = ' ';
  art[4][3] = '$';

  draw_ascii_art(art, w, h);

  free(art);

  return 0;
}