//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct baggage_item {
  char *name;
  int weight;
  struct baggage_item *next;
} baggage_item;

typedef struct baggage_handler {
  baggage_item *head;
  int total_weight;
  struct baggage_handler *next;
} baggage_handler;

void add_baggage(baggage_handler *handler, char *name, int weight) {
  baggage_item *new_item = malloc(sizeof(baggage_item));
  new_item->name = strdup(name);
  new_item->weight = weight;
  new_item->next = NULL;

  if (handler->head == NULL) {
    handler->head = new_item;
  } else {
    handler->head->next = new_item;
  }

  handler->total_weight += weight;
}

void print_baggage(baggage_handler *handler) {
  baggage_item *item = handler->head;
  while (item) {
    printf("%s (%.2f kg)\n", item->name, item->weight);
    item = item->next;
  }
}

void calculate_total_weight(baggage_handler *handler) {
  handler->total_weight = 0;
  baggage_item *item = handler->head;
  while (item) {
    handler->total_weight += item->weight;
    item = item->next;
  }
}

int main() {
  time_t t = time(NULL);
  srand(t);

  baggage_handler *handler = malloc(sizeof(baggage_handler));
  handler->head = NULL;
  handler->total_weight = 0;
  handler->next = NULL;

  // Simulate baggage handling
  for (int i = 0; i < 10; i++) {
    add_baggage(handler, "Item", rand() % 20);
  }

  // Print baggage
  print_baggage(handler);

  // Calculate total weight
  calculate_total_weight(handler);

  // Print total weight
  printf("Total weight: %.2f kg\n", handler->total_weight);

  return 0;
}