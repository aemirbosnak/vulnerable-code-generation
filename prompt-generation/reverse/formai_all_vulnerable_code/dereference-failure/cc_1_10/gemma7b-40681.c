//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void draw_ascii_art(char **arr)
{
  int i, j;
  for (i = 0; arr[i] != NULL; i++)
  {
    for (j = 0; arr[i][j] != '\0'; j++)
    {
      switch (arr[i][j])
      {
        case '.':
          printf(" ");
          break;
        case '#':
          printf("=");
          break;
        case '$':
          printf("O");
          break;
        default:
          printf("%c", arr[i][j]);
          break;
      }
    }
    printf("\n");
  }
}

int main()
{
  char **arr = NULL;
  arr = malloc(sizeof(char *) * 3);
  arr[0] = malloc(sizeof(char) * 10);
  arr[1] = malloc(sizeof(char) * 10);
  arr[2] = malloc(sizeof(char) * 10);

  arr[0][0] = '$';
  arr[0][1] = '#';
  arr[0][2] = '$';
  arr[0][3] = '#';
  arr[0][4] = '$';
  arr[0][5] = ' ';
  arr[0][6] = ' ';
  arr[0][7] = ' ';
  arr[0][8] = ' ';
  arr[0][9] = '\0';

  arr[1][0] = '#';
  arr[1][1] = '#';
  arr[1][2] = '#';
  arr[1][3] = ' ';
  arr[1][4] = ' ';
  arr[1][5] = ' ';
  arr[1][6] = ' ';
  arr[1][7] = ' ';
  arr[1][8] = ' ';
  arr[1][9] = '\0';

  arr[2][0] = '$';
  arr[2][1] = '#';
  arr[2][2] = '$';
  arr[2][3] = ' ';
  arr[2][4] = ' ';
  arr[2][5] = ' ';
  arr[2][6] = ' ';
  arr[2][7] = ' ';
  arr[2][8] = ' ';
  arr[2][9] = '\0';

  draw_ascii_art(arr);

  free(arr[0]);
  free(arr[1]);
  free(arr[2]);
  free(arr);

  return 0;
}