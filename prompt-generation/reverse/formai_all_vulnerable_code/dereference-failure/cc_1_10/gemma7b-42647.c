//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Linus Torvalds
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_BAGS 10
#define MAX_WEIGHT 20

typedef struct Bag {
  char *name;
  int weight;
  struct Bag *next;
} Bag;

Bag *create_bag(char *name, int weight) {
  Bag *new_bag = malloc(sizeof(Bag));
  new_bag->name = name;
  new_bag->weight = weight;
  new_bag->next = NULL;
  return new_bag;
}

void handle_baggage(Bag *bags) {
  printf("List of bags:\n");
  for (Bag *bag = bags; bag; bag = bag->next) {
    printf("  - %s (%d kg)\n", bag->name, bag->weight);
  }

  int total_weight = 0;
  for (Bag *bag = bags; bag; bag = bag->next) {
    total_weight += bag->weight;
  }

  printf("Total weight: %d kg\n", total_weight);

  time_t now = time(NULL);
  printf("Time: %s\n", now);
}

int main() {
  Bag *bags = NULL;

  // Create some bags
  bags = create_bag("John Doe's suitcase", 15);
  bags = create_bag("Jane Doe's handbag", 10);
  bags = create_bag("Bill Smith's backpack", 12);

  // Handle baggage
  handle_baggage(bags);

  return 0;
}