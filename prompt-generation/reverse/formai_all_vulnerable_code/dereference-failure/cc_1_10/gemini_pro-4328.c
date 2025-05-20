//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <signal.h>

#define MAX_LINE 1024
#define MAX_ARGS 128

// Function to parse input into an array of arguments
char** parse_args(char* line) {
  char** args = malloc(sizeof(char*) * MAX_ARGS);
  char* arg;
  int i = 0;
  while ((arg = strtok(line, " ")) != NULL) {
    args[i++] = arg;
  }
  args[i] = NULL;
  return args;
}

// Function to execute a command
void execute_command(char** args) {
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork");
    exit(1);
  } else if (pid == 0) {
    execvp(args[0], args);
    perror("execvp");
    exit(1);
  } else {
    wait(NULL);
  }
}

// Function to handle built-in commands
int handle_builtin(char** args) {
  if (strcmp(args[0], "exit") == 0) {
    exit(0);
  } else if (strcmp(args[0], "cd") == 0) {
    if (args[1] == NULL) {
      chdir(getenv("HOME"));
    } else {
      chdir(args[1]);
    }
    return 1;
  }
  return 0;
}

// Main function
int main(void) {
  char line[MAX_LINE];
  char** args;
  int status = 1;
  
  // Greetings
  printf("Welcome to the Cosmic Shell, my friend!\n");
  printf("Prepare for an epic adventure through the digital stars!\n\n");
  
  // Main loop
  while (status) {
    
    // Prompt the user
    printf("--> ");
    fflush(stdout);
    
    // Read the input
    if (fgets(line, MAX_LINE, stdin) == NULL) {
      break;
    }
    
    // Parse the input
    args = parse_args(line);
    
    // Handle built-in commands
    if (handle_builtin(args)) {
      continue;
    }
    
    // Execute the command
    execute_command(args);
  }
  
  // Farewell message
  printf("\nMay your cosmic journey be filled with joy and wonder!\n");
  
  return 0;
}