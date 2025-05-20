//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>

// Function to print shell prompt
void print_prompt() {
  printf("\033[1;31m%s\033[0m>", "Gobo>");
}

// Function to execute a given command
int execute_command(char **args) {
  pid_t pid;
  int status;

  pid = fork();
  if (pid == -1) {
    perror("Error forking process");
    return 1;
  } else if (pid == 0) { // Child process
    if (execvp(args[0], args) == -1) {
      perror("Error executing command");
      exit(1);
    }
  } else { // Parent process
    waitpid(pid, &status, 0);
  }

  return status;
}

// Function to parse user input into tokens
char **parse_input(char *line) {
  int bufsize = 64, position = 0, counter = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  token = strtok(line, " ");
  while (token != NULL) {
    tokens[counter] = token;
    counter++;

    if (counter + 1 >= bufsize) {
      bufsize += 64;
      tokens = realloc(tokens, bufsize * sizeof(char*));
    }

    token = strtok(NULL, " ");
  }
  tokens[counter] = NULL;
  return tokens;
}

int main() {
  char line[256], *args[128];
  char **tokens;
  int status;

  while (1) {
    print_prompt();
    fgets(line, sizeof(line), stdin);
    line[strlen(line) - 1] = '\0'; // Remove newline character

    tokens = parse_input(line);

    if (strcmp(tokens[0], "exit") == 0) {
      break;
    }

    status = execute_command(tokens);
    if (WIFEXITED(status)) {
      printf("\033[1;31m%s\033[0m exited with status: %d\n", tokens[0], WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
      printf("\033[1;31m%s\033[0m received signal: %d\n", tokens[0], WTERMSIG(status));
    }

    for (int i = 0; tokens[i] != NULL; i++) {
      free(tokens[i]);
    }
    free(tokens);
  }

  return 0;
}