//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 256

char shell_prompt[] = "$ ";

void execute_command(char *command) {
  char **args = NULL;
  char *arg = NULL;
  int num_args = 0;

  // Tokenize the command into arguments
  args = strtok(command, " ");

  // Count the number of arguments
  while (args[num_args] != NULL) {
    num_args++;
  }

  // Allocate memory for the arguments
  arg = malloc(num_args * sizeof(char *));

  // Copy the arguments into the allocated memory
  for (int i = 0; i < num_args; i++) {
    arg[i] = strdup(args[i]);
  }

  // Execute the command
  pid_t pid = fork();
  if (pid == 0) {
    execvp(arg[0], arg);
  } else {
    wait(NULL);
  }

  // Free the allocated memory
  free(arg);
}

int main() {
  char command[MAX_CMD_LEN];

  // Display the shell prompt
  printf("%s", shell_prompt);

  // Get the user input
  fgets(command, MAX_CMD_LEN, stdin);

  // Execute the command
  execute_command(command);

  return 0;
}