//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 50

int main() {
  char input[MAX_COMMANDS * MAX_COMMAND_LENGTH];
  char* commands[MAX_COMMANDS];

  printf("Welcome to the Futuristic Shell program!\n");

  while(1) {
    printf(">> ");
    fgets(input, MAX_COMMANDS * MAX_COMMAND_LENGTH, stdin);
    input[strlen(input) - 1] = '\0';  // remove newline character

    char* token = strtok(input, " ");
    int i = 0;

    while(token != NULL) {
      commands[i] = token;
      i++;
      token = strtok(NULL, " ");
    }
    commands[i] = NULL;  // set the last element to NULL for execvp

    if(strcmp(commands[0], "exit") == 0) {
      printf("Exiting the futuristic shell program...\n");
      exit(0);
    }

    pid_t pid = fork();

    if(pid == -1) {
      fprintf(stderr, "Error: fork failed\n");
      exit(1);
    } else if(pid == 0) {
      // child process
      int exec_status = execvp(commands[0], commands);
      if(exec_status == -1) {
        fprintf(stderr, "Error: execvp failed\n");
        exit(1);
      }
    } else {
      // parent process
      wait(NULL);
    }
  }
}