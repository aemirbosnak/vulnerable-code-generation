//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: expert-level
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_NUM_PASSENGERS 100

typedef struct Passenger {
    char name[50];
    int flight_number;
    int baggage_weight;
    struct Passenger* next;
} Passenger;

void addPassenger(Passenger** head, char* name, int flight_number, int baggage_weight) {
    Passenger* newPassenger = malloc(sizeof(Passenger));
    strcpy(newPassenger->name, name);
    newPassenger->flight_number = flight_number;
    newPassenger->baggage_weight = baggage_weight;
    newPassenger->next = NULL;

    if (*head == NULL) {
        *head = newPassenger;
    } else {
        (*head)->next = newPassenger;
    }
}

void handleBaggage(Passenger* head) {
    while (head) {
        int total_weight = 0;
        for (Passenger* current = head; current; current = current->next) {
            total_weight += current->baggage_weight;
        }
        printf("Total baggage weight: %d kg\n", total_weight);

        int average_weight = total_weight / MAX_NUM_PASSENGERS;
        printf("Average baggage weight per passenger: %d kg\n", average_weight);

        head = head->next;
    }
}

int main() {
    Passenger* head = NULL;
    addPassenger(&head, "John Doe", 123, 20);
    addPassenger(&head, "Jane Doe", 456, 15);
    addPassenger(&head, "Peter Pan", 321, 30);
    addPassenger(&head, "Mary Poppins", 246, 25);

    handleBaggage(head);

    return 0;
}