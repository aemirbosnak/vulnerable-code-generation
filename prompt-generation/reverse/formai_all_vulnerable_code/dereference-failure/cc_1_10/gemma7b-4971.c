//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 10
#define MAX_WAIT_TIME 5

typedef struct Bag {
  char* name;
  int weight;
  struct Bag* next;
} Bag;

void simulate_airport() {

  // Create a list of bags
  Bag* head = NULL;
  for (int i = 0; i < MAX_BAGS; i++) {
    head = malloc(sizeof(Bag));
    head->name = malloc(20);
    sprintf(head->name, "Bag %d", i);
    head->weight = rand() % MAX_WAIT_TIME;
    head->next = NULL;
    if (head) {
      head->next = head;
    }
  }

  // Simulate baggage handling
  time_t start_time = time(NULL);
  for (Bag* bag = head; bag; bag = bag->next) {
    printf("Bag %s is waiting for %d seconds.\n", bag->name, bag->weight);
    sleep(bag->weight);
  }

  // Calculate total time
  time_t end_time = time(NULL);
  int total_time = end_time - start_time;

  // Print total time
  printf("Total time: %d seconds.\n", total_time);

  // Free memory
  free(head);
}

int main() {

  simulate_airport();

  return 0;
}