//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSENGERS 100

typedef struct Passenger {
  char name[50];
  int baggage_weight;
  struct Passenger* next;
} Passenger;

void addPassenger(Passenger** head) {
  Passenger* newPassenger = (Passenger*)malloc(sizeof(Passenger));
  newPassenger->next = NULL;

  if (*head == NULL) {
    *head = newPassenger;
  } else {
    (*head)->next = newPassenger;
    *head = newPassenger;
  }
}

void handleBaggage(Passenger* passenger) {
  int baggage_weight = passenger->baggage_weight;
  if (baggage_weight > 50) {
    printf("%s, your baggage weight is too high. You will have to pay extra fees.\n", passenger->name);
  } else {
    printf("%s, your baggage weight is within the allowed limit.\n", passenger->name);
  }
}

int main() {
  Passenger* head = NULL;
  int numPassengers = 0;

  // Simulate passenger arrival
  for (int i = 0; i < MAX_PASSENGERS; i++) {
    addPassenger(&head);
    numPassengers++;
  }

  // Handle baggage for each passenger
  for (Passenger* passenger = head; passenger; passenger = passenger->next) {
    handleBaggage(passenger);
  }

  printf("Total number of passengers: %d\n", numPassengers);

  return 0;
}