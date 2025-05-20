//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE_LENGTH 1024

// Function to split a string into an array of strings
char **split_string(char *str, char *delimiter) {
  char **result = malloc(sizeof(char *) * MAX_LINE_LENGTH);
  int i = 0;
  char *token = strtok(str, delimiter);
  while (token != NULL) {
    result[i] = token;
    i++;
    token = strtok(NULL, delimiter);
  }
  result[i] = NULL;
  return result;
}

int main() {
  // The great detective's prompt
  printf("\nElementary, my dear Watson! Enter your commands below:\n");

  // The loop that keeps the shell running
  while (1) {
    // The magnifying glass for user input
    char line[MAX_LINE_LENGTH];
    printf("> ");
    fgets(line, MAX_LINE_LENGTH, stdin);

    // The magnifying glass for the arguments
    char **args = split_string(line, " ");

    // If the user wants to quit, we bid them farewell
    if (strcmp(args[0], "exit") == 0) {
      printf("Until next time, my dear Watson!\n");
      break;
    }

    // Otherwise, we summon the hounds of Unix
    pid_t pid = fork();
    if (pid == 0) {
      // The hound's keen sense of smell
      execvp(args[0], args);
      printf("Elementary, my dear Watson! The command '%s' was not found.\n", args[0]);
      exit(1);
    } else {
      // The detective's keen observation
      int status;
      waitpid(pid, &status, 0);
    }
  }

  return 0;
}