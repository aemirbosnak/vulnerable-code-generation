//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

// Function to handle SIGINT signal
void sigint_handler(int sig) {
  printf("\nCaught SIGINT (Ctrl+C)\n");
  exit(0);
}

// Function to execute a command
int execute_command(char **argv) {
  pid_t pid = fork();

  if (pid == 0) {
    // Child process
    execvp(argv[0], argv);
    perror("execvp");
    exit(1);
  } else if (pid > 0) {
    // Parent process
    int status;
    waitpid(pid, &status, 0);
    return status;
  } else {
    // Error
    perror("fork");
    return 1;
  }
}

// Main function
int main(int argc, char **argv) {
  // Register SIGINT signal handler
  signal(SIGINT, sigint_handler);

  // Main loop
  while (1) {
    // Print the prompt
    printf("MyShell> ");

    // Get the command from the user
    char *line = NULL;
    size_t len = 0;
    ssize_t nread = getline(&line, &len, stdin);
    if (nread == -1) {
      perror("getline");
      exit(1);
    }

    // Tokenize the command
    char **argv = malloc(sizeof(char *) * 10);
    int argc = 0;
    char *token = strtok(line, " ");
    while (token != NULL) {
      argv[argc++] = token;
      token = strtok(NULL, " ");
    }

    // Execute the command
    int status = execute_command(argv);

    // Free the memory allocated for the command
    free(line);
    free(argv);

    // Check the status of the command
    if (status != 0) {
      printf("Error executing command\n");
    }
  }

  return 0;
}