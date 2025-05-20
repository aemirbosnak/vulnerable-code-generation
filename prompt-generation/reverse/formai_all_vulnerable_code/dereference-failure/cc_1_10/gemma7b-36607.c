//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSENGERS 100

typedef struct Passenger {
    char name[20];
    int baggage_weight;
    struct Passenger* next;
} Passenger;

void add_passenger(Passenger** head, char* name, int baggage_weight) {
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

void handle_baggage(Passenger* passenger) {
    int baggage_weight = passenger->baggage_weight;
    printf("Passenger: %s, Baggage weight: %d kg\n", passenger->name, baggage_weight);

    if (baggage_weight > 20) {
        printf("Excess baggage charge: $50.00\n");
    }

    if (baggage_weight < 10) {
        printf("Underweight baggage charge: $25.00\n");
    }
}

int main() {
    Passenger* head = NULL;

    // Add passengers
    add_passenger(&head, "John Doe", 25);
    add_passenger(&head, "Jane Doe", 15);
    add_passenger(&head, "Peter Pan", 30);

    // Handle baggage
    handle_baggage(head);

    return 0;
}