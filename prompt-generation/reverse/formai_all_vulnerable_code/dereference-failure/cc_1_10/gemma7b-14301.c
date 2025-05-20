//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

char buffer[MAX_BUFFER_SIZE];

void parse_command(char *command)
{
  char **args = NULL;
  int num_args = 0;

  // Split the command into arguments
  char *arg = strtok(command, " ");
  while (arg)
  {
    args = realloc(args, (num_args + 1) * sizeof(char *));
    args[num_args++] = arg;
    arg = strtok(NULL, " ");
  }

  // Execute the command
  if (num_args > 0)
  {
    execvp(args[0], args);
  }
  else
  {
    printf("Error: invalid command.\n");
  }

  // Free the arguments
  free(args);
}

int main()
{
  // Get the user input
  char input[MAX_BUFFER_SIZE];

  // Loop until the user enters an exit command
  while (1)
  {
    // Print the prompt
    printf("$ ");

    // Get the user input
    fgets(input, MAX_BUFFER_SIZE, stdin);

    // Remove the newline character from the input
    input[strcspn(input, "\n")] = '\0';

    // Parse the command
    parse_command(input);

    // Check if the user entered an exit command
    if (strcmp(input, "exit") == 0)
    {
      break;
    }
  }

  // Exit the shell
  return 0;
}