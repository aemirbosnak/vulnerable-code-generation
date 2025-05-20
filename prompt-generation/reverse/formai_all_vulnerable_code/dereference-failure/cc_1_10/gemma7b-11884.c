//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: innovative
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
    char label[20];
    int weight;
    struct Bag* next;
} Bag;

Passenger* head = NULL;
Bag* tail = NULL;

void addPassenger(char* name, int numBags) {
    Passenger* newPassenger = (Passenger*)malloc(sizeof(Passenger));
    strcpy(newPassenger->name, name);
    newPassenger->numBags = numBags;
    newPassenger->next = head;
    head = newPassenger;
}

void addBag(char* label, int weight) {
    Bag* newBag = (Bag*)malloc(sizeof(Bag));
    strcpy(newBag->label, label);
    newBag->weight = weight;
    newBag->next = tail;
    tail = newBag;
}

void handleBaggage() {
    time_t start = time(NULL);
    for (int i = 0; i < MAX_PASSENGERS; i++) {
        Passenger* passenger = head;
        while (passenger) {
            int numBags = passenger->numBags;
            for (int j = 0; j < numBags; j++) {
                Bag* bag = tail;
                while (bag) {
                    if (strcmp(bag->label, passenger->name) == 0) {
                        printf("Passenger: %s, Bag label: %s, Weight: %d\n", passenger->name, bag->label, bag->weight);
                        free(bag);
                        tail = bag->next;
                        break;
                    }
                }
            }
            passenger = passenger->next;
        }
    }
    time_t end = time(NULL);
    printf("Time taken: %ld seconds\n", end - start);
}

int main() {
    addPassenger("John Doe", 3);
    addPassenger("Jane Doe", 2);
    addPassenger("Peter Pan", 4);

    addBag("John Doe", 20);
    addBag("Jane Doe", 15);
    addBag("Peter Pan", 25);
    addBag("Peter Pan", 30);

    handleBaggage();

    return 0;
}