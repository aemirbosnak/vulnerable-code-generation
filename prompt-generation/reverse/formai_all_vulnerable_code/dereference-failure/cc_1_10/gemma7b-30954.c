//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSENGERS 100

typedef struct Passenger {
  char name[50];
  int baggage_weight;
  struct Passenger* next;
} Passenger;

Passenger* create_passenger() {
  Passenger* new_passenger = (Passenger*)malloc(sizeof(Passenger));
  new_passenger->next = NULL;
  return new_passenger;
}

void add_passenger(Passenger* head, char* name, int baggage_weight) {
  Passenger* new_passenger = create_passenger();
  strcpy(new_passenger->name, name);
  new_passenger->baggage_weight = baggage_weight;
  if (head == NULL) {
    head = new_passenger;
  } else {
    head->next = new_passenger;
  }
  head = new_passenger;
}

void print_passengers(Passenger* head) {
  while (head) {
    printf("%s (%d baggage) ", head->name, head->baggage_weight);
    head = head->next;
  }
  printf("\n");
}

int main() {
  Passenger* head = NULL;

  // Simulate passenger check-in
  add_passenger(head, "John Doe", 20);
  add_passenger(head, "Jane Doe", 15);
  add_passenger(head, "Peter Pan", 30);

  // Print passengers
  print_passengers(head);

  // Randomly select a passenger and increase baggage weight
  srand(time(NULL));
  int passenger_index = rand() % MAX_PASSENGERS;
  Passenger* passenger = head;
  for (int i = 0; i < passenger_index; i++) {
    passenger = passenger->next;
  }
  passenger->baggage_weight++;

  // Print passengers after modification
  print_passengers(head);

  return 0;
}