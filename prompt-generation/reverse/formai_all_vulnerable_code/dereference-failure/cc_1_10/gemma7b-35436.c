//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

char shell_buffer[MAX_BUFFER_SIZE];

void execute_command(char *command) {
  char **args = NULL;
  char *arg = NULL;
  int i = 0;

  // Tokenize the command
  args = malloc(sizeof(char *) * MAX_BUFFER_SIZE);
  arg = strtok(command, " ");
  while (arg) {
    args[i++] = arg;
    arg = strtok(NULL, " ");
  }

  // Execute the command
  if (fork() == 0) {
    execvp(args[0], args);
  } else {
    wait(NULL);
  }

  // Free the memory
  free(args);
}

int main() {
  char input[MAX_BUFFER_SIZE];

  // Enter the shell loop
  while (1) {
    // Print the prompt
    printf("$ ");

    // Get the user input
    fgets(input, MAX_BUFFER_SIZE, stdin);

    // Remove the newline character
    input[strcspn(input, "\n")] = '\0';

    // Execute the command
    execute_command(input);
  }

  return 0;
}