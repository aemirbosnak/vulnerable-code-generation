//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void generate_ascii_art(int size)
{
  int i, j, k;
  char **arr = (char **)malloc(size * sizeof(char *));
  for (i = 0; i < size; i++)
  {
    arr[i] = (char *)malloc(size * sizeof(char));
  }

  for (i = 0; i < size; i++)
  {
    for (j = 0; j < size; j++)
    {
      arr[i][j] = ' ';
    }
  }

  arr[0][0] = '*';
  arr[0][1] = '*';
  arr[1][0] = '*';
  arr[1][1] = '*';

  for (k = 0; k < size; k++)
  {
    for (i = 0; i < size; i++)
    {
      for (j = 0; j < size; j++)
      {
        printf("%c", arr[i][j]);
      }
      printf("\n");
    }
  }

  for (i = 0; i < size; i++)
  {
    free(arr[i]);
  }
  free(arr);
}

int main()
{
  generate_ascii_art(MAX_SIZE);

  return 0;
}