//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 10
#define MAX_WEIGHT 20

typedef struct Bag {
  int weight;
  char *name;
  struct Bag *next;
} Bag;

void handle_baggage(Bag **head) {
  // Calculate total weight of bags
  int total_weight = 0;
  for (Bag *bag = *head; bag; bag = bag->next) {
    total_weight += bag->weight;
  }

  // Check if total weight exceeds allowed limit
  if (total_weight > MAX_WEIGHT) {
    printf("Total weight exceeds limit of %d. Please reduce the weight of your bags.\n", MAX_WEIGHT);
  } else {
    printf("Total weight: %d\n", total_weight);
  }

  // Print bag names
  for (Bag *bag = *head; bag; bag = bag->next) {
    printf("Bag name: %s\n", bag->name);
  }
}

int main() {
  // Create a linked list of bags
  Bag *head = NULL;
  for (int i = 0; i < MAX_BAGS; i++) {
    Bag *new_bag = malloc(sizeof(Bag));
    new_bag->weight = rand() % MAX_WEIGHT;
    new_bag->name = malloc(20);
    sprintf(new_bag->name, "Bag %d", i + 1);
    new_bag->next = head;
    head = new_bag;
  }

  // Handle baggage
  handle_baggage(&head);

  return 0;
}