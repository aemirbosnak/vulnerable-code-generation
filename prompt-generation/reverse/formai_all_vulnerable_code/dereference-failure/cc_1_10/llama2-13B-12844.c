//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// Define our own magic constants 🧙‍♂️
#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 64

// Structure to hold command and its arguments 📝
typedef struct command {
  char *name;  // Command name
  char *args[MAX_ARGS];  // Argument list
} command_t;

// Function to execute a command 🔥
int execute_command(command_t *cmd) {
  // Check if the command exists 🤔
  if (!access(cmd->name, X_OK)) {
    // Execute the command 💥
    char *argv[MAX_ARGS];
    int status;
    for (int i = 0; i < MAX_ARGS; i++) {
      argv[i] = cmd->args[i];
    }
    if (execvp(cmd->name, argv) == -1) {
      perror("execvp");
      return 1;
    }
    wait(&status);
    return 0;
  }
  // Command not found 😢
  printf("Command not found: %s\n", cmd->name);
  return 1;
}

int main() {
  // Initialize command and argument structures 🤝
  command_t cmd;
  cmd.name = "ls";
  cmd.args[0] = "-l";
  cmd.args[1] = "-t";

  // Execute the command 🔥
  if (execute_command(&cmd) == 0) {
    // Print the command output 📦
    printf("Command output:\n%s\n", cmd.args[0]);
  } else {
    // Print an error message 😢
    printf("Command execution failed\n");
  }

  // Clean up 🧹
  free(cmd.name);
  for (int i = 0; i < MAX_ARGS; i++) {
    free(cmd.args[i]);
  }

  return 0;
}