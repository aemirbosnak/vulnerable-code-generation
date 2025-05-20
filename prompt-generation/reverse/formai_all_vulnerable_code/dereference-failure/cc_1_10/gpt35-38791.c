//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFERSIZE 1024
#define TOKEN_BUFFERSIZE 64
#define TOKEN_DELIMITER " \t\r\n\a"

void launchShell();
char *readLine();
char **parseLine(char *line);
int execute(char **args);

int main() {
  launchShell();
  return 0;
}

void launchShell() {
  char *line;
  char **args;
  int status;
  
  do {
    printf("unixsh>");
    line = readLine();
    args = parseLine(line);
    status = execute(args);
    
    free(line);
    free(args);
  } while (status);
}

char *readLine() {
  int bufferSize = BUFFERSIZE;
  int position = 0;
  char *buffer = malloc(sizeof(char) * bufferSize);
  int character;

  while (1) {
    character = getchar();

    if (character == EOF || character == '\n') {
      buffer[position] = '\0';
      return buffer;
    } 
    else {
      buffer[position] = character;
    }

    position++;

    if (position >= bufferSize) {
      bufferSize += BUFFERSIZE;
      buffer = realloc(buffer, bufferSize);
    }
  }
}

char **parseLine(char *line) {
  int bufferSize = TOKEN_BUFFERSIZE, position = 0;
  char **tokens = malloc(bufferSize * sizeof(char*));
  char *token;

  if (!tokens) {
    fprintf(stderr, "Allocation Error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, TOKEN_DELIMITER);
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= bufferSize) {
      bufferSize += TOKEN_BUFFERSIZE;
      tokens = realloc(tokens, bufferSize * sizeof(char*));
      if (!tokens) {
        fprintf(stderr, "Allocation Error\n");
        exit(EXIT_FAILURE);
      }
    }
    token = strtok(NULL, TOKEN_DELIMITER);
  }
  tokens[position] = NULL;
  return tokens;
}

int execute(char **args) {
  pid_t pid, wpid;
  int status;

  if (args[0] == NULL) {
    return 1; 
  }

  pid = fork();
  if (pid == 0) {
    if (execvp(args[0], args) == -1) {
      perror("Unix Shell");
    }
    exit(EXIT_FAILURE);
  } 
  else if (pid < 0) {
    perror("Unix Shell");
  } 
  else {
    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}