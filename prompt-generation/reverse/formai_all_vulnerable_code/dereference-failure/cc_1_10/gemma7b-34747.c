//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSENGERS 100

typedef struct Passenger {
    char name[50];
    int baggage_weight;
    struct Passenger* next;
} Passenger;

void handle_baggage(Passenger* passenger) {
    int baggage_fee = 0;
    if (passenger->baggage_weight <= 20) {
        baggage_fee = 0;
    } else if (passenger->baggage_weight <= 50) {
        baggage_fee = 50;
    } else if (passenger->baggage_weight <= 80) {
        baggage_fee = 100;
    } else {
        baggage_fee = 150;
    }

    printf("Passenger: %s, baggage weight: %d, baggage fee: %d\n", passenger->name, passenger->baggage_weight, baggage_fee);
}

int main() {
    Passenger* head = NULL;
    Passenger* tail = NULL;

    // Create a few passengers
    Passenger* passenger1 = malloc(sizeof(Passenger));
    strcpy(passenger1->name, "John Doe");
    passenger1->baggage_weight = 30;

    Passenger* passenger2 = malloc(sizeof(Passenger));
    strcpy(passenger2->name, "Jane Doe");
    passenger2->baggage_weight = 40;

    Passenger* passenger3 = malloc(sizeof(Passenger));
    strcpy(passenger3->name, "Peter Pan");
    passenger3->baggage_weight = 60;

    // Add passengers to the linked list
    if (head == NULL) {
        head = passenger1;
        tail = passenger1;
    } else {
        tail->next = passenger2;
        tail = passenger2;
    }
    tail->next = passenger3;
    tail = passenger3;

    // Handle baggage for each passenger
    handle_baggage(head);

    return 0;
}