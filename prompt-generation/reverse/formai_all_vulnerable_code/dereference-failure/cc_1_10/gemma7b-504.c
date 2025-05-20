//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: ephemeral
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_Luggage_NUMBER 10

typedef struct baggage_item {
  char name[20];
  int weight;
  struct baggage_item* next;
} baggage_item;

baggage_item* create_baggage_item(char* name, int weight) {
  baggage_item* item = malloc(sizeof(baggage_item));
  strcpy(item->name, name);
  item->weight = weight;
  item->next = NULL;
  return item;
}

void handle_baggage(baggage_item* item) {
  printf("Handling baggage item: %s (%d kg)\n", item->name, item->weight);
  switch (item->weight) {
    case 1:
      printf("Item placed in overhead bin.\n");
      break;
    case 2:
      printf("Item placed in middle compartment.\n");
      break;
    case 3:
      printf("Item placed in bottom compartment.\n");
      break;
    default:
      printf("Error: invalid item weight.\n");
  }
}

int main() {
  srand(time(NULL));

  // Create a list of baggage items
  baggage_item* head = create_baggage_item("Laptop", 1);
  head->next = create_baggage_item("Toiletries", 2);
  head->next->next = create_baggage_item("Clothes", 3);

  // Handle each item
  handle_baggage(head);

  return 0;
}