//Gemma-7B DATASET v1.0 Category: Error handling ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void handle_error(int err_num)
{
  switch (err_num)
  {
    case 1:
      fprintf(stderr, "Oh no, the sky is falling! Error 1 has occurred.\n");
      break;
    case 2:
      fprintf(stderr, "The cat has jumped on the keyboard. Error 2 has occurred.\n");
      break;
    case 3:
      fprintf(stderr, "Oops, a banana peel moment. Error 3 has occurred.\n");
      break;
    default:
      fprintf(stderr, "Unknown error. Please consult the manual.\n");
      break;
  }
  exit(1);
}

int main()
{
  int result = 0;
  char *buffer = NULL;

  buffer = malloc(10);
  if (buffer == NULL)
  {
    handle_error(1);
  }

  buffer = strcat(buffer, "Hello, world!");
  if (buffer == NULL)
  {
    handle_error(2);
  }

  result = printf(buffer);
  if (result == -1)
  {
    handle_error(3);
  }

  free(buffer);

  return 0;
}