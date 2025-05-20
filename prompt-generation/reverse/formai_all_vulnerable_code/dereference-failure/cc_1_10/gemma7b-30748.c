//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSENGERS 10
#define MAX_BAGS 5

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

void addPassenger(Passenger** head, char* name, int numBags) {
    Passenger* newPassenger = malloc(sizeof(Passenger));
    strcpy(newPassenger->name, name);
    newPassenger->numBags = numBags;
    newPassenger->next = NULL;

    if (*head == NULL) {
        *head = newPassenger;
    } else {
        (*head)->next = newPassenger;
    }
}

void addBag(Bag** head, char* tag, int weight) {
    Bag* newBag = malloc(sizeof(Bag));
    strcpy(newBag->tag, tag);
    newBag->weight = weight;
    newBag->next = NULL;

    if (*head == NULL) {
        *head = newBag;
    } else {
        (*head)->next = newBag;
    }
}

void simulateBaggageHandling() {
    Passenger* head = NULL;
    Bag* headBag = NULL;

    // Simulate passenger check-in
    addPassenger(&head, "John Doe", 3);
    addPassenger(&head, "Jane Doe", 2);
    addPassenger(&head, "Peter Pan", 1);

    // Simulate baggage check-in
    addBag(&headBag, "Bag 1", 20);
    addBag(&headBag, "Bag 2", 15);
    addBag(&headBag, "Bag 3", 25);
    addBag(&headBag, "Bag 4", 10);
    addBag(&headBag, "Bag 5", 22);

    // Randomly select passengers and their baggage
    srand(time(NULL));
    int passengerIndex = rand() % MAX_PASSENGERS;
    int baggageIndex = rand() % MAX_BAGS;

    // Print passenger and baggage information
    printf("Passenger: %s\n", head->name);
    printf("Number of bags: %d\n", head->numBags);
    printf("Bag tag: %s\n", headBag->tag);
    printf("Bag weight: %d\n", headBag->weight);
}

int main() {
    simulateBaggageHandling();

    return 0;
}