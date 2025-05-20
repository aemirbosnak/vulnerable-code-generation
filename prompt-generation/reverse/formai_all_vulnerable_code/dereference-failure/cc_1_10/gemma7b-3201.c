//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSENGERS 100

typedef struct Passenger {
    char name[20];
    int baggage_weight;
    struct Passenger* next;
} Passenger;

void add_passenger(Passenger** head) {
    Passenger* new_passenger = (Passenger*)malloc(sizeof(Passenger));
    new_passenger->next = NULL;

    if (*head == NULL) {
        *head = new_passenger;
    } else {
        (*head)->next = new_passenger;
        *head = new_passenger;
    }
}

void handle_baggage(Passenger* passenger) {
    int baggage_weight = passenger->baggage_weight;
    int baggage_fee = 0;

    if (baggage_weight <= 20) {
        baggage_fee = 0;
    } else if (baggage_weight <= 40) {
        baggage_fee = 50;
    } else if (baggage_weight <= 60) {
        baggage_fee = 100;
    } else {
        baggage_fee = 200;
    }

    printf("Passenger: %s, Baggage weight: %d, Baggage fee: %d\n", passenger->name, baggage_weight, baggage_fee);
}

int main() {
    Passenger* head = NULL;

    for (int i = 0; i < MAX_PASSENGERS; i++) {
        add_passenger(&head);
    }

    handle_baggage(head);

    return 0;
}