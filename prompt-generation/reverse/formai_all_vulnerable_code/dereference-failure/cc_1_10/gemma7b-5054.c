//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: sophisticated
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

Passenger* createPassenger(char* name, char* flight_number, int baggage_weight) {
    Passenger* newPassenger = (Passenger*)malloc(sizeof(Passenger));
    strcpy(newPassenger->name, name);
    strcpy(newPassenger->flight_number, flight_number);
    newPassenger->baggage_weight = baggage_weight;
    newPassenger->next = NULL;
    return newPassenger;
}

void addPassenger(Passenger* head, char* name, char* flight_number, int baggage_weight) {
    Passenger* newPassenger = createPassenger(name, flight_number, baggage_weight);
    if (head == NULL) {
        head = newPassenger;
    } else {
        newPassenger->next = head;
        head = newPassenger;
    }
}

int calculateBaggageWeight(Passenger* head) {
    int total_weight = 0;
    while (head) {
        total_weight += head->baggage_weight;
        head = head->next;
    }
    return total_weight;
}

int main() {
    Passenger* head = NULL;
    addPassenger(head, "John Doe", "Flight 123", 20);
    addPassenger(head, "Jane Doe", "Flight 456", 15);
    addPassenger(head, "Peter Pan", "Flight 789", 25);

    int total_weight = calculateBaggageWeight(head);
    printf("Total baggage weight: %d", total_weight);

    return 0;
}