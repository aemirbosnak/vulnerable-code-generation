//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSENGERS 10

typedef struct Passenger {
  char name[20];
  int baggage_quantity;
  struct Passenger* next;
} Passenger;

void simulate_airport(Passenger** head) {
  time_t start_time = time(NULL);
  printf("--------------------------------------------------------------------\n");
  printf("Welcome to the bustling C Airport! Prepare for a journey!\n");
  printf("--------------------------------------------------------------------\n");

  // Passenger check-in
  for (int i = 0; i < MAX_PASSENGERS; i++) {
    Passenger* new_passenger = (Passenger*)malloc(sizeof(Passenger));
    printf("Enter your name: ");
    scanf("%s", new_passenger->name);
    printf("Enter your baggage quantity: ");
    scanf("%d", &new_passenger->baggage_quantity);

    if (*head == NULL) {
      *head = new_passenger;
    } else {
      (*head)->next = new_passenger;
      *head = new_passenger;
    }
  }

  // Baggage sorting
  printf("Sorting baggage...\n");
  for (Passenger* passenger = *head; passenger; passenger = passenger->next) {
    for (int i = 0; i < passenger->baggage_quantity; i++) {
      printf("%s's baggage item: ", passenger->name);
      printf("Loading...\n");
    }
  }

  // Departure
  printf("Time to depart! Please proceed to the gate.\n");
  time_t end_time = time(NULL);
  printf("Total time spent at the airport: %d seconds\n", (int)(end_time - start_time));
  printf("--------------------------------------------------------------------\n");
}

int main() {
  Passenger** head = NULL;
  simulate_airport(head);
  return 0;
}