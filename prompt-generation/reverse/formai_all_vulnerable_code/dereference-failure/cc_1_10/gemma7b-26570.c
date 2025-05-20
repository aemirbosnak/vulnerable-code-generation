//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX_HISTORY 10

typedef struct CalculatorHistory {
  char **commands;
  int size;
} CalculatorHistory;

CalculatorHistory *history = NULL;

void addToHistory(char *command) {
  if (history == NULL) {
    history = malloc(sizeof(CalculatorHistory));
    history->commands = malloc(MAX_HISTORY * sizeof(char *));
    history->size = 0;
  }

  if (history->size >= MAX_HISTORY) {
    free(history->commands);
    history->commands = malloc(MAX_HISTORY * sizeof(char *));
  }

  history->commands[history->size++] = command;
}

void printHistory() {
  if (history != NULL) {
    for (int i = 0; i < history->size; i++) {
      printf("%s\n", history->commands[i]);
    }
  }
}

int main() {
  char input[256];
  char *command;

  printf("Welcome to the Cybernetic Calculator!\n");

  while (1) {
    printf("Enter your command: ");
    scanf("%s", input);

    command = strdup(input);

    addToHistory(command);

    switch (command[0]) {
      case 'a':
        printf("Adding two numbers: %s\n", command);
        break;
      case 's':
        printf("Subtracting two numbers: %s\n", command);
        break;
      case 'm':
        printf("Multiplying two numbers: %s\n", command);
        break;
      case 'd':
        printf("Dividing two numbers: %s\n", command);
        break;
      case 'h':
        printHistory();
        break;
      default:
        printf("Invalid command. Please try again.\n");
    }
  }

  return 0;
}