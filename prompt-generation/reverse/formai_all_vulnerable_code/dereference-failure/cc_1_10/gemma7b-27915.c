//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: active
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 10
#define MAX_BAG_WEIGHT 20

typedef struct Bag {
  char *name;
  int weight;
  struct Bag *next;
} Bag;

Bag *createBag(char *name, int weight) {
  Bag *newBag = malloc(sizeof(Bag));
  newBag->name = strdup(name);
  newBag->weight = weight;
  newBag->next = NULL;
  return newBag;
}

void handleBag(Bag *bag) {
  printf("Handling bag: %s, weight: %d\n", bag->name, bag->weight);
  if (bag->weight > MAX_BAG_WEIGHT) {
    printf("Bag is overweight!\n");
  } else {
    printf("Bag is within weight limits.\n");
  }
}

int main() {
  srand(time(NULL));
  Bag *head = NULL;

  // Create a few bags
  for (int i = 0; i < MAX_BAGS; i++) {
    char *name = "Bag " + i;
    int weight = rand() % MAX_BAG_WEIGHT;
    Bag *newBag = createBag(name, weight);
    if (head == NULL) {
      head = newBag;
    } else {
      newBag->next = head;
      head = newBag;
    }
  }

  // Handle each bag
  for (Bag *bag = head; bag; bag = bag->next) {
    handleBag(bag);
  }

  return 0;
}