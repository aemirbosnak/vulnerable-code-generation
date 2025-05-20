//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSENGERS 100
#define MAX_BAGS 50

typedef struct Passenger {
    char name[50];
    int numBags;
    struct Passenger* next;
} Passenger;

typedef struct Bag {
    char tag[20];
    int weight;
    struct Bag* next;
} Bag;

void simulateAirports() {
    Passenger* head = NULL;
    Bag* headBag = NULL;

    // Create a few passengers
    for (int i = 0; i < MAX_PASSENGERS; i++) {
        Passenger* newPassenger = (Passenger*)malloc(sizeof(Passenger));
        strcpy(newPassenger->name, "Passenger " + i);
        newPassenger->numBags = rand() % MAX_BAGS;
        newPassenger->next = head;
        head = newPassenger;
    }

    // Create a few bags
    for (int i = 0; i < MAX_BAGS; i++) {
        Bag* newBag = (Bag*)malloc(sizeof(Bag));
        strcpy(newBag->tag, "Bag " + i);
        newBag->weight = rand() % 20;
        newBag->next = headBag;
        headBag = newBag;
    }

    // Simulate passenger check-in
    for (Passenger* passenger = head; passenger; passenger++) {
        printf("Passenger: %s, Number of bags: %d\n", passenger->name, passenger->numBags);
    }

    // Simulate baggage handling
    for (Bag* bag = headBag; bag; bag++) {
        printf("Bag tag: %s, Weight: %d\n", bag->tag, bag->weight);
    }
}

int main() {
    simulateAirports();
    return 0;
}