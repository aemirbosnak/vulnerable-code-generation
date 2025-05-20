//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: scalable
#include <stdlib.h>
#include <stdio.h>
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

Passenger* createPassenger(char* name, int numBags) {
  Passenger* newPassenger = (Passenger*)malloc(sizeof(Passenger));
  strcpy(newPassenger->name, name);
  newPassenger->numBags = numBags;
  newPassenger->next = NULL;
  return newPassenger;
}

Bag* createBag(char* contents) {
  Bag* newBag = (Bag*)malloc(sizeof(Bag));
  strcpy(newBag->contents, contents);
  newBag->next = NULL;
  return newBag;
}

void simulateBaggageHandling() {
  // Create a list of passengers
  Passenger* head = createPassenger("John Doe", 3);
  head->next = createPassenger("Jane Doe", 2);
  head->next->next = createPassenger("Peter Pan", 4);

  // Create a list of bags
  Bag* bagHead = createBag("Clothes");
  bagHead->next = createBag("Electronics");
  bagHead->next->next = createBag("Toiletries");

  // Simulate baggage handling
  srand(time(NULL));
  for (int i = 0; i < 100; i++) {
    int passengerIndex = rand() % MAX_PASSENGERS;
    int bagIndex = rand() % MAX_BAGS;

    Passenger* passenger = head;
    for (int j = 0; j < passengerIndex; j++) {
      passenger = passenger->next;
    }

    Bag* bag = bagHead;
    for (int j = 0; j < bagIndex; j++) {
      bag = bag->next;
    }

    printf("%s is retrieving bag %s.\n", passenger->name, bag->contents);
  }
}

int main() {
  simulateBaggageHandling();
  return 0;
}