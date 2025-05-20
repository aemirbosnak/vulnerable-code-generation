//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 1024

char buffer[MAX_LINES][MAX_LINES];

void beautify(char **buffer, int lines)
{
  int i, j, k;
  for (i = 0; i < lines; i++)
  {
    for (j = 0; buffer[i][j] != '\0'; j++)
    {
      for (k = 0; buffer[i][j] == buffer[i][k] && k < j; k++)
      {
        buffer[i][k] = ' ';
      }
    }
  }
}

int main()
{
  int lines = 0;
  char **pbuffer = NULL;

  // Allocate memory for the buffer
  pbuffer = (char **)malloc(MAX_LINES * sizeof(char *));
  for (int i = 0; i < MAX_LINES; i++)
  {
    pbuffer[i] = (char *)malloc(MAX_LINES * sizeof(char));
  }

  // Get the number of lines from the user
  printf("Enter the number of lines: ");
  scanf("%d", &lines);

  // Read the data from the user
  printf("Enter the data: ");
  for (int i = 0; i < lines; i++)
  {
    fgets(pbuffer[i], MAX_LINES, stdin);
  }

  // Beautify the data
  beautify(pbuffer, lines);

  // Print the beautified data
  for (int i = 0; i < lines; i++)
  {
    printf("%s", pbuffer[i]);
  }

  // Free the memory
  for (int i = 0; i < MAX_LINES; i++)
  {
    free(pbuffer[i]);
  }
  free(pbuffer);

  return 0;
}