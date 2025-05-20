//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 10

typedef struct Bag {
  char* name;
  int weight;
  struct Bag* next;
} Bag;

void insertBag(Bag** head, char* name, int weight) {
  Bag* newBag = malloc(sizeof(Bag));
  newBag->name = strdup(name);
  newBag->weight = weight;
  newBag->next = NULL;

  if (*head == NULL) {
    *head = newBag;
  } else {
    (*head)->next = newBag;
  }
}

void handleBags(Bag** head) {
  time_t start = time(NULL);

  while (*head) {
    printf("Processing bag: %s (%d kg)\n", (*head)->name, (*head)->weight);
    sleep(rand() % 5);
    free((*head)->name);
    free(*head);
    *head = (*head)->next;
  }

  time_t end = time(NULL);
  printf("Time taken: %ld seconds\n", end - start);
}

int main() {
  Bag* head = NULL;

  insertBag(&head, "John Doe's suitcase", 20);
  insertBag(&head, "Jane Doe's backpack", 15);
  insertBag(&head, "Peter Pan's hat", 5);

  handleBags(&head);

  return 0;
}