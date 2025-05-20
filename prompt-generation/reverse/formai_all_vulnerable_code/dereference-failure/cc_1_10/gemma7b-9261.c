//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSENGERS 100
#define MAX_BAGS 20

typedef struct Passenger {
  char name[50];
  int numBags;
  struct Passenger* next;
} Passenger;

typedef struct Bag {
  char contents[100];
  struct Bag* next;
} Bag;

void simulateBaggageHandling(int numPassengers) {
  // Create a linked list of passengers
  Passenger* head = NULL;
  for (int i = 0; i < numPassengers; i++) {
    Passenger* newPassenger = (Passenger*)malloc(sizeof(Passenger));
    newPassenger->name[0] = 'A' + i;
    newPassenger->numBags = rand() % MAX_BAGS;
    newPassenger->next = head;
    head = newPassenger;
  }

  // Create a linked list of bags
  Bag* tail = NULL;
  for (Passenger* passenger = head; passenger; passenger++) {
    for (int i = 0; i < passenger->numBags; i++) {
      Bag* newBag = (Bag*)malloc(sizeof(Bag));
      newBag->contents[0] = 'a' + i;
      newBag->next = tail;
      tail = newBag;
    }
  }

  // Simulate baggage handling
  for (Bag* bag = tail; bag; bag = bag->next) {
    printf("Bag %c: %s\n", bag->contents[0], bag->contents);
  }
}

int main() {
  simulateBaggageHandling(50);
  return 0;
}