//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
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

Passenger* insertPassenger(Passenger* head, char* name, int numBags);
Bag* insertBag(Bag* head, char* tag, int weight);

int main() {
    Passenger* head = NULL;
    Bag* headBag = NULL;

    srand(time(NULL));

    // Simulate passenger arrival
    for (int i = 0; i < MAX_PASSENGERS; i++) {
        char name[50];
        sprintf(name, "Passenger %d", i);
        int numBags = rand() % MAX_BAGS;

        insertPassenger(head, name, numBags);
    }

    // Simulate baggage handling
    for (Passenger* passenger = head; passenger; passenger++) {
        for (int i = 0; i < passenger->numBags; i++) {
            char tag[20];
            sprintf(tag, "Bag %d", i);
            int weight = rand() % 20;

            insertBag(headBag, tag, weight);
        }
    }

    // Print passenger and baggage information
    for (Passenger* passenger = head; passenger; passenger++) {
        printf("Passenger: %s, Number of bags: %d\n", passenger->name, passenger->numBags);
    }

    for (Bag* bag = headBag; bag; bag++) {
        printf("Bag tag: %s, Weight: %d\n", bag->tag, bag->weight);
    }

    return 0;
}

Passenger* insertPassenger(Passenger* head, char* name, int numBags) {
    Passenger* newPassenger = malloc(sizeof(Passenger));
    strcpy(newPassenger->name, name);
    newPassenger->numBags = numBags;
    newPassenger->next = NULL;

    if (head == NULL) {
        head = newPassenger;
    } else {
        head->next = newPassenger;
    }

    return head;
}

Bag* insertBag(Bag* head, char* tag, int weight) {
    Bag* newBag = malloc(sizeof(Bag));
    strcpy(newBag->tag, tag);
    newBag->weight = weight;
    newBag->next = NULL;

    if (head == NULL) {
        head = newBag;
    } else {
        head->next = newBag;
    }

    return head;
}