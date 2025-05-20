//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: systematic
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

Passenger* createPassenger(char* name, int numBags) {
    Passenger* newPassenger = (Passenger*)malloc(sizeof(Passenger));
    strcpy(newPassenger->name, name);
    newPassenger->numBags = numBags;
    newPassenger->next = NULL;
    return newPassenger;
}

Bag* createBag(char* content) {
    Bag* newBag = (Bag*)malloc(sizeof(Bag));
    strcpy(newBag->content, content);
    newBag->next = NULL;
    return newBag;
}

void handleBaggage(Passenger* passenger) {
    for (int i = 0; i < passenger->numBags; i++) {
        Bag* bag = createBag(passenger->name);
        printf("Passenger: %s, Bag Content: %s\n", passenger->name, bag->content);
    }
}

int main() {
    time_t t = time(NULL);
    srand(t);

    Passenger* head = NULL;
    for (int i = 0; i < MAX_PASSENGERS; i++) {
        char* name = "Passenger " + i;
        int numBags = rand() % MAX_BAGS;
        Passenger* newPassenger = createPassenger(name, numBags);
        handleBaggage(newPassenger);
        head = newPassenger;
    }

    return 0;
}