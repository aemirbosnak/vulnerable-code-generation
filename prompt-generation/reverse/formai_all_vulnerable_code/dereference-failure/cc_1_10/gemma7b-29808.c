//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSENGERS 100
#define MAX_BAG_WEIGHT 50

typedef struct Passenger {
  char name[50];
  int baggage_weight;
  struct Passenger* next;
} Passenger;

typedef struct Baggage {
  int weight;
  struct Baggage* next;
} Baggage;

Passenger* createPassenger(char* name, int baggage_weight) {
  Passenger* passenger = (Passenger*)malloc(sizeof(Passenger));
  strcpy(passenger->name, name);
  passenger->baggage_weight = baggage_weight;
  passenger->next = NULL;
  return passenger;
}

Baggage* createBaggage(int weight) {
  Baggage* baggage = (Baggage*)malloc(sizeof(Baggage));
  baggage->weight = weight;
  baggage->next = NULL;
  return baggage;
}

int main() {
  srand(time(NULL));
  Passenger* head = NULL;
  for (int i = 0; i < MAX_PASSENGERS; i++) {
    char name[50];
    sprintf(name, "Passenger %d", i + 1);
    int baggage_weight = rand() % MAX_BAG_WEIGHT;
    Passenger* passenger = createPassenger(name, baggage_weight);
    if (head == NULL) {
      head = passenger;
    } else {
      passenger->next = head;
      head = passenger;
    }
  }

  for (Passenger* passenger = head; passenger; passenger = passenger->next) {
    printf("Name: %s, Baggage Weight: %d\n", passenger->name, passenger->baggage_weight);
  }

  return 0;
}