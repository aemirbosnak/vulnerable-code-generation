//Gemma-7B DATASET v1.0 Category: Performance-Critical Component ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cosmic_dance(char **galaxy, int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      if (galaxy[i][j] == 'S')
      {
        galaxy[i][j] = 'O';
      }
    }
  }
}

int main()
{
  char **galaxy;
  int size = 10;

  galaxy = (char **)malloc(size * size * sizeof(char));
  for (int i = 0; i < size; i++)
  {
    galaxy[i] = (char *)malloc(size * sizeof(char));
    for (int j = 0; j < size; j++)
    {
      galaxy[i][j] = '.';
    }
  }

  // Draw a spaceship in the center of the galaxy
  galaxy[5][5] = 'S';

  cosmic_dance(galaxy, size);

  // Print the updated galaxy
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      printf("%c ", galaxy[i][j]);
    }
    printf("\n");
  }

  free(galaxy);

  return 0;
}