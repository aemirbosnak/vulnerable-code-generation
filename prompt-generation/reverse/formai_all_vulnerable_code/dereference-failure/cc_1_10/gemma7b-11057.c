//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: paranoid
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
    char content[100];
    struct Bag* next;
} Bag;

Passenger* headPassenger = NULL;
Bag* headBag = NULL;

void addPassenger(char* name, int numBags) {
    Passenger* newPassenger = malloc(sizeof(Passenger));
    strcpy(newPassenger->name, name);
    newPassenger->numBags = numBags;
    newPassenger->next = headPassenger;
    headPassenger = newPassenger;
}

void addBag(char* content) {
    Bag* newBag = malloc(sizeof(Bag));
    strcpy(newBag->content, content);
    newBag->next = headBag;
    headBag = newBag;
}

void searchPassenger(char* name) {
    Passenger* currentPassenger = headPassenger;
    while (currentPassenger) {
        if (strcmp(currentPassenger->name, name) == 0) {
            printf("Passenger found: %s\n", currentPassenger->name);
            printf("Number of bags: %d\n", currentPassenger->numBags);
            break;
        }
        currentPassenger = currentPassenger->next;
    }
    if (currentPassenger == NULL) {
        printf("Passenger not found.\n");
    }
}

void searchBag(char* content) {
    Bag* currentBag = headBag;
    while (currentBag) {
        if (strcmp(currentBag->content, content) == 0) {
            printf("Bag found: %s\n", currentBag->content);
            break;
        }
        currentBag = currentBag->next;
    }
    if (currentBag == NULL) {
        printf("Bag not found.\n");
    }
}

int main() {
    // Add some passengers
    addPassenger("John Doe", 3);
    addPassenger("Jane Doe", 2);
    addPassenger("Peter Pan", 4);

    // Add some bags
    addBag("Laptop");
    addBag("Smartphone");
    addBag("Trolley");
    addBag("Handbag");

    // Search for a passenger
    searchPassenger("John Doe");

    // Search for a bag
    searchBag("Trolley");

    return 0;
}