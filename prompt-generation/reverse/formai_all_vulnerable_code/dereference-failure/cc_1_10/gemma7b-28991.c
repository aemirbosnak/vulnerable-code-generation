//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>

void generate_ascii_art(int width, int height, char **arr)
{
  int i, j;

  for (i = 0; i < height; i++)
  {
    for (j = 0; j < width; j++)
    {
      arr[i][j] = rand() % 26 + 65;
    }
  }

  for (i = 0; i < height; i++)
  {
    for (j = 0; j < width; j++)
    {
      printf("%c ", arr[i][j]);
    }

    printf("\n");
  }
}

int main()
{
  int width, height;

  printf("Enter the width of the ASCII art: ");
  scanf("%d", &width);

  printf("Enter the height of the ASCII art: ");
  scanf("%d", &height);

  char **arr = (char **)malloc(height * sizeof(char *) + 1);
  for (int i = 0; i < height; i++)
  {
    arr[i] = (char *)malloc(width * sizeof(char) + 1);
  }

  generate_ascii_art(width, height, arr);

  for (int i = 0; i < height; i++)
  {
    free(arr[i]);
  }

  free(arr);

  return 0;
}