//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_HISTORY_SIZE 10

typedef struct HistoryEntry {
  char *command;
  struct HistoryEntry *next;
} HistoryEntry;

HistoryEntry *history = NULL;

void add_history(char *command) {
  HistoryEntry *new_entry = malloc(sizeof(HistoryEntry));
  new_entry->command = strdup(command);
  new_entry->next = history;
  history = new_entry;
  if (history->next) {
    free(history->next);
  }
  if (history) {
    history->next = NULL;
  }
}

void print_history() {
  HistoryEntry *current = history;
  printf("History:\n");
  while (current) {
    printf("%s\n", current->command);
    current = current->next;
  }
}

int main() {
  char prompt[] = "shell$ ";
  char command[1024];
  int history_size = 0;

  while (1) {
    printf("%s", prompt);
    fgets(command, 1024, stdin);

    add_history(command);

    if (strcmp(command, "exit") == 0) {
      printf("Goodbye!\n");
      exit(0);
    } else if (strcmp(command, "history") == 0) {
      print_history();
    } else {
      system(command);
    }

    history_size++;
    if (history_size >= MAX_HISTORY_SIZE) {
      free(history->next);
      history = history->next;
    }
  }

  return 0;
}