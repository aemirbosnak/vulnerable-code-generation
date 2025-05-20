//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: all-encompassing
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_PASSENGERS 100
#define MAX_BAGS 50

typedef struct Passenger {
    char name[20];
    int numBags;
    struct Passenger* next;
} Passenger;

typedef struct Bag {
    char label[20];
    struct Bag* next;
} Bag;

void simulate_airport() {

    // Create a linked list of passengers
    Passenger* head = NULL;
    for (int i = 0; i < MAX_PASSENGERS; i++) {
        Passenger* newPassenger = (Passenger*)malloc(sizeof(Passenger));
        newPassenger->name[0] = 'A' + i;
        newPassenger->numBags = rand() % MAX_BAGS;
        newPassenger->next = head;
        head = newPassenger;
    }

    // Create a linked list of bags
    Bag* bagHead = NULL;
    for (int i = 0; i < MAX_BAGS; i++) {
        Bag* newBag = (Bag*)malloc(sizeof(Bag));
        newBag->label[0] = 'A' + i;
        newBag->next = bagHead;
        bagHead = newBag;
    }

    // Simulate passengers checking in and baggage handling
    time_t start = time(NULL);
    for (Passenger* passenger = head; passenger; passenger = passenger->next) {
        for (int i = 0; i < passenger->numBags; i++) {
            Bag* bag = bagHead;
            while (bag) {
                if (strcmp(bag->label, passenger->name) == 0) {
                    printf("%s checked in with bag %s\n", passenger->name, bag->label);
                    break;
                }
                bag = bag->next;
            }
        }
    }

    time_t end = time(NULL);
    printf("Total time spent checking in: %ld seconds\n", end - start);
}

int main() {
    simulate_airport();
    return 0;
}