//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: high level of detail
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_BAGS 10
#define MAX_WEIGHT 50

typedef struct Bag {
  char* name;
  int weight;
  struct Bag* next;
} Bag;

Bag* CreateBag(char* name, int weight) {
  Bag* newBag = malloc(sizeof(Bag));
  newBag->name = name;
  newBag->weight = weight;
  newBag->next = NULL;
  return newBag;
}

void AddBag(Bag* head, char* name, int weight) {
  Bag* newBag = CreateBag(name, weight);
  if (head == NULL) {
    head = newBag;
  } else {
    newBag->next = head;
    head = newBag;
  }
}

void HandleBags(Bag* head) {
  printf("Bags: ");
  for (Bag* currentBag = head; currentBag; currentBag = currentBag->next) {
    printf("%s (%d) ", currentBag->name, currentBag->weight);
  }
  printf("\n");
}

int main() {
  Bag* head = NULL;
  AddBag(head, "John Doe's Bag", 25);
  AddBag(head, "Jane Doe's Bag", 30);
  AddBag(head, "Peter Pan's Bag", 15);
  AddBag(head, "The Cat in the Hat's Bag", 40);

  HandleBags(head);

  return 0;
}