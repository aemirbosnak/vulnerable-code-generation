//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 512
#define MAX_ARGS 10

/* Function to tokenize the input command */
char** tokenize(char* cmd) {
  char** tokens = malloc(MAX_ARGS * sizeof(char*));
  char* token;
  int i = 0;
  
  token = strtok(cmd, " \n\t");
  while (token != NULL) {
    tokens[i] = token;
    i++;
    
    if (i >= MAX_ARGS) {
      printf("Too many arguments.\n");
      return NULL;
    }
    
    token = strtok(NULL, " \n\t");
  }
  
  tokens[i] = NULL;
  
  return tokens;
}

/* Function to execute a command */
void execute(char** argv) {
  pid_t pid = fork();
  
  if (pid == 0) {
    /* Child process: execute command */
    if (execvp(argv[0], argv) == -1) {
      printf("Command not found.\n");
      exit(EXIT_FAILURE);
    }
  } else if (pid < 0) {
    /* Error forking */
    printf("Error forking.\n");
    exit(EXIT_FAILURE);
  } else {
    /* Parent process: wait for child to finish */
    int status;
    waitpid(pid, &status, 0);
  }
}

int main() {
  char cmd[MAX_CMD_LENGTH];
  char** argv;
  
  printf("Welcome to Puzzling Shell!\n");
  printf("Enter a command (or 'exit' to quit):\n");
  
  while (1) {
    /* Read input */
    fgets(cmd, MAX_CMD_LENGTH, stdin);
    
    /* Exit if 'exit' command entered */
    if (strcmp(cmd, "exit\n") == 0) {
      break;
    }
    
    /* Tokenize input */
    argv = tokenize(cmd);
    if (argv == NULL) {
      continue;
    }
    
    /* Execute command */
    execute(argv);
    
    /* Free memory */
    free(argv);
  }
  
  printf("Goodbye!\n");
  
  return 0;
}