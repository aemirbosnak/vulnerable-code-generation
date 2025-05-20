//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Linus Torvalds
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_PASSENGERS 10
#define MAX_BAGS 20

typedef struct Passenger {
  char name[20];
  int numBags;
  struct Passenger* next;
} Passenger;

typedef struct Bag {
  char label[20];
  struct Bag* next;
} Bag;

Passenger* headPassenger = NULL;
Bag* headBag = NULL;

void simulate_passenger_arrival(int numBags) {
  Passenger* newPassenger = malloc(sizeof(Passenger));
  newPassenger->numBags = numBags;
  strcpy(newPassenger->name, "John Doe");

  if (headPassenger == NULL) {
    headPassenger = newPassenger;
  } else {
    headPassenger->next = newPassenger;
    headPassenger = newPassenger;
  }
}

void simulate_bag_arrival(char* label) {
  Bag* newBag = malloc(sizeof(Bag));
  strcpy(newBag->label, label);

  if (headBag == NULL) {
    headBag = newBag;
  } else {
    headBag->next = newBag;
    headBag = newBag;
  }
}

void simulate_check_in() {
  time_t start = time(NULL);
  for (int i = 0; i < MAX_PASSENGERS; i++) {
    simulate_passenger_arrival(rand() % MAX_BAGS);
  }

  for (int i = 0; i < MAX_BAGS; i++) {
    simulate_bag_arrival("Bag #" + i);
  }

  time_t end = time(NULL);
  printf("Check-in completed in %ld seconds\n", end - start);
}

int main() {
  simulate_check_in();
  return 0;
}