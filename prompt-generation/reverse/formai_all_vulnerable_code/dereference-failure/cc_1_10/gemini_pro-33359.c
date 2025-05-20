//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Function to parse the command line into tokens
char **parse_args(char *line) {
  int bufsize = 64;
  int position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  if (!tokens) {
    fprintf(stderr, "allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, " ");
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= bufsize) {
      bufsize += 64;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
        fprintf(stderr, "allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, " ");
  }
  tokens[position] = NULL;
  return tokens;
}

// Function to execute the command
int execute(char **args) {
  pid_t pid;
  int status;

  pid = fork();
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
    waitpid(pid, &status, 0);
  }

  return status;
}

// Main function
int main() {
  char *line;
  char **args;
  int status;

  do {
    // Print the prompt
    printf("Enter a command: ");
    fflush(stdout);

    // Read the command line
    line = malloc(1024);
    if (!line) {
      fprintf(stderr, "allocation error\n");
      exit(EXIT_FAILURE);
    }
    fgets(line, 1024, stdin);

    // Parse the command line
    args = parse_args(line);

    // Execute the command
    status = execute(args);

    // Free the memory
    free(line);
    free(args);
  } while (status != EXIT_FAILURE);

  return EXIT_SUCCESS;
}