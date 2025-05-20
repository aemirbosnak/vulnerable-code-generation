//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSENGERS 10
#define MAX_BAGS 20

typedef struct Passenger {
    char name[50];
    int numBags;
    struct Passenger* next;
} Passenger;

typedef struct Bag {
    char label[20];
    int weight;
    struct Bag* next;
} Bag;

Passenger* createPassenger(char* name, int numBags) {
    Passenger* newPassenger = malloc(sizeof(Passenger));
    strcpy(newPassenger->name, name);
    newPassenger->numBags = numBags;
    newPassenger->next = NULL;
    return newPassenger;
}

Bag* createBag(char* label, int weight) {
    Bag* newBag = malloc(sizeof(Bag));
    strcpy(newBag->label, label);
    newBag->weight = weight;
    newBag->next = NULL;
    return newBag;
}

void simulateBaggageHandling() {
    int numPassengers = rand() % MAX_PASSENGERS + 1;
    Passenger* head = NULL;
    for (int i = 0; i < numPassengers; i++) {
        char name[50];
        sprintf(name, "Passenger %d", i + 1);
        int numBags = rand() % MAX_BAGS + 1;
        head = createPassenger(name, numBags);
        for (int j = 0; j < numBags; j++) {
            char label[20];
            sprintf(label, "Bag %d", j + 1);
            int weight = rand() % 20 + 1;
            head->numBags++;
            head->next = createBag(label, weight);
            head = head->next;
        }
    }

    printf("Number of passengers: %d\n", numPassengers);
    for (head = head; head; head = head->next) {
        printf("Passenger: %s\n", head->name);
        printf("Number of bags: %d\n", head->numBags);
        for (Bag* bag = head->next; bag; bag = bag->next) {
            printf("Bag label: %s\n", bag->label);
            printf("Bag weight: %d\n", bag->weight);
        }
    }
}

int main() {
    simulateBaggageHandling();
    return 0;
}