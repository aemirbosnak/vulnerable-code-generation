//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {

  while(1) {

    // Print the prompt and get user input
    char prompt[100] = "puzzle-shell$ ";
    char input[255];
    printf("%s", prompt);
    fgets(input, 255, stdin);

    // Remove newline character from user input
    input[strcspn(input, "\n")] = 0;

    // Tokenize the user input
    char *args[255];
    int i = 0;
    char *token = strtok(input, " ");
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    // Check if user wants to exit the shell
    if (strcmp(args[0], "exit") == 0) {
        printf("Exiting...\n");
        exit(0);
    }

    // Check if user wants to solve a puzzle
    if (strcmp(args[0], "solve") == 0) {

      // Create child process to solve puzzle
      pid_t pid = fork();
      if (pid == 0) {
        // Child process
        printf("Solving puzzle...\n");
        int x = 0;
        for (int i=0; i<1000000; i++) {
          x = rand() % 1000000;
        }
        printf("Solution: %d\n", x);
        exit(0);
      }
      else if (pid > 0) {
        // Parent process
        wait(NULL);
      }
      else {
        // Error occured creating child process
        printf("Error: Could not create child process\n");
        continue;
      }

    }

    // Unknown command
    else {
      printf("Unknown command: %s\n", args[0]);
    }

  }

  return 0;
}