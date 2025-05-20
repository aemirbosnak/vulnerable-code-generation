//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: complete
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

#define MAX_LENGTH 100
#define MAX_ARGUMENTS 10

char **get_arguments(char *input) {
  char **arguments = malloc(MAX_ARGUMENTS*sizeof(char*));
  char *argument;
  int i=0;

  argument = strtok(input, " ");
  while(argument != NULL) {
    arguments[i++] = argument;
    argument = strtok(NULL, " ");
  }
  arguments[i] = NULL;
  return arguments;
}

void execute(char *input) {
  pid_t pid;
  int status;
  char **arguments = get_arguments(input);

  pid = fork();
  if(pid < 0) {
    perror("Unable to create child process");
    exit(1);
  }
  else if(pid == 0) {
    if(execvp(*arguments, arguments) < 0) {
      perror("Execution Failed");
      exit(1);
    }
  }
  else {
    waitpid(pid, &status, 0);
  }
}

int main() {
  char input[MAX_LENGTH];

  while(1) {
    printf(">> ");
    fflush(stdout);

    fgets(input, MAX_LENGTH, stdin);

    if(strcmp(input, "exit\n") == 0) {
      break;
    }

    execute(input);
  }

  return 0;
}