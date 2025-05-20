//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: mind-bending
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_PASSENGERS 20

typedef struct Bag {
    char *name;
    int weight;
    struct Bag *next;
} Bag;

typedef struct Passenger {
    char *name;
    int numBags;
    struct Passenger *next;
} Passenger;

void simulate_airport() {
    Bag *head = NULL;
    Passenger *tail = NULL;

    // Simulate passenger arrival
    for (int i = 0; i < MAX_PASSENGERS; i++) {
        Passenger *newPassenger = (Passenger *)malloc(sizeof(Passenger));
        newPassenger->name = "Passenger " + i;
        newPassenger->numBags = rand() % MAX_BAGS;

        if (tail) {
            tail->next = newPassenger;
            tail = newPassenger;
        } else {
            head = newPassenger;
            tail = newPassenger;
        }
    }

    // Simulate baggage handling
    for (Bag *bag = head; bag; bag = bag->next) {
        printf("%s's bag weighs %d kg\n", bag->name, bag->weight);
    }
}

int main() {
    simulate_airport();

    return 0;
}