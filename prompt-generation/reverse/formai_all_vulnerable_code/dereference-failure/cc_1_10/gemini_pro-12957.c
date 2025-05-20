//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 100

char *args[MAX_ARGS];
char line[MAX_LINE_LENGTH];

int main(int argc, char **argv)
{
  while (1)
  {
    printf("What is thy bidding, fair maiden?\n");
    fgets(line, MAX_LINE_LENGTH, stdin);

    char *p = strtok(line, " \n");
    int i = 0;
    while (p != NULL && i < MAX_ARGS)
    {
      args[i] = p;
      p = strtok(NULL, " \n");
      i++;
    }

    args[i] = NULL;

    if (strcmp(args[0], "quit") == 0)
    {
      printf("Farewell, fair maiden.\n");
      exit(0);
    }
    else if (strcmp(args[0], "cd") == 0)
    {
      if (args[1] == NULL)
      {
        printf("To what realm wouldst thou journey?\n");
      }
      else
      {
        if (chdir(args[1]) != 0)
        {
          printf("Alas, thy path is blocked.\n");
        }
      }
    }
    else if (strcmp(args[0], "ls") == 0)
    {
      system("ls");
    }
    else
    {
      printf("I know not of that command, fair maiden.\n");
    }
  }

  return 0;
}