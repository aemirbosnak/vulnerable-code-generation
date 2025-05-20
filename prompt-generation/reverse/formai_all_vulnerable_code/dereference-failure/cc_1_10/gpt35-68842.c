//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  char command[100];
  char *args[10];
  int status;

  printf("Hello there! Welcome to the Cheerful Unix-like Shell.\n");

  while (1) {
    printf("\n>> ");

    // read user input
    fgets(command, sizeof(command), stdin);

    // remove newline character from input
    command[strcspn(command, "\n")] = '\0';

    // split input by whitespace
    char *token = strtok(command, " ");
    int i = 0;

    while (token != NULL) {
      args[i++] = token;
      token = strtok(NULL, " ");
    }

    args[i] = NULL;

    // exit if user types "exit"
    if (strcmp(args[0], "exit") == 0) {
      printf("Goodbye! Have a great day.\n");
      exit(0);
    }

    // fork and execute command
    int pid = fork();

    if (pid == 0) {
      execvp(args[0], args);
      printf("Error executing command.\n");
      exit(0);
    } else {
      waitpid(pid, &status, 0);
    }
  }
  
  return 0;
}