//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: energetic
#include <stdlib.h>
#include <stdio.h>
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

void simulate_airport() {
    Passenger* head = NULL;
    Bag* tail = NULL;

    // Simulate passenger arrival
    for (int i = 0; i < MAX_PASSENGERS; i++) {
        Passenger* newPassenger = (Passenger*)malloc(sizeof(Passenger));
        newPassenger->numBags = rand() % MAX_BAGS;
        strcpy(newPassenger->name, "Passenger " + i);

        // Insert passenger into linked list
        if (head == NULL) {
            head = newPassenger;
        } else {
            newPassenger->next = head;
            head = newPassenger;
        }
    }

    // Simulate baggage handling
    for (Passenger* passenger = head; passenger; passenger = passenger->next) {
        for (int j = 0; j < passenger->numBags; j++) {
            Bag* newBag = (Bag*)malloc(sizeof(Bag));
            newBag->weight = rand() % 20;
            strcpy(newBag->tag, "Bag " + j);

            // Insert bag into linked list
            if (tail == NULL) {
                tail = newBag;
            } else {
                newBag->next = tail;
                tail = newBag;
            }
        }
    }

    // Print passenger and baggage information
    printf("Passengers:\n");
    for (Passenger* passenger = head; passenger; passenger = passenger->next) {
        printf("%s has %d bags:\n", passenger->name, passenger->numBags);
    }

    printf("Bags:\n");
    for (Bag* bag = tail; bag; bag = bag->next) {
        printf("%s weighs %d kilos\n", bag->tag, bag->weight);
    }

    // Free memory
    free(head);
    free(tail);
}

int main() {
    simulate_airport();
    return 0;
}