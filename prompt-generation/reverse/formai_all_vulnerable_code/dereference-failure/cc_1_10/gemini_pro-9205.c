//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// Built-in commands
#define CD "cd"
#define LS "ls"
#define PWD "pwd"
#define EXIT "exit"

// Maximum command length
#define MAX_CMD_LEN 1024

// Main function
int main() {
  // Welcome message
  printf("\nWelcome to the Cuckoo Shell!\n");
  printf("Type 'help' for a list of commands.\n\n");

  // Main loop
  while (1) {
    // Prompt
    printf("Cuckoo> ");

    // Get command
    char cmd[MAX_CMD_LEN];
    fgets(cmd, MAX_CMD_LEN, stdin);

    // Parse command
    char *argv[10]; // Maximum 10 arguments
    int argc = 0;
    char *token = strtok(cmd, " ");
    while (token) {
      argv[argc++] = token;
      token = strtok(NULL, " ");
    }

    // Built-in commands
    if (!strcmp(argv[0], CD)) {
      if (argc == 2) {
        chdir(argv[1]);
      } else {
        printf("Usage: cd <directory>\n");
      }
    } else if (!strcmp(argv[0], LS)) {
      system("ls -lh");
    } else if (!strcmp(argv[0], PWD)) {
      char cwd[1024];
      getcwd(cwd, sizeof(cwd));
      printf("%s\n", cwd);
    } else if (!strcmp(argv[0], EXIT)) {
      printf("Exiting the Cuckoo Shell.\n");
      exit(0);
    } else {
      // External command
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
      } else {
        perror("fork");
      }
    }
  }

  return 0;
}