//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Claude Shannon
#include <stdlib.h>
#include <time.h>

#define MAX_PASSENGERS 100
#define MAX_BAGS 50

typedef struct Passenger {
  char name[50];
  int numBags;
  struct Passenger* next;
} Passenger;

typedef struct Bag {
  char label[50];
  struct Bag* next;
} Bag;

Passenger* headPassenger = NULL;
Bag* headBag = NULL;

void addPassenger(char* name, int numBags) {
  Passenger* newPassenger = (Passenger*)malloc(sizeof(Passenger));
  strcpy(newPassenger->name, name);
  newPassenger->numBags = numBags;
  newPassenger->next = headPassenger;
  headPassenger = newPassenger;
}

void addBag(char* label) {
  Bag* newBag = (Bag*)malloc(sizeof(Bag));
  strcpy(newBag->label, label);
  newBag->next = headBag;
  headBag = newBag;
}

void simulate() {
  int numPassengers = rand() % MAX_PASSENGERS;
  for (int i = 0; i < numPassengers; i++) {
    addPassenger("Passenger", rand() % MAX_BAGS);
  }

  int numBags = rand() % MAX_BAGS;
  for (int i = 0; i < numBags; i++) {
    addBag("Bag");
  }

  printf("Number of passengers: %d\n", numPassengers);
  printf("Number of bags: %d\n", numBags);
  printf("Passengers:\n");
  for (Passenger* passenger = headPassenger; passenger; passenger = passenger->next) {
    printf("%s has %d bags\n", passenger->name, passenger->numBags);
  }
  printf("Bags:\n");
  for (Bag* bag = headBag; bag; bag = bag->next) {
    printf("%s\n", bag->label);
  }
}

int main() {
  simulate();
  return 0;
}