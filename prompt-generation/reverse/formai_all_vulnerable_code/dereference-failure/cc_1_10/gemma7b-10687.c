//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 256

typedef struct ShellState {
  char cmd_line[MAX_CMD_LEN];
  char **cmd_argv;
  int cmd_argc;
  int pipefd[2];
} ShellState;

ShellState shell_state;

void parse_cmd_line(char *line) {
  char *cmd, *arg;
  shell_state.cmd_line[0] = '\0';

  // Extract the command and arguments
  cmd = strtok(line, " ");
  arg = strtok(NULL, " ");

  // Copy the command and arguments to the shell state
  strncpy(shell_state.cmd_line, cmd, MAX_CMD_LEN - 1);
  shell_state.cmd_argc = 0;
  while (arg) {
    shell_state.cmd_argv = realloc(shell_state.cmd_argv, (shell_state.cmd_argc + 1) * sizeof(char *));
    shell_state.cmd_argv[shell_state.cmd_argc++] = arg;
    arg = strtok(NULL, " ");
  }
  shell_state.cmd_argv[shell_state.cmd_argc] = NULL;
}

void execute_cmd() {
  pid_t pid;
  int status;

  // Fork the child process
  pid = fork();

  if (pid == 0) {
    // Child process
    execvp(shell_state.cmd_line, shell_state.cmd_argv);
    exit(1);
  } else if (pid > 0) {
    // Parent process
    wait(&status);
    printf("Exit status: %d\n", status);
  } else {
    // Error
    perror("fork");
  }
}

int main() {
  char line[MAX_CMD_LEN];

  // Initialize the shell state
  shell_state.cmd_argc = 0;
  shell_state.cmd_argv = NULL;
  shell_state.pipefd[0] = -1;
  shell_state.pipefd[1] = -1;

  // Enter the shell loop
  while (1) {
    // Print the prompt
    printf("$ ");

    // Get the command line input
    getline(line, MAX_CMD_LEN, stdin);

    // Parse the command line
    parse_cmd_line(line);

    // Execute the command
    execute_cmd();
  }

  return 0;
}