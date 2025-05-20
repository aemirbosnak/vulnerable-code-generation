//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_COMMAND_LENGTH 128
#define MAX_ARGUMENTS 32

char* input_buffer;
char** arguments;

void print_prompt() {
  printf("$ ");
}

void read_line() {
  input_buffer = (char*)malloc(sizeof(char) * MAX_INPUT_LENGTH);
  fgets(input_buffer, MAX_INPUT_LENGTH, stdin);
  input_buffer[strlen(input_buffer) - 1] = '\0';
}

void parse_arguments() {
  arguments = (char**)malloc(sizeof(char*) * MAX_ARGUMENTS);
  char* argument = strtok(input_buffer, " ");
  int i = 0;
  while (argument != NULL) {
    arguments[i] = argument;
    argument = strtok(NULL, " ");
    i++;
  }
  arguments[i] = NULL;
}

void execute_command() {
  int pid = fork();
  if (pid == 0) {
    if (execvp(arguments[0], arguments) == -1) {
      printf("Command not found: %s\n", arguments[0]);
    }
    exit(0);
  } else if (pid == -1) {
    printf("Failed to fork process\n");
  } else {
    wait(NULL);
  }
}

void handle_signal(int signal) {
  printf("\n");
  print_prompt();
}

int main() {
  signal(SIGINT, handle_signal); // handle interrupt signal
  input_buffer = NULL;
  arguments = NULL;
  while (1) {
    print_prompt();
    read_line();
    parse_arguments();
    execute_command();
    free(input_buffer);
    free(arguments);
  }
  return 0;
}