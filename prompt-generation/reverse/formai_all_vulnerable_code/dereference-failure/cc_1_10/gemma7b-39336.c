//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDLES 20

typedef struct Candle {
  char name[20];
  int remaining_wax;
  struct Candle* next;
} Candle;

Candle* create_candle(char* name, int wax) {
  Candle* candle = malloc(sizeof(Candle));
  strcpy(candle->name, name);
  candle->remaining_wax = wax;
  candle->next = NULL;
  return candle;
}

void add_candle(Candle* head, char* name, int wax) {
  Candle* new_candle = create_candle(name, wax);
  if (head) {
    head->next = new_candle;
  } else {
    head = new_candle;
  }
  head = new_candle;
}

void burn_candle(Candle* candle) {
  candle->remaining_wax--;
  if (candle->remaining_wax == 0) {
    printf("Candle: %s has burned out.\n", candle->name);
    free(candle);
  } else {
    printf("Candle: %s has burned for %d hours.\n", candle->name, candle->remaining_wax);
  }
}

int main() {
  Candle* head = NULL;

  // Create and add candles
  add_candle(head, "Candle A", 100);
  add_candle(head, "Candle B", 75);
  add_candle(head, "Candle C", 50);

  // Burn candles
  burn_candle(head->next);
  burn_candle(head);

  return 0;
}