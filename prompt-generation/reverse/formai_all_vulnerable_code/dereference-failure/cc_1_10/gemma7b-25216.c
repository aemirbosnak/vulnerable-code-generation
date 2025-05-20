//Gemma-7B DATASET v1.0 Category: Ebook reader ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
  system("rm -rf tmp");
  system("mkdir tmp");

  FILE *fp = fopen("ebook.txt", "r");
  if (fp == NULL)
  {
    return 1;
  }

  char *buffer = malloc(1024);
  int bytesRead = fread(buffer, 1, 1024, fp);

  if (bytesRead > 0)
  {
    buffer[bytesRead] = '\0';

    time_t t = time(NULL);
    srand(t);

    int randomNumber = rand() % 10;
    printf("Random number: %d\n", randomNumber);

    char *searchString = "The quick brown fox";
    int searchStringLength = strlen(searchString);

    int found = 0;
    for (int i = 0; i < bytesRead; i++)
    {
      if (strstr(buffer, searchString) != NULL)
      {
        found = 1;
        break;
      }
    }

    if (found)
    {
      printf("Book contains the search string: %s\n", searchString);
    }
    else
    {
      printf("Book does not contain the search string: %s\n", searchString);
    }

    fclose(fp);
    free(buffer);
  }

  return 0;
}