//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDLES 10

typedef struct Candle {
  char name[20];
  int remaining_wax;
  int burned_wax;
  struct Candle* next;
} Candle;

void initialize_candles(Candle** head) {
  *head = NULL;
}

void add_candle(Candle** head, char* name, int wax) {
  Candle* new_candle = malloc(sizeof(Candle));
  strcpy(new_candle->name, name);
  new_candle->remaining_wax = wax;
  new_candle->burned_wax = 0;
  new_candle->next = NULL;

  if (*head == NULL) {
    *head = new_candle;
  } else {
    ((*head)->next = new_candle);
    *head = new_candle;
  }
}

void burn_candle(Candle** head, char* name) {
  Candle* current_candle = *head;

  while (current_candle) {
    if (strcmp(current_candle->name, name) == 0) {
      int burn_amount = rand() % MAX_CANDLES;
      current_candle->burned_wax += burn_amount;
      printf("Candle '%s' burned %d wax.\n", current_candle->name, burn_amount);
      break;
    }
    current_candle = current_candle->next;
  }

  if (current_candle == NULL) {
    printf("Candle not found.\n");
  }
}

int main() {
  Candle* head = NULL;
  initialize_candles(&head);

  add_candle(&head, "Candle A", 50);
  add_candle(&head, "Candle B", 20);
  add_candle(&head, "Candle C", 30);

  burn_candle(&head, "Candle A");
  burn_candle(&head, "Candle B");

  return 0;
}