//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: lively
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_PASSENGERS 10
#define MAX_BAGS 20

typedef struct Passenger {
    char name[20];
    int numBags;
    struct Passenger* next;
} Passenger;

typedef struct Bag {
    char tag[20];
    int weight;
    struct Bag* next;
} Bag;

void simulate_airport() {

    // Create a list of passengers
    Passenger* head = NULL;
    for (int i = 0; i < MAX_PASSENGERS; i++) {
        Passenger* newPassenger = malloc(sizeof(Passenger));
        strcpy(newPassenger->name, "Passenger " + i);
        newPassenger->numBags = rand() % MAX_BAGS;
        newPassenger->next = head;
        head = newPassenger;
    }

    // Create a list of bags
    Bag* tail = NULL;
    for (int i = 0; i < MAX_BAGS; i++) {
        Bag* newBag = malloc(sizeof(Bag));
        strcpy(newBag->tag, "Bag " + i);
        newBag->weight = rand() % 20;
        newBag->next = tail;
        tail = newBag;
    }

    // Simulate passengers checking in
    for (Passenger* passenger = head; passenger; passenger = passenger->next) {
        printf("%s has checked in with %d bags.\n", passenger->name, passenger->numBags);
    }

    // Simulate baggage claim
    for (Bag* bag = tail; bag; bag = bag->next) {
        printf("Bag tag: %s, weight: %d\n", bag->tag, bag->weight);
    }

    // Free memory
    free(head);
    free(tail);
}

int main() {
    simulate_airport();
    return 0;
}