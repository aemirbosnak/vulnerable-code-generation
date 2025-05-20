//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: all-encompassing
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_PASSENGERS 100
#define MAX_BAGS 20

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

void simulate_airport_baggage_handling() {
    // Create a linked list of passengers
    Passenger* head = NULL;
    for (int i = 0; i < MAX_PASSENGERS; i++) {
        Passenger* newPassenger = (Passenger*)malloc(sizeof(Passenger));
        newPassenger->name[0] = '\0';
        newPassenger->numBags = rand() % MAX_BAGS;
        newPassenger->next = head;
        head = newPassenger;
    }

    // Create a linked list of bags
    Bag* tail = NULL;
    for (int i = 0; i < MAX_BAGS; i++) {
        Bag* newBag = (Bag*)malloc(sizeof(Bag));
        newBag->tag[0] = '\0';
        newBag->weight = rand() % 20;
        newBag->next = tail;
        tail = newBag;
    }

    // Simulate passenger baggage handling
    for (Passenger* passenger = head; passenger; passenger = passenger->next) {
        int numBags = passenger->numBags;
        for (int i = 0; i < numBags; i++) {
            for (Bag* bag = tail; bag; bag = bag->next) {
                if (strcmp(bag->tag, passenger->name) == 0) {
                    printf("%s has baggage with tag %s and weight %d\n", passenger->name, bag->tag, bag->weight);
                }
            }
        }
    }
}

int main() {
    simulate_airport_baggage_handling();
    return 0;
}