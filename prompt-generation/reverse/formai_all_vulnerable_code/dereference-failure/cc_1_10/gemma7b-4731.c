//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_WEIGHT 50

typedef struct Bag {
  char name[20];
  int weight;
  struct Bag* next;
} Bag;

void main() {
  Bag* head = NULL;
  srand(time(NULL));

  // Simulate baggage check-in
  for (int i = 0; i < MAX_BAGS; i++) {
    Bag* new_bag = (Bag*)malloc(sizeof(Bag));
    new_bag->name[0] = 'A' + i;
    new_bag->weight = rand() % MAX_WEIGHT;

    if (head == NULL) {
      head = new_bag;
    } else {
      head->next = new_bag;
      head = new_bag;
    }
  }

  // Calculate total weight
  int total_weight = 0;
  for (Bag* current = head; current; current = current->next) {
    total_weight += current->weight;
  }

  // Print baggage information
  printf("Total weight: %d kg\n", total_weight);
  printf("List of bags:\n");
  for (Bag* current = head; current; current = current->next) {
    printf("  Bag name: %s, Weight: %d kg\n", current->name, current->weight);
  }

  // Simulate baggage loading
  printf("Loading bags onto the plane...\n");
  for (Bag* current = head; current; current = current->next) {
    printf("  Loading bag %s...\n", current->name);
  }

  // Simulate baggage unloading
  printf("Unloading bags from the plane...\n");
  for (Bag* current = head; current; current = current->next) {
    printf("  Unloading bag %s...\n", current->name);
  }

  // Free memory
  free(head);
}