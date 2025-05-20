//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// An array of strings to hold the arguments for the shell.
char *args[512];

// The main function of the shell.
int main() {
  // Create a loop that will run until the user exits the shell.
  while (1) {
    // Prompt the user for a command.
    printf("> ");

    // Read the command from the user.
    char line[512];
    fgets(line, 512, stdin);

    // Parse the command into arguments.
    int i = 0;
    args[i] = strtok(line, " ");
    while (args[i] != NULL) {
      i++;
      args[i] = strtok(NULL, " ");
    }

    // Check if the user entered the exit command.
    if (strcmp(args[0], "exit") == 0) {
      break;
    }

    // Fork a child process to execute the command.
    pid_t pid = fork();
    if (pid < 0) {
      perror("fork");
      continue;
    }

    // If the child process is the parent, wait for the child process to terminate.
    if (pid > 0) {
      int status;
      waitpid(pid, &status, 0);
    }

    // If the child process is the child, execute the command.
    if (pid == 0) {
      // Replace the current process with the command.
      execvp(args[0], args);

      // If the execvp() call fails, print an error message and exit.
      perror("execvp");
      exit(1);
    }
  }

  // Return 0 to indicate that the program has terminated successfully.
  return 0;
}