//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_BAG_WEIGHT 50

typedef struct Bag {
  char *name;
  int weight;
  struct Bag *next;
} Bag;

Bag *createBag(char *name, int weight) {
  Bag *newBag = (Bag *)malloc(sizeof(Bag));
  newBag->name = name;
  newBag->weight = weight;
  newBag->next = NULL;
  return newBag;
}

void handleBags(Bag *head) {
  while (head) {
    printf("Bag name: %s, weight: %d\n", head->name, head->weight);
    head = head->next;
  }
}

int main() {
  srand(time(NULL));
  Bag *head = NULL;

  // Create a few bags
  for (int i = 0; i < MAX_BAGS; i++) {
    char name[20];
    sprintf(name, "Bag %d", i + 1);
    int weight = rand() % MAX_BAG_WEIGHT;
    Bag *newBag = createBag(name, weight);
    if (head == NULL) {
      head = newBag;
    } else {
      newBag->next = head;
      head = newBag;
    }
  }

  // Handle the bags
  handleBags(head);

  return 0;
}