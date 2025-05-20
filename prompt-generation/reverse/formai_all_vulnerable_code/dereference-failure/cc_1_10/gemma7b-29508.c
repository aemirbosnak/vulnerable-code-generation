//Gemma-7B DATASET v1.0 Category: System administration ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 255
#define MAX_HISTORY_SIZE 10

typedef struct CommandHistory {
  char **commands;
  int size;
} CommandHistory;

CommandHistory *initCommandHistory() {
  CommandHistory *history = malloc(sizeof(CommandHistory));
  history->commands = malloc(MAX_HISTORY_SIZE * sizeof(char *));
  history->size = 0;
  return history;
}

void addToCommandHistory(CommandHistory *history, char *command) {
  history->commands[history->size++] = strdup(command);
  if (history->size >= MAX_HISTORY_SIZE) {
    free(history->commands[0]);
    history->commands = realloc(history->commands, MAX_HISTORY_SIZE * sizeof(char *));
  }
}

int main() {
  CommandHistory *history = initCommandHistory();

  char command[MAX_CMD_LEN];

  while (1) {
    printf("$ ");
    scanf("%s", command);

    if (!strcmp(command, "exit")) {
      exit(0);
    }

    addToCommandHistory(history, command);

    printf("Command history: \n");
    for (int i = 0; i < history->size; i++) {
      printf("%d. %s\n", i + 1, history->commands[i]);
    }
  }

  return 0;
}