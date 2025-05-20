//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: ultraprecise
#include <stdlib.h>
#include <time.h>

struct baggage_item {
  char* name;
  int weight;
  struct baggage_item* next;
};

struct baggage_handler {
  struct baggage_item* head;
  int total_weight;
  time_t last_update;
};

void add_baggage_item(struct baggage_handler* handler, char* name, int weight) {
  struct baggage_item* item = malloc(sizeof(struct baggage_item));
  item->name = strdup(name);
  item->weight = weight;
  item->next = NULL;

  if (handler->head == NULL) {
    handler->head = item;
  } else {
    handler->head->next = item;
  }

  handler->total_weight += weight;
}

void update_baggage_handler(struct baggage_handler* handler) {
  handler->last_update = time(NULL);
}

int main() {
  struct baggage_handler handler;
  handler.head = NULL;
  handler.total_weight = 0;
  handler.last_update = 0;

  add_baggage_item(&handler, "Laptop", 20);
  add_baggage_item(&handler, "Shoes", 15);
  add_baggage_item(&handler, "Trolley", 30);

  update_baggage_handler(&handler);

  printf("Total weight: %d\n", handler.total_weight);
  printf("Last update: %ld\n", handler.last_update);

  return 0;
}