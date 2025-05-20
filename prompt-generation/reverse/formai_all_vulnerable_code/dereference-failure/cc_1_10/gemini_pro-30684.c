//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

// Define the maximum length of a command
#define MAX_COMMAND_LENGTH 1024

// Define the maximum number of arguments in a command
#define MAX_ARGS 16

// Define the maximum number of commands in a history
#define MAX_HISTORY 10

// Define the history file
#define HISTORY_FILE ".history"

// Function to print the prompt
void print_prompt() {
  printf("myshell> ");
}

// Function to read a line from the terminal
char* read_line() {
  char* line = malloc(MAX_COMMAND_LENGTH);
  if (line == NULL) {
    perror("malloc");
    exit(1);
  }
  if (fgets(line, MAX_COMMAND_LENGTH, stdin) == NULL) {
    perror("fgets");
    exit(1);
  }
  return line;
}

// Function to parse a line into arguments
char** parse_args(char* line) {
  char** args = malloc(MAX_ARGS * sizeof(char*));
  if (args == NULL) {
    perror("malloc");
    exit(1);
  }
  int i = 0;
  char* token = strtok(line, " ");
  while (token != NULL) {
    args[i] = token;
    i++;
    token = strtok(NULL, " ");
  }
  args[i] = NULL;
  return args;
}

// Function to execute a command
int execute_command(char** args) {
  pid_t pid = fork();
  if (pid == -1) {
    perror("fork");
    exit(1);
  } else if (pid == 0) {
    // Child process
    if (execvp(args[0], args) == -1) {
      perror("execvp");
      exit(1);
    }
  } else {
    // Parent process
    int status;
    waitpid(pid, &status, 0);
    return WEXITSTATUS(status);
  }
  return 0;
}

// Function to add a command to the history
void add_to_history(char* line) {
  FILE* fp = fopen(HISTORY_FILE, "a");
  if (fp == NULL) {
    perror("fopen");
    exit(1);
  }
  fprintf(fp, "%s\n", line);
  fclose(fp);
}

// Function to print the history
void print_history() {
  FILE* fp = fopen(HISTORY_FILE, "r");
  if (fp == NULL) {
    perror("fopen");
    exit(1);
  }
  char* line = malloc(MAX_COMMAND_LENGTH);
  if (line == NULL) {
    perror("malloc");
    exit(1);
  }
  int i = 1;
  while (fgets(line, MAX_COMMAND_LENGTH, fp) != NULL) {
    printf("%d %s", i, line);
    i++;
  }
  free(line);
  fclose(fp);
}

// Function to run the shell
void run_shell() {
  while (1) {
    print_prompt();
    char* line = read_line();
    if (strcmp(line, "exit\n") == 0) {
      break;
    } else if (strcmp(line, "history\n") == 0) {
      print_history();
    } else {
      char** args = parse_args(line);
      add_to_history(line);
      execute_command(args);
      free(args);
    }
    free(line);
  }
}

// Main function
int main() {
  run_shell();
  return 0;
}