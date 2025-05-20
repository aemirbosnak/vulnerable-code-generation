//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Alan Turing
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_PASSENGERS 10
#define MAX_BAGS 20

typedef struct Passenger {
    char name[20];
    int numBags;
    struct Passenger* next;
} Passenger;

typedef struct Bag {
    int weight;
    struct Bag* next;
} Bag;

void simulateBaggageHandling() {
    Passenger* head = NULL;
    Bag* headBag = NULL;

    for (int i = 0; i < MAX_PASSENGERS; i++) {
        Passenger* newPassenger = malloc(sizeof(Passenger));
        newPassenger->numBags = rand() % MAX_BAGS;
        newPassenger->name[0] = 'A' + i;
        newPassenger->next = head;
        head = newPassenger;
    }

    for (Passenger* passenger = head; passenger; passenger) {
        for (int j = 0; j < passenger->numBags; j++) {
            Bag* newBag = malloc(sizeof(Bag));
            newBag->weight = rand() % 20;
            newBag->next = headBag;
            headBag = newBag;
        }
    }

    time_t start = time(NULL);
    for (int i = 0; i < MAX_PASSENGERS; i++) {
        printf("%s's baggage handling complete.\n", head->name);
        head = head->next;
    }

    time_t end = time(NULL);
    printf("Total time: %d seconds\n", end - start);
}

int main() {
    simulateBaggageHandling();
    return 0;
}