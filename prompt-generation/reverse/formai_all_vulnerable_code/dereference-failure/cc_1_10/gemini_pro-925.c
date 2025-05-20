//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ARGS 128

// Function to split a string into an array of strings
char** split_string(char* str, char* delim) {
  char** tokens = malloc(MAX_ARGS * sizeof(char*));
  char* token = strtok(str, delim);
  int i = 0;
  while (token != NULL) {
    tokens[i++] = token;
    token = strtok(NULL, delim);
  }
  tokens[i] = NULL;
  return tokens;
}

// Function to execute a command
int execute_command(char** args) {
  pid_t pid = fork();
  if (pid == -1) {
    perror("fork");
    return -1;
  } else if (pid == 0) {
    execvp(args[0], args);
    perror("execvp");
    exit(1);
  } else {
    int status;
    waitpid(pid, &status, 0);
    if (WIFEXITED(status)) {
      return WEXITSTATUS(status);
    } else {
      return -1;
    }
  }
}

// Main function
int main() {
  char* line = malloc(MAX_LINE_LENGTH);
  char** args;
  int status;
  
  while (1) {
    printf("> ");
    fflush(stdout);
    if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
      break;
    }
    
    args = split_string(line, " ");
    
    if (strcmp(args[0], "exit") == 0) {
      break;
    } else {
      status = execute_command(args);
      if (status == -1) {
        perror("execute_command");
      }
    }
    
    free(args);
  }
  
  free(line);
  return 0;
}