//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 10
#define MAX_WEIGHT 50

typedef struct Bag {
  char *name;
  int weight;
  struct Bag *next;
} Bag;

void createBag(Bag **head) {
  *head = malloc(sizeof(Bag));
  (*head)->name = "John Doe's Bag";
  (*head)->weight = 20;
  (*head)->next = NULL;
}

void addBag(Bag **head, char *name, int weight) {
  Bag *newBag = malloc(sizeof(Bag));
  newBag->name = name;
  newBag->weight = weight;
  newBag->next = NULL;

  if (*head == NULL) {
    *head = newBag;
  } else {
    (*head)->next = newBag;
  }
}

void handleBags(Bag *head) {
  while (head) {
    printf("Bag name: %s, Weight: %d\n", head->name, head->weight);
    head = head->next;
  }
}

int main() {
  Bag *head = NULL;
  createBag(&head);
  addBag(head, "Jane Doe's Bag", 30);
  addBag(head, "Peter Pan's Bag", 40);
  addBag(head, "Captain America's Bag", 25);

  handleBags(head);

  return 0;
}