//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// What's this? A shell? In C? You betcha!

// Function declarations
char *read_line();
char **split_line(char *line);
int execute(char **args);
void loop();

// Read a line from the user
char *read_line() {
  char *line = NULL;
  size_t bufsize = 0;
  getline(&line, &bufsize, stdin);
  return line;
}

// Split a line into an array of arguments
char **split_line(char *line) {
  char **args = malloc(sizeof(char *) * 10);
  char *arg;
  int i = 0;
  arg = strtok(line, " ");
  while (arg != NULL) {
    args[i] = arg;
    i++;
    arg = strtok(NULL, " ");
  }
  args[i] = NULL;
  return args;
}

// Execute a command
int execute(char **args) {
  pid_t pid;
  int status;
  if ((pid = fork()) < 0) {
    perror("fork");
    exit(EXIT_FAILURE);
  } else if (pid == 0) {
    if (execvp(args[0], args) < 0) {
      perror("execvp");
      exit(EXIT_FAILURE);
    }
  } else {
    while (wait(&status) != pid)
      ;
  }
  return 0;
}

// Main loop
void loop() {
  char *line;
  char **args;
  int status;
  do {
    printf("> ");
    line = read_line();
    args = split_line(line);
    status = execute(args);
    free(line);
    free(args);
  } while (status);
}

// Entry point
int main() {
  loop();
  return 0;
}