//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_NUM_ARGUMENTS 10

int main()
{
  char command[MAX_COMMAND_LENGTH];
  char *args[MAX_NUM_ARGUMENTS];
  int status;

  while (1)
  {
    printf("My Awesome Unix-like Shell >>> ");
    fflush(stdout);

    fgets(command, MAX_COMMAND_LENGTH, stdin);

    // Remove newline character from input
    command[strcspn(command, "\n")] = 0;

    // Tokenize input
    char *token = strtok(command, " ");
    int i = 0;

    while (token != NULL && i < MAX_NUM_ARGUMENTS - 1)
    {
      args[i] = token;
      token = strtok(NULL, " ");
      i++;
    }
    args[i] = NULL;

    // Exit program if user enters "exit"
    if (strcmp(args[0], "exit") == 0)
    {
      exit(0);
    }

    pid_t pid = fork();

    if (pid == -1)
    {
      perror("fork");
      exit(1);
    }

    if (pid == 0)
    {
      // Child process
      execvp(args[0], args);
      perror("execvp");
      exit(1);
    }
    else
    {
      // Parent process
      waitpid(pid, &status, 0);
    }
  }

  return 0;
}