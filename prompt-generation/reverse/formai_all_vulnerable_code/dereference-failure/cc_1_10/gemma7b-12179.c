//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 20

void generate_ascii_art(char **arr, int h, int w)
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
  int h, w;
  printf("Enter the height of your ASCII art: ");
  scanf("%d", &h);

  printf("Enter the width of your ASCII art: ");
  scanf("%d", &w);

  char **arr = (char **)malloc(h * sizeof(char *) + 1);
  for (int i = 0; i < h; i++)
  {
    arr[i] = (char *)malloc(w * sizeof(char) + 1);
  }

  // Fill the array with ASCII art characters
  arr[0][0] = '$';
  arr[0][1] = '$';
  arr[1][0] = '$';
  arr[1][1] = '#';
  arr[2][0] = '#';
  arr[2][1] = '#';

  generate_ascii_art(arr, h, w);

  for (int i = 0; i < h; i++)
  {
    free(arr[i]);
  }
  free(arr);

  return 0;
}