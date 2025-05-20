//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ARGS 10
#define MAX_LINE 1024

void print_usage() {
  printf("Usage: shell [options] [command] [arguments]\n");
  printf("Options:\n");
  printf("  -h, --help        Print this help message\n");
  printf("  -v, --verbose      Print verbose output\n");
  printf("  -c, --command      Execute the given command\n");
}

int main(int argc, char **argv) {
  int verbose = 0;
  int command_given = 0;
  char *command = NULL;

  // Parse command-line arguments
  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
      print_usage();
      return 0;
    } else if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--verbose") == 0) {
      verbose = 1;
    } else if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--command") == 0) {
      command_given = 1;
      command = argv[i + 1];
      i++; // Skip the next argument, which is the command itself
    } else {
      fprintf(stderr, "Unknown option: %s\n", argv[i]);
      print_usage();
      return 1;
    }
  }

  // If no command was given, print the prompt and wait for user input
  if (!command_given) {
    printf("$ ");
    fflush(stdout);

    char line[MAX_LINE];
    if (fgets(line, MAX_LINE, stdin) == NULL) {
      perror("fgets");
      return 1;
    }

    // Parse the user input into arguments
    char *args[MAX_ARGS];
    int num_args = 0;
    char *token = strtok(line, " ");
    while (token != NULL) {
      args[num_args++] = token;
      token = strtok(NULL, " ");
    }

    // Execute the command
    pid_t pid = fork();
    if (pid == 0) { // Child process
      execvp(args[0], args);
      perror("execvp");
      exit(1);
    } else if (pid > 0) { // Parent process
      int status;
      waitpid(pid, &status, 0);
      if (verbose) {
        printf("Command '%s' exited with status %d\n", args[0], status);
      }
    } else { // Error
      perror("fork");
      return 1;
    }
  } else { // A command was given as an argument
    // Execute the command
    pid_t pid = fork();
    if (pid == 0) { // Child process
      execlp(command, command, NULL);
      perror("execlp");
      exit(1);
    } else if (pid > 0) { // Parent process
      int status;
      waitpid(pid, &status, 0);
      if (verbose) {
        printf("Command '%s' exited with status %d\n", command, status);
      }
    } else { // Error
      perror("fork");
      return 1;
    }
  }

  return 0;
}