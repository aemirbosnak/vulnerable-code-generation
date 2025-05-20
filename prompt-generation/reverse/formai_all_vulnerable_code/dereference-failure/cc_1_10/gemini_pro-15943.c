//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Built-in commands
#define BUILTIN_EXIT "exit"
#define BUILTIN_CD "cd"
#define BUILTIN_HELP "help"

// Maximum command length
#define MAX_CMD_LEN 1024

// Maximum number of arguments
#define MAX_ARGS 32

// Prompt
#define PROMPT ">>> "

// Function to parse the command line
int parse_cmd(char *line, char **argv) {
  int argc = 0;
  char *ptr = strtok(line, " ");
  while (ptr != NULL) {
    argv[argc++] = ptr;
    ptr = strtok(NULL, " ");
  }
  return argc;
}

// Function to execute a command
int execute_cmd(char **argv) {
  // Check for built-in commands
  if (strcmp(argv[0], BUILTIN_EXIT) == 0) {
    exit(0);
  } else if (strcmp(argv[0], BUILTIN_CD) == 0) {
    if (chdir(argv[1]) != 0) {
      perror("chdir");
      return 1;
    }
    return 0;
  } else if (strcmp(argv[0], BUILTIN_HELP) == 0) {
    printf("Built-in commands:\n");
    printf("  %s: Exit the shell\n", BUILTIN_EXIT);
    printf("  %s: Change the current directory\n", BUILTIN_CD);
    printf("  %s: Display this help message\n", BUILTIN_HELP);
    return 0;
  }

  // Otherwise, fork and exec the command
  pid_t pid = fork();
  if (pid == 0) {
    // Child process
    execvp(argv[0], argv);
    perror("execvp");
    exit(1);
  } else if (pid > 0) {
    // Parent process
    int status;
    waitpid(pid, &status, 0);
    return WEXITSTATUS(status);
  } else {
    // Fork failed
    perror("fork");
    return 1;
  }
}

// Main loop
int main() {
  char line[MAX_CMD_LEN];
  char *argv[MAX_ARGS];

  while (1) {
    // Print the prompt
    printf("%s ", PROMPT);

    // Read the command line
    if (fgets(line, MAX_CMD_LEN, stdin) == NULL) {
      printf("\n");
      exit(0);
    }

    // Parse the command line
    int argc = parse_cmd(line, argv);

    // Execute the command
    int status = execute_cmd(argv);

    // Check for errors

    if (status != 0) {
      printf("Command not found or failed to execute\n");
    }
  }

  return 0;
}