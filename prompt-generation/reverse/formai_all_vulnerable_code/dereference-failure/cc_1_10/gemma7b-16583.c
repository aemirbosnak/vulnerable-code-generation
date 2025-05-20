//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: puzzling
#include <stdlib.h>
#include <time.h>

#define MAX_PASSENGERS 10
#define MAX_BAGS 20

typedef struct Passenger {
  char name[20];
  int numBags;
  struct Passenger* next;
} Passenger;

typedef struct Bag {
  char content[100];
  struct Bag* next;
} Bag;

Passenger* head = NULL;
Bag* tail = NULL;

void addPassenger(char* name, int numBags) {
  Passenger* newPassenger = malloc(sizeof(Passenger));
  strcpy(newPassenger->name, name);
  newPassenger->numBags = numBags;
  newPassenger->next = head;
  head = newPassenger;
}

void addBag(char* content) {
  Bag* newBag = malloc(sizeof(Bag));
  strcpy(newBag->content, content);
  newBag->next = tail;
  tail = newBag;
}

void simulateBaggageHandling() {
  int i = 0;
  srand(time(NULL));
  for (i = 0; i < MAX_PASSENGERS; i++) {
    addPassenger("Passenger " + i, rand() % MAX_BAGS);
  }

  for (i = 0; i < MAX_BAGS; i++) {
    addBag("Bag content " + i);
  }

  for (Passenger* passenger = head; passenger; passenger = passenger->next) {
    int numBags = passenger->numBags;
    for (int j = 0; j < numBags; j++) {
      for (Bag* bag = tail; bag; bag = bag->next) {
        if (strcmp(bag->content, passenger->name) == 0) {
          printf("Passenger: %s, Bag: %s\n", passenger->name, bag->content);
        }
      }
    }
  }
}

int main() {
  simulateBaggageHandling();
  return 0;
}