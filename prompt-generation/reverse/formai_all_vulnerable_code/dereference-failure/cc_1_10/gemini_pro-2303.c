//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

// Declare the maximum length of a command line
#define MAX_LINE_LENGTH 1024

// Declare the maximum number of arguments in a command line
#define MAX_ARGS 10

// Declare the maximum number of commands in a history
#define MAX_HISTORY 10

// Declare the history of commands
char *history[MAX_HISTORY];

// Declare the current position in the history
int history_pos = 0;

// Declare the prompt
char *prompt = "myshell> ";

// Print the prompt
void print_prompt() {
  printf("%s", prompt);
}

// Read a line from the user
char *read_line() {
  char *line = malloc(MAX_LINE_LENGTH);
  if (line == NULL) {
    perror("malloc");
    exit(1);
  }
  if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
    perror("fgets");
    exit(1);
  }
  // Remove the newline character from the end of the line
  line[strlen(line) - 1] = '\0';
  return line;
}

// Parse a line into an array of arguments
char **parse_args(char *line) {
  char **args = malloc(MAX_ARGS * sizeof(char *));
  if (args == NULL) {
    perror("malloc");
    exit(1);
  }
  int i = 0;
  char *arg = strtok(line, " ");
  while (arg != NULL) {
    args[i] = arg;
    i++;
    arg = strtok(NULL, " ");
  }
  args[i] = NULL;
  return args;
}

// Execute a command
int execute_command(char **args) {
  // Check if the command is built-in
  if (strcmp(args[0], "exit") == 0) {
    exit(0);
  } else if (strcmp(args[0], "cd") == 0) {
    if (chdir(args[1]) != 0) {
      perror("chdir");
      return 1;
    }
    return 0;
  } else if (strcmp(args[0], "history") == 0) {
    for (int i = 0; i < history_pos; i++) {
      printf("%s\n", history[i]);
    }
    return 0;
  }

  // Fork a new process
  pid_t pid = fork();
  if (pid == -1) {
    perror("fork");
    return 1;
  }

  // If the child process, execute the command
  if (pid == 0) {
    if (execvp(args[0], args) == -1) {
      perror("execvp");
      exit(1);
    }
  }

  // If the parent process, wait for the child process to finish
  int status;
  waitpid(pid, &status, 0);

  // Return the exit status of the child process
  return WEXITSTATUS(status);
}

// Main loop
int main() {
  while (1) {
    // Print the prompt
    print_prompt();

    // Read a line from the user
    char *line = read_line();

    // Parse the line into an array of arguments
    char **args = parse_args(line);

    // Execute the command
    int status = execute_command(args);

    // Add the command to the history
    if (history_pos < MAX_HISTORY) {
      history[history_pos] = line;
      history_pos++;
    } else {
      for (int i = 0; i < MAX_HISTORY - 1; i++) {
        history[i] = history[i + 1];
      }
      history[MAX_HISTORY - 1] = line;
    }

    // Free the memory allocated for the arguments
    free(args);
  }

  return 0;
}