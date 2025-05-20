//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_TOKENS 64
#define TOKEN_DELIMITER " \t\r\n\a"

void execute_command(char **tokens) {
  pid_t pid;
  int status;

  if ((pid = fork()) == 0) { // Child process
    if (execvp(tokens[0], tokens) == -1) {
      printf("Error: command not found.\n");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) { // Error forking
    printf("Error: forking failed.\n");
  } else { // Parent process
    do {
      waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }
}

char **parse_input(char *input) {
  char **tokens = malloc(MAX_TOKENS * sizeof(char *));
  char *token;
  int index = 0;

  if (!tokens) {
    printf("Error: memory allocation failed.\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(input, TOKEN_DELIMITER);
  while (token != NULL) {
    tokens[index] = token;
    index++;

    if (index >= MAX_TOKENS) {
      printf("Error: too many arguments.\n");
      exit(EXIT_FAILURE);
    }

    token = strtok(NULL, TOKEN_DELIMITER);
  }
  tokens[index] = NULL;
  return tokens;
}

int main() {
  char input[MAX_INPUT_LENGTH];
  char **tokens;
  
  printf("Unix-like Shell. Type 'exit' to quit.\n");

  while (1) {
    printf("> ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    if (strcmp(input, "exit\n") == 0) {
      break;
    } else {
      tokens = parse_input(input);
      execute_command(tokens);
      free(tokens);
    }
  }
  return 0;
}