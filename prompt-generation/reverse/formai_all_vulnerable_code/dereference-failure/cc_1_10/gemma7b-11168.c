//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSENGER_NUMBER 100

typedef struct Passenger {
  char name[50];
  int baggage_weight;
  struct Passenger* next;
} Passenger;

void insert_passenger(Passenger** head, char* name, int baggage_weight) {
  Passenger* new_passenger = (Passenger*)malloc(sizeof(Passenger));
  strcpy(new_passenger->name, name);
  new_passenger->baggage_weight = baggage_weight;
  new_passenger->next = NULL;

  if (*head == NULL) {
    *head = new_passenger;
  } else {
    (*head)->next = new_passenger;
  }
}

void print_passengers(Passenger* head) {
  while (head) {
    printf("%s, ", head->name);
    printf("Baggage weight: %d kg\n", head->baggage_weight);
    head = head->next;
  }
}

int main() {
  Passenger* passengers = NULL;

  // Simulate passenger check-in
  insert_passenger(&passengers, "John Doe", 20);
  insert_passenger(&passengers, "Jane Doe", 15);
  insert_passenger(&passengers, "Peter Pan", 25);

  // Print passenger information
  print_passengers(passengers);

  // Randomly select a passenger
  Passenger* selected_passenger = passengers;
  srand(time(NULL));
  int random_index = rand() % MAX_PASSENGER_NUMBER;
  selected_passenger = passengers;

  // Print selected passenger information
  for (int i = 0; i < random_index; i++) {
    selected_passenger = selected_passenger->next;
  }
  printf("Selected passenger: %s\n", selected_passenger->name);
  printf("Selected passenger's baggage weight: %d kg\n", selected_passenger->baggage_weight);

  return 0;
}