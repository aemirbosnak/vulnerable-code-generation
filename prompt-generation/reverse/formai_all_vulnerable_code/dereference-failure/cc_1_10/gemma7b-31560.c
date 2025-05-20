//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imgToAscii(char **img, int w, int h)
{
  int i, j, k;
  char **ascii = malloc(h * sizeof(char *));
  for (i = 0; i < h; i++)
  {
    ascii[i] = malloc(w * sizeof(char));
  }

  for (i = 0; i < h; i++)
  {
    for (j = 0; j < w; j++)
    {
      int pixel = img[i][j];
      switch (pixel)
      {
        case 0:
          ascii[i][j] = ' ';
          break;
        case 1:
          ascii[i][j] = '.';
          break;
        case 2:
          ascii[i][j] = '#';
          break;
        default:
          ascii[i][j] = '=';
          break;
      }
    }
  }

  for (i = 0; i < h; i++)
  {
    free(ascii[i]);
  }
  free(ascii);

  return;
}

int main()
{
  char **img = malloc(5 * sizeof(char *));
  for (int i = 0; i < 5; i++)
  {
    img[i] = malloc(10 * sizeof(char));
  }

  img[0][0] = 1;
  img[0][1] = 2;
  img[0][2] = 1;
  img[0][3] = 2;
  img[0][4] = 1;

  img[1][0] = 2;
  img[1][1] = 1;
  img[1][2] = 2;
  img[1][3] = 1;
  img[1][4] = 2;

  imgToAscii(img, 10, 5);

  for (int i = 0; i < 5; i++)
  {
    free(img[i]);
  }
  free(img);

  return 0;
}