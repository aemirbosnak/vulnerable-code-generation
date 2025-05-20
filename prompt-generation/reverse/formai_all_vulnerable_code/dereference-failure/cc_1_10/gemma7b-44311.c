//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSENGERS 100

typedef struct Passenger {
  char name[50];
  int baggage_quantity;
  struct Passenger* next;
} Passenger;

void add_passenger(Passenger** head, char* name, int baggage_quantity) {
  Passenger* new_passenger = (Passenger*)malloc(sizeof(Passenger));
  strcpy(new_passenger->name, name);
  new_passenger->baggage_quantity = baggage_quantity;
  new_passenger->next = NULL;

  if (*head == NULL) {
    *head = new_passenger;
  } else {
    (*head)->next = new_passenger;
  }
}

void simulate_airport_baggage_handling(Passenger* head) {
  time_t start_time = time(NULL);

  while (head) {
    printf("%s is checking in with %d bags...\n", head->name, head->baggage_quantity);
    sleep(rand() % 5);
    head->baggage_quantity--;
  }

  time_t end_time = time(NULL);

  printf("Total time spent checking in: %ld seconds\n", end_time - start_time);
}

int main() {
  Passenger* head = NULL;

  // Simulate adding passengers
  add_passenger(&head, "John Doe", 20);
  add_passenger(&head, "Jane Doe", 15);
  add_passenger(&head, "Peter Pan", 5);

  // Simulate baggage handling
  simulate_airport_baggage_handling(head);

  return 0;
}