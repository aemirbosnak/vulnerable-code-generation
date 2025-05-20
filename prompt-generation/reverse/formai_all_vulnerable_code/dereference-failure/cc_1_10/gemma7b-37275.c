//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: optimized
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
    char item[50];
    struct Bag* next;
} Bag;

Passenger* CreatePassenger(char* name, int numBags) {
    Passenger* newPassenger = (Passenger*)malloc(sizeof(Passenger));
    strcpy(newPassenger->name, name);
    newPassenger->numBags = numBags;
    newPassenger->next = NULL;
    return newPassenger;
}

Bag* CreateBag(char* item) {
    Bag* newBag = (Bag*)malloc(sizeof(Bag));
    strcpy(newBag->item, item);
    newBag->next = NULL;
    return newBag;
}

void HandleBaggage(Passenger* passenger) {
    for (int i = 0; i < passenger->numBags; i++) {
        Bag* bag = CreateBag(passenger->name);
        printf("Passenger: %s, Bag item: %s\n", passenger->name, bag->item);
    }
}

int main() {
    // Create a list of passengers
    Passenger* head = CreatePassenger("John Doe", 3);
    head->next = CreatePassenger("Jane Doe", 2);
    head->next->next = CreatePassenger("Peter Pan", 4);

    // Handle baggage for each passenger
    HandleBaggage(head);

    return 0;
}