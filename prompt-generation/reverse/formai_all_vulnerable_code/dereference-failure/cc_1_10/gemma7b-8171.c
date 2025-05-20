//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void generate_ascii_art(int width, int height, char ***ascii_art)
{
  *ascii_art = malloc(height * sizeof(char *) + 1);
  for (int h = 0; h < height; h++)
  {
    (*ascii_art)[h] = malloc(width * sizeof(char) + 1);
    for (int w = 0; w < width; w++)
    {
      (*ascii_art)[h][w] = ' ';
    }
    (*ascii_art)[h][width] = '\0';
  }

  // Create the ASCII art
  (*ascii_art)[0][0] = '*';
  (*ascii_art)[0][1] = '*';
  (*ascii_art)[1][0] = '*';
  (*ascii_art)[1][1] = '*';
  (*ascii_art)[2][0] = '*';
  (*ascii_art)[2][1] = '*';

  // Print the ASCII art
  for (int h = 0; h < height; h++)
  {
    for (int w = 0; w < width; w++)
    {
      printf("%c", (*ascii_art)[h][w]);
    }
    printf("\n");
  }

  // Free the memory
  for (int h = 0; h < height; h++)
  {
    free((*ascii_art)[h]);
  }
  free(*ascii_art);
}

int main()
{
  int width = 5;
  int height = 3;
  char ***ascii_art;

  generate_ascii_art(width, height, &ascii_art);

  return 0;
}