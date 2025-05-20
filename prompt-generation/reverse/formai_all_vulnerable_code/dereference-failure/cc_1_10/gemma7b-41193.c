//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: mind-bending
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_PASSENGERS 10
#define MAX_LUGGAGE 20

typedef struct Passenger {
    char name[50];
    int numBags;
    struct Passenger* next;
} Passenger;

typedef struct Luggage {
    char tag[20];
    int weight;
    struct Luggage* next;
} Luggage;

void simulateAirPort() {
    Passenger* head = NULL;
    Luggage* tail = NULL;

    // Create a bunch of passengers
    for (int i = 0; i < MAX_PASSENGERS; i++) {
        Passenger* newPassenger = (Passenger*)malloc(sizeof(Passenger));
        strcpy(newPassenger->name, "Passenger " + i);
        newPassenger->numBags = rand() % MAX_LUGGAGE;
        newPassenger->next = head;
        head = newPassenger;
    }

    // Create a bunch of luggage
    for (int i = 0; i < MAX_LUGGAGE; i++) {
        Luggage* newLuggage = (Luggage*)malloc(sizeof(Luggage));
        strcpy(newLuggage->tag, "Luggage " + i);
        newLuggage->weight = rand() % 50;
        newLuggage->next = tail;
        tail = newLuggage;
    }

    // Simulate passengers checking in
    for (Passenger* passenger = head; passenger; passenger = passenger->next) {
        printf("%s has checked in with %d bags.\n", passenger->name, passenger->numBags);
    }

    // Simulate passengers collecting their luggage
    for (Passenger* passenger = head; passenger; passenger = passenger->next) {
        for (Luggage* luggage = tail; luggage; luggage = luggage->next) {
            if (strcmp(passenger->name, luggage->tag) == 0) {
                printf("%s has collected their luggage: %s.\n", passenger->name, luggage->tag);
            }
        }
    }
}

int main() {
    simulateAirPort();

    return 0;
}