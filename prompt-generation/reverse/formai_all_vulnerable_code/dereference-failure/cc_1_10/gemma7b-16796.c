//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 1024

typedef struct CmdLine {
  char **argv;
  char **history;
  int pos;
  int histSize;
} CmdLine;

CmdLine *cmdLine = NULL;

void initCmdLine() {
  cmdLine = malloc(sizeof(CmdLine));
  cmdLine->argv = NULL;
  cmdLine->history = NULL;
  cmdLine->pos = 0;
  cmdLine->histSize = 0;
}

void addCmdLineArg(char *arg) {
  cmdLine->argv = realloc(cmdLine->argv, (cmdLine->pos + 1) * sizeof(char *));
  cmdLine->argv[cmdLine->pos++] = arg;
}

void saveCmdLineHistory(char *cmd) {
  cmdLine->history = realloc(cmdLine->history, (cmdLine->histSize + 1) * sizeof(char *));
  cmdLine->history[cmdLine->histSize++] = cmd;
}

int main() {
  initCmdLine();

  char cmd[MAX_CMD_LEN];

  while (1) {
    printf("$ ");
    fgets(cmd, MAX_CMD_LEN, stdin);

    char *argv[MAX_CMD_LEN] = {};
    char *history[MAX_CMD_LEN] = {};

    char *cmdPtr = cmd;
    char *arg = NULL;

    while (*cmdPtr) {
      if (*cmdPtr == ' ') {
        arg = NULL;
        argv[cmdLine->pos++] = cmdPtr;
      } else if (arg == NULL) {
        arg = cmdPtr;
      } else {
        arg = realloc(arg, (cmdLine->pos + 1) * sizeof(char *));
        arg[cmdLine->pos++] = cmdPtr;
      }

      cmdPtr++;
    }

    saveCmdLineHistory(cmd);

    if (cmdLine->pos > 0) {
      execvp(argv[0], argv);
    } else {
      printf("Error: Invalid command.\n");
    }
  }

  return 0;
}