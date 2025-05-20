//Gemma-7B DATASET v1.0 Category: System administration ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024
#define MAX_HISTORY_LEN 10

typedef struct CommandHistory {
  char **commands;
  int size;
} CommandHistory;

CommandHistory *createCommandHistory() {
  CommandHistory *history = malloc(sizeof(CommandHistory));
  history->commands = malloc(MAX_HISTORY_LEN * sizeof(char *));
  history->size = 0;
  return history;
}

void addCommandToHistory(CommandHistory *history, char *command) {
  history->commands[history->size++] = strdup(command);
}

int executeCommand(CommandHistory *history, char *command) {
  for (int i = 0; i < history->size; i++) {
    if (strcmp(command, history->commands[i]) == 0) {
      return 1;
    }
  }
  return 0;
}

int main() {
  CommandHistory *history = createCommandHistory();

  char cmd[MAX_CMD_LEN];

  while (1) {
    printf("$ ");
    fgets(cmd, MAX_CMD_LEN, stdin);

    if (strcmp(cmd, "exit") == 0) {
      exit(0);
    }

    addCommandToHistory(history, cmd);

    if (executeCommand(history, cmd)) {
      printf("Command already executed.\n");
    } else {
      printf("Command not found.\n");
    }
  }

  return 0;
}