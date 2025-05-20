//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 10
#define MAX_WEIGHT 20

typedef struct Bag {
  char *name;
  int weight;
  struct Bag *next;
} Bag;

Bag *createBag(char *name, int weight) {
  Bag *newBag = malloc(sizeof(Bag));
  newBag->name = name;
  newBag->weight = weight;
  newBag->next = NULL;
  return newBag;
}

void addBag(Bag *head, char *name, int weight) {
  Bag *newBag = createBag(name, weight);
  if (head == NULL) {
    head = newBag;
  } else {
    newBag->next = head;
    head = newBag;
  }
}

void handleLuggage(Bag *head) {
  while (head) {
    printf("%s weighs %d pounds\n", head->name, head->weight);
    head = head->next;
  }
}

int main() {
  srand(time(NULL));
  Bag *bags = NULL;

  // Create a few bags
  addBag(bags, "John Doe's suitcase", rand() % MAX_WEIGHT);
  addBag(bags, "Mary Smith's backpack", rand() % MAX_WEIGHT);
  addBag(bags, "Bob Jones' carry-on", rand() % MAX_WEIGHT);

  // Handle the luggage
  handleLuggage(bags);

  return 0;
}