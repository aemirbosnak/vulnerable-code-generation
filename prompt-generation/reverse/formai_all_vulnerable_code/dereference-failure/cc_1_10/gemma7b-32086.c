//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSENGERS 100

typedef struct Passenger {
    char name[50];
    char flight_number[20];
    int baggage_weight;
    struct Passenger* next;
} Passenger;

void handle_baggage(Passenger* passenger) {
    int baggage_weight = passenger->baggage_weight;
    if (baggage_weight <= 20) {
        printf("Passenger %s has checked in with a baggage weight of %d. No additional fees.\n", passenger->name, baggage_weight);
    } else if (baggage_weight <= 50) {
        int excess_weight = baggage_weight - 20;
        printf("Passenger %s has checked in with a baggage weight of %d. An excess baggage fee of $%d will be charged.\n", passenger->name, baggage_weight, excess_weight * 5);
    } else {
        int excess_weight = baggage_weight - 50;
        printf("Passenger %s has checked in with a baggage weight of %d. An excess baggage fee of $%d will be charged.\n", passenger->name, baggage_weight, excess_weight * 10);
    }
}

int main() {
    Passenger* head = NULL;

    // Simulate passengers checking in
    for (int i = 0; i < MAX_PASSENGERS; i++) {
        Passenger* passenger = (Passenger*)malloc(sizeof(Passenger));
        passenger->name[0] = 'A' + i;
        passenger->flight_number[0] = 'A' + i;
        passenger->baggage_weight = 10 + i;

        // Insert passenger into the linked list
        if (head == NULL) {
            head = passenger;
        } else {
            passenger->next = head;
            head = passenger;
        }
    }

    // Handle baggage for each passenger
    for (Passenger* passenger = head; passenger; passenger = passenger->next) {
        handle_baggage(passenger);
    }

    return 0;
}