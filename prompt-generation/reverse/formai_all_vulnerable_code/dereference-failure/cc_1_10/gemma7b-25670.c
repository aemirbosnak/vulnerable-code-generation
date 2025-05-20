//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 100

void draw_ascii_art(char **art, int w, int h)
{
  for (int y = 0; y < h; y++)
  {
    for (int x = 0; x < w; x++)
    {
      printf("%c ", art[y][x]);
    }
    printf("\n");
  }
}

int main()
{
  char **art = NULL;
  int w, h;

  printf("Enter the width of the ASCII art: ");
  scanf("%d", &w);

  printf("Enter the height of the ASCII art: ");
  scanf("%d", &h);

  art = malloc(h * sizeof(char *) + 1);
  for (int i = 0; i < h; i++)
  {
    art[i] = malloc(w * sizeof(char) + 1);
  }

  // Create the ASCII art
  art[0][0] = '*';
  art[0][1] = '*';
  art[0][2] = '*';
  art[1][0] = '=';
  art[1][1] = '=';
  art[1][2] = '=';
  art[2][0] = '*';
  art[2][1] = '*';
  art[2][2] = '*';

  draw_ascii_art(art, w, h);

  free(art);

  return 0;
}