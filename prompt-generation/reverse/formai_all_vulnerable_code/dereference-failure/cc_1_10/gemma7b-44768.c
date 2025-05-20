//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char img[1024];
  printf("Enter image data (separate pixels with spaces): ");
  scanf("%s", img);

  int w, h;
  printf("Enter image width and height: ");
  scanf("%d %d", &w, &h);

  int pixel_size = w * h;
  char **ascii_art = (char **)malloc(pixel_size * sizeof(char *));

  for (int i = 0; i < pixel_size; i++)
  {
    ascii_art[i] = (char *)malloc(20 * sizeof(char));
  }

  int i = 0;
  for (int r = 0; r < h; r++)
  {
    for (int c = 0; c < w; c++)
    {
      int pixel_value = img[i] & 0xFF;
      ascii_art[i][0] = pixel_value / 16 + 'A';
      ascii_art[i][1] = pixel_value % 16 + 'A';
      i++;
    }
  }

  for (int i = 0; i < pixel_size; i++)
  {
    free(ascii_art[i]);
  }

  free(ascii_art);

  printf("ASCII art:\n");
  for (int r = 0; r < h; r++)
  {
    for (int c = 0; c < w; c++)
    {
      printf("%c ", ascii_art[r][c]);
    }
    printf("\n");
  }

  return 0;
}