//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

void draw_ascii_art(int argc, char *argv[])
{
  int height = 5;
  int width = 5;
  char **art = (char **)malloc(height * sizeof(char *) + height);
  for (int i = 0; i < height; i++)
  {
    art[i] = (char *)malloc(width * sizeof(char) + width);
  }
  art[0][0] = '+';
  art[0][1] = '+';
  art[0][2] = '+';
  art[0][3] = '+';
  art[0][4] = '+';
  art[1][0] = ' ';
  art[1][1] = ' ';
  art[1][2] = ' ';
  art[1][3] = ' ';
  art[1][4] = ' ';
  art[2][0] = ' ';
  art[2][1] = ' ';
  art[2][2] = ' ';
  art[2][3] = ' ';
  art[2][4] = ' ';
  art[3][0] = 'O';
  art[3][1] = 'O';
  art[3][2] = 'O';
  art[3][3] = 'O';
  art[3][4] = 'O';
  art[4][0] = '+';
  art[4][1] = '+';
  art[4][2] = '+';
  art[4][3] = '+';
  art[4][4] = '+';

  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      printf("%c ", art[i][j]);
    }
    printf("\n");
  }

  free(art);
}

int main()
{
  draw_ascii_art(0, NULL);
  return 0;
}