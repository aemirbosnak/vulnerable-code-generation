//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: thoughtful
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_BAGS 10
#define MAX_WEIGHT 50

typedef struct Bag {
  char *name;
  int weight;
  struct Bag *next;
} Bag;

Bag *createBag(char *name, int weight) {
  Bag *newBag = (Bag *)malloc(sizeof(Bag));
  newBag->name = strdup(name);
  newBag->weight = weight;
  newBag->next = NULL;
  return newBag;
}

void addBag(Bag **head, char *name, int weight) {
  Bag *newBag = createBag(name, weight);
  if (*head == NULL) {
    *head = newBag;
  } else {
    (*head)->next = newBag;
  }
}

int calculateTotalWeight(Bag *head) {
  int totalWeight = 0;
  while (head) {
    totalWeight += head->weight;
    head = head->next;
  }
  return totalWeight;
}

int main() {
  Bag *bags = NULL;
  addBag(&bags, "John Doe's bag", 20);
  addBag(&bags, "Jane Doe's bag", 30);
  addBag(&bags, "Peter Pan's bag", 40);

  int totalWeight = calculateTotalWeight(bags);
  printf("Total weight: %d", totalWeight);

  return 0;
}