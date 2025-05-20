//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1000
#define MAX_ARGUMENTS 100

char* read_command() {
  char* input = malloc(MAX_COMMAND_LENGTH);
  fgets(input, MAX_COMMAND_LENGTH, stdin);
  return input;
}

char** parse_command(char* input) {
  char** arguments = malloc(MAX_ARGUMENTS);
  int index = 0;
  char* argument = strtok(input, " ");
  while(argument != NULL) {
    arguments[index] = argument;
    index++;
    argument = strtok(NULL, " ");
  }
  arguments[index] = NULL;
  return arguments;
}

int execute_command(char** arguments) {
  pid_t pid = fork();
  if(pid < 0) {
    printf("Error: forking child process failed\n");
    return 1;
  } else if (pid == 0) {
    if(execvp(arguments[0], arguments) < 0) {
      printf("Error: executing command\n");
      return 1;
    }
    exit(0);
  } else {
    wait(NULL);
    return 0;
  }
}

int main() {
  printf("Welcome to the Happy Unix-like Shell!\nType 'exit' to quit the shell.\n");
  while(1) {
    printf(">> ");
    char* input = read_command();
    if(strncmp(input, "exit", 4) == 0) {
      free(input);
      break;
    } else {
      char** arguments = parse_command(input);
      int result = execute_command(arguments);
      free(input);
      free(arguments);
      if(result == 1) {
        printf("Oops, something went wrong!\n");
      }
    }
  }
  printf("Thanks for using the Happy Unix-like Shell!\n");
  return 0;
}