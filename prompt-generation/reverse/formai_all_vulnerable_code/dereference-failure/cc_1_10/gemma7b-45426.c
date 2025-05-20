//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSENGERS 100
#define MAX_BAGS 20

typedef struct Passenger {
    char name[50];
    int numBags;
    struct Passenger* next;
} Passenger;

typedef struct Bag {
    char label[20];
    struct Bag* next;
} Bag;

Passenger* headPassenger = NULL;
Bag* headBag = NULL;

void addPassenger(char* name, int numBags) {
    Passenger* newPassenger = (Passenger*)malloc(sizeof(Passenger));
    strcpy(newPassenger->name, name);
    newPassenger->numBags = numBags;
    newPassenger->next = headPassenger;
    headPassenger = newPassenger;
}

void addBag(char* label) {
    Bag* newBag = (Bag*)malloc(sizeof(Bag));
    strcpy(newBag->label, label);
    newBag->next = headBag;
    headBag = newBag;
}

void handleBaggage() {
    Passenger* currentPassenger = headPassenger;
    while (currentPassenger) {
        Bag* currentBag = headBag;
        while (currentBag) {
            if (strcmp(currentBag->label, currentPassenger->name) == 0) {
                printf("Passenger: %s, Bag: %s\n", currentPassenger->name, currentBag->label);
            }
        }
        currentPassenger = currentPassenger->next;
    }
}

int main() {
    addPassenger("John Doe", 3);
    addPassenger("Jane Doe", 2);
    addBag("John Doe Bag 1");
    addBag("Jane Doe Bag 1");
    addBag("John Doe Bag 2");
    handleBaggage();
    return 0;
}