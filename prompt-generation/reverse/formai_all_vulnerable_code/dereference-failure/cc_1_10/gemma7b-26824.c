//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 10
#define MAX_BAG_WEIGHT 20

typedef struct Bag {
  char* name;
  int weight;
  struct Bag* next;
} Bag;

Bag* CreateBag(char* name, int weight) {
  Bag* newBag = (Bag*)malloc(sizeof(Bag));
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
  while (head) {
    printf("%s (%d) ", head->name, head->weight);
    head = head->next;
  }
  printf("\n");
}

int main() {
  srand(time(NULL));
  Bag* head = NULL;

  // Create a few bags
  AddBag(head, "John Doe's Bag", rand() % MAX_BAG_WEIGHT);
  AddBag(head, "Jane Doe's Bag", rand() % MAX_BAG_WEIGHT);
  AddBag(head, "Peter Pan's Bag", rand() % MAX_BAG_WEIGHT);

  // Handle the bags
  HandleBags(head);

  return 0;
}