//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSENGERS 100
#define MAX_BAGS 20

typedef struct Passenger {
    char name[50];
    char address[100];
    int numBags;
    struct Passenger* next;
} Passenger;

typedef struct Bag {
    char tag[20];
    int weight;
    struct Bag* next;
} Bag;

Passenger* createPassenger(char* name, char* address, int numBags) {
    Passenger* newPassenger = (Passenger*)malloc(sizeof(Passenger));
    strcpy(newPassenger->name, name);
    strcpy(newPassenger->address, address);
    newPassenger->numBags = numBags;
    newPassenger->next = NULL;
    return newPassenger;
}

Bag* createBag(char* tag, int weight) {
    Bag* newBag = (Bag*)malloc(sizeof(Bag));
    strcpy(newBag->tag, tag);
    newBag->weight = weight;
    newBag->next = NULL;
    return newBag;
}

void handleBaggage(Passenger* passenger) {
    printf("Passenger: %s\n", passenger->name);
    printf("Address: %s\n", passenger->address);
    printf("Number of bags: %d\n", passenger->numBags);

    for(Bag* bag = passenger->numBags; bag != NULL; bag = bag->next) {
        printf("Bag tag: %s\n", bag->tag);
        printf("Bag weight: %d\n", bag->weight);
    }
}

int main() {
    Passenger* head = createPassenger("John Doe", "123 Main St.", 3);
    head->next = createPassenger("Jane Doe", "456 Oak Ave.", 2);

    Bag* bag1 = createBag("Bag 1", 20);
    bag1->next = createBag("Bag 2", 30);
    head->numBags = bag1;

    handleBaggage(head);

    return 0;
}