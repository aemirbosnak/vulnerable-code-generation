//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shell_loop(void);
char *read_line(void);
char **parse_line(char *line);
int execute(char **args);

int main(int argc, char **argv) {
  system("clear");
  printf("Welcome to the Surrealist Shell\n");
  printf("Commands: say, dance, fly, disappear\n");
  shell_loop();
  return 0;
}

void shell_loop(void) {
  char *line;
  char **args;
  int status;

  do {
    printf("> ");
    line = read_line();
    args = parse_line(line);
    status = execute(args);

    free(line);
    free(args);
  } while (status);
}

char *read_line(void) {
  char *line = NULL;
  size_t bufsize = 0;
  getline(&line, &bufsize, stdin);
  return line;
}

char **parse_line(char *line) {
  char **tokens = malloc(100 * sizeof(char *));
  char *token;
  int i = 0;

  token = strtok(line, " \t\r\n\a");
  while (token != NULL) {
    tokens[i] = token;
    i++;
    token = strtok(NULL, " \t\r\n\a");
  }
  tokens[i] = NULL;
  return tokens;
}

int execute(char **args) {
  if (args[0] == NULL) {
    return 1;
  }
  if (strcmp(args[0], "say") == 0) {
    printf("I say that you are the universe!\n");
  } else if (strcmp(args[0], "dance") == 0) {
    printf("You dance like a shooting star!\n");
  } else if (strcmp(args[0], "fly") == 0) {
    printf("You fly away into the cosmos!\n");
  } else if (strcmp(args[0], "disappear") == 0) {
    printf("You disappear into the ether!\n");
    return 0;
  } else {
    printf("I don't understand what you mean...\n");
  }
  return 1;
}