//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// Built-in commands
int cd(char **args);
int help(char **args);
int exit_shell(char **args);

// List of built-in commands
char *builtin_str[] = {"cd", "help", "exit"};
int (*builtin_func[]) (char **) = {&cd, &help, &exit_shell};

// Function declarations
int launch_program(char **args);
int execute_command(char **args);

// Function to change the current working directory
int cd(char **args) {
  if (args[1] == NULL) {
    fprintf(stderr, "cd: no argument provided\n");
  } else {
    if (chdir(args[1]) != 0) {
      perror("cd");
    }
  }
  return 1;
}

// Function to display a help message
int help(char **args) {
  printf("Built-in commands:\n");
  for (int i = 0; i < 3; i++) {
    printf("  %s\n", builtin_str[i]);
  }
  printf("Use the man command for more information on a specific command.\n");
  return 1;
}

// Function to exit the shell
int exit_shell(char **args) {
  return 0;
}

// Function to launch a program
int launch_program(char **args) {
  pid_t pid = fork();
  if (pid == 0) {
    // Child process
    if (execvp(args[0], args) == -1) {
      perror("execvp");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    // Error
    perror("fork");
  } else {
    // Parent process
    waitpid(pid, NULL, 0);
  }
  return 1;
}

// Function to execute a command
int execute_command(char **args) {
  // Check if the command is a built-in command
  for (int i = 0; i < 3; i++) {
    if (strcmp(args[0], builtin_str[i]) == 0) {
      return (*builtin_func[i])(args);
    }
  }

  // Otherwise, launch the program
  return launch_program(args);
}

// Function to read a line from the terminal
char *readline() {
  char *line = NULL;
  size_t bufsize = 0;
  getline(&line, &bufsize, stdin);
  return line;
}

// Function to split a line into tokens
char **split_line(char *line) {
  char **tokens = malloc(sizeof(char *) * 10);
  int i = 0;
  char *token = strtok(line, " ");
  while (token != NULL) {
    tokens[i] = token;
    i++;
    token = strtok(NULL, " ");
  }
  tokens[i] = NULL;
  return tokens;
}

// Function to free the tokens
void free_tokens(char **tokens) {
  for (int i = 0; tokens[i] != NULL; i++) {
    free(tokens[i]);
  }
  free(tokens);
}

// Main function
int main() {
  // Create a buffer to store the user's input
  char *buffer;
  // Create an array to store the tokens
  char **tokens;
  // Loop until the user exits the shell
  while (1) {
    // Display the prompt
    printf("osh> ");
    // Read a line from the terminal
    buffer = readline();
    // Split the line into tokens
    tokens = split_line(buffer);
    // Execute the command
    execute_command(tokens);
    // Free the tokens
    free_tokens(tokens);
    // Free the buffer
    free(buffer);
  }

  return 0;
}