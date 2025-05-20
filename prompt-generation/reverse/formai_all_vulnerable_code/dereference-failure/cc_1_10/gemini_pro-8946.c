//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// Command structure
struct Command {
  char *name;
  char **args;
};

// Parse a command line into a Command structure
struct Command *parse_command(char *line) {
  // Allocate memory for the command
  struct Command *command = malloc(sizeof(struct Command));

  // Parse the command name
  char *name = strtok(line, " ");
  command->name = strdup(name);

  // Parse the command arguments
  char **args = malloc(sizeof(char *) * 10);
  int i = 0;
  while ((args[i] = strtok(NULL, " ")) != NULL) {
    i++;
  }
  args[i] = NULL;
  command->args = args;

  return command;
}

// Execute a command
int execute_command(struct Command *command) {
  // Fork a child process
  pid_t pid = fork();
  if (pid == 0) {
    // This is the child process
    execvp(command->name, command->args);
    perror("execvp");
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    // Fork failed
    perror("fork");
    return -1;
  } else {
    // This is the parent process
    int status;
    waitpid(pid, &status, 0);
    return status;
  }
}

// Main loop
int main() {
  // Read a line from the user
  char line[1024];
  while (1) {
    printf("$ ");
    fgets(line, sizeof(line), stdin);

    // Parse the command
    struct Command *command = parse_command(line);

    // Execute the command
    execute_command(command);

    // Free the memory allocated for the command
    free(command->name);
    free(command->args);
    free(command);
  }

  return 0;
}