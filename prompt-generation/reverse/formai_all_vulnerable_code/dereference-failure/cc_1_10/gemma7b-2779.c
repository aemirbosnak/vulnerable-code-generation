//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSENGERS 10
#define MAX_BAGS 20

typedef struct Passenger {
  char name[50];
  int numBags;
  struct Passenger* next;
} Passenger;

typedef struct Bag {
  char tag[20];
  int weight;
  struct Bag* next;
} Bag;

void simulate_airport() {
  Passenger* head = NULL;
  Bag* tail = NULL;

  // Simulate passenger arrival
  for (int i = 0; i < MAX_PASSENGERS; i++) {
    Passenger* passenger = (Passenger*)malloc(sizeof(Passenger));
    passenger->numBags = rand() % MAX_BAGS;
    passenger->next = head;
    head = passenger;
  }

  // Simulate baggage handling
  for (Passenger* passenger = head; passenger; passenger = passenger->next) {
    for (int i = 0; i < passenger->numBags; i++) {
      Bag* bag = (Bag*)malloc(sizeof(Bag));
      bag->weight = rand() % 50;
      bag->next = tail;
      tail = bag;
    }
  }

  // Print passenger information
  for (Passenger* passenger = head; passenger; passenger = passenger->next) {
    printf("Passenger: %s, Number of bags: %d\n", passenger->name, passenger->numBags);
  }

  // Print baggage information
  for (Bag* bag = tail; bag; bag = bag->next) {
    printf("Bag tag: %s, Weight: %d\n", bag->tag, bag->weight);
  }
}

int main() {
  simulate_airport();

  return 0;
}