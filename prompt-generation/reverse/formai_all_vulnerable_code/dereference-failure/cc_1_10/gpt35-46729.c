//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_COMMANDS 5

void executeCommand(char **args, int background) {
  pid_t pid = fork();
  if(pid == -1) {
    printf("Error forking process.\n");
    return;
  }

  if(pid == 0) {
    // Child process
    int status = execvp(args[0], args);
    if(status == -1) {
      printf("Error executing command.\n");
    }
    exit(0);
  } else {
    // Parent process
    if(background != 1) {
      int status;
      waitpid(pid, &status, 0);
    }
  }
}

void executeCommands(char *commands[MAX_COMMANDS][MAX_ARGS], int numCommands) {
  int i;
  int pipes[numCommands-1][2];
  for(i = 0; i < numCommands-1; i++) {
    pipe(pipes[i]);
  }

  for(i = 0; i < numCommands; i++) {
    pid_t pid = fork();
    if(pid == -1) {
      printf("Error forking process.\n");
      exit(1);
    }

    if(pid == 0) {
      // Child process
      if(i > 0) {
        close(pipes[i-1][1]);
        dup2(pipes[i-1][0], STDIN_FILENO);
      }

      if(i < numCommands-1) {
        close(pipes[i][0]);
        dup2(pipes[i][1], STDOUT_FILENO);
      }

      int status = execvp(commands[i][0], commands[i]);
      if(status == -1) {
        printf("Error executing command.\n");
        exit(1);
      }
    }
  }

  for(i = 0; i < numCommands-1; i++) {
    close(pipes[i][0]);
    close(pipes[i][1]);
  }

  for(i = 0; i < numCommands; i++) {
    int status;
    wait(&status);
  }
}

int main() {
  char input[1024];
  char **args = malloc(MAX_ARGS * sizeof(char *));
  int background = 0;
  int status = 0;
  int i;

  while(1) {
    printf("> ");
    fgets(input, 1024, stdin);
    input[strlen(input)-1] = '\0';

    if(strcmp(input, "exit") == 0) {
      break;
    }

    char *commands[MAX_COMMANDS][MAX_ARGS];
    int numCommands = 0;

    char *token = strtok(input, " ");
    while(token != NULL) {
      if(strcmp(token, "&") == 0) {
        background = 1;
        break;
      }

      if(strcmp(token, "|") == 0) {
        numCommands++;
      } else {
        args[status++] = token;
      }

      token = strtok(NULL, " ");
    }

    args[status] = NULL;

    if(numCommands == 0) {
      executeCommand(args, background);
    } else {
      char *prevArg[MAX_ARGS];
      int prevStatus = 0;
      for(i = 0; i < status; i++) {
        prevArg[prevStatus++] = args[i];
        if(strcmp(args[i], "|") == 0) {
          prevArg[prevStatus-1] = NULL;
          memcpy(commands[numCommands], prevArg, prevStatus * sizeof(char *));
          prevStatus = 0;
          numCommands++;
        }
      }

      prevArg[prevStatus++] = args[i];
      prevArg[prevStatus] = NULL;
      memcpy(commands[numCommands], prevArg, (prevStatus+1) * sizeof(char *));

      executeCommands(commands, numCommands+1);
    }

    background = 0;
    status = 0;
    memset(args, 0, MAX_ARGS * sizeof(char *));
  }

  free(args);
  return 0;
}