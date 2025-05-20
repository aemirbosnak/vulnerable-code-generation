//GEMINI-pro DATASET v1.0 Category: System administration ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[])
{
  int i, j, status;
  char *args[MAX_ARGS];
  char line[MAX_LINE_LENGTH];
  char *prompt = "$ ";

  while (1)
  {
    printf("%s", prompt);
    fflush(stdout);
    if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL)
    {
      break;
    }

    // Parse the command line.
    i = 0;
    args[i] = strtok(line, " ");
    while (args[i] != NULL && i < MAX_ARGS - 1)
    {
      i++;
      args[i] = strtok(NULL, " ");
    }
    args[i] = NULL;

    // Check for built-in commands.
    if (strcmp(args[0], "cd") == 0)
    {
      if (args[1] == NULL)
      {
        fprintf(stderr, "Usage: cd <directory>\n");
      }
      else
      {
        if (chdir(args[1]) != 0)
        {
          perror("chdir");
        }
      }
    }
    else if (strcmp(args[0], "exit") == 0)
    {
      break;
    }
    else
    {
      // Fork a child process to execute the command.
      pid_t child_pid = fork();
      if (child_pid == 0)
      {
        // Child process.
        execvp(args[0], args);
        perror("execvp");
        exit(EXIT_FAILURE);
      }
      else
      {
        // Parent process.
        waitpid(child_pid, &status, 0);
      }
    }
  }

  return 0;
}