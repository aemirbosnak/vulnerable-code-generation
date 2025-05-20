//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSENGERS 100
#define MAX_BAGS 5

typedef struct Passenger {
    char name[50];
    int numBags;
    struct Passenger* next;
} Passenger;

typedef struct Bag {
    int weight;
    struct Bag* next;
} Bag;

Passenger* createPassenger(char* name, int numBags) {
    Passenger* newPassenger = (Passenger*)malloc(sizeof(Passenger));
    strcpy(newPassenger->name, name);
    newPassenger->numBags = numBags;
    newPassenger->next = NULL;
    return newPassenger;
}

Bag* createBag(int weight) {
    Bag* newBag = (Bag*)malloc(sizeof(Bag));
    newBag->weight = weight;
    newBag->next = NULL;
    return newBag;
}

void handleBaggage(Passenger* passenger) {
    for (int i = 0; i < passenger->numBags; i++) {
        Bag* bag = createBag(rand() % 20 + 10);
        passenger->numBags--;
        printf("%s checked in a bag with weight %d.\n", passenger->name, bag->weight);
    }
}

int main() {
    srand(time(NULL));

    Passenger* head = NULL;
    for (int i = 0; i < MAX_PASSENGERS; i++) {
        Passenger* newPassenger = createPassenger("Passenger", rand() % MAX_BAGS);
        newPassenger->next = head;
        head = newPassenger;
    }

    for (Passenger* passenger = head; passenger; passenger = passenger->next) {
        handleBaggage(passenger);
    }

    return 0;
}