//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSENGERS 100

typedef struct Passenger {
    char name[50];
    int baggage_weight;
    struct Passenger* next;
} Passenger;

Passenger* insert_passenger(Passenger* head) {
    Passenger* new_passenger = (Passenger*)malloc(sizeof(Passenger));
    new_passenger->next = NULL;

    if (head == NULL) {
        head = new_passenger;
    } else {
        head->next = new_passenger;
    }

    return head;
}

void handle_baggage(Passenger* head) {
    while (head) {
        printf("Processing passenger: %s\n", head->name);
        printf("Baggage weight: %d kg\n", head->baggage_weight);

        if (head->baggage_weight > 20) {
            printf("Excess baggage penalty applies.\n");
        } else {
            printf("No excess baggage penalty.\n");
        }

        head = head->next;
    }
}

int main() {
    time_t t;
    srand(time(&t));

    Passenger* head = NULL;

    // Simulate passenger arrival
    for (int i = 0; i < MAX_PASSENGERS; i++) {
        insert_passenger(head);
    }

    // Handle baggage
    handle_baggage(head);

    return 0;
}