//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_Passengers 10
#define MAX_Luggage 20

typedef struct Passenger {
    char name[50];
    int numBags;
    struct Passenger* next;
} Passenger;

typedef struct Bag {
    int weight;
    struct Bag* next;
} Bag;

Passenger* insertPassenger(Passenger* head, char* name, int numBags) {
    Passenger* newPassenger = (Passenger*)malloc(sizeof(Passenger));
    strcpy(newPassenger->name, name);
    newPassenger->numBags = numBags;
    newPassenger->next = NULL;

    if (head == NULL) {
        head = newPassenger;
    } else {
        head->next = newPassenger;
    }

    return head;
}

Bag* insertBag(Bag* head, int weight) {
    Bag* newBag = (Bag*)malloc(sizeof(Bag));
    newBag->weight = weight;
    newBag->next = NULL;

    if (head == NULL) {
        head = newBag;
    } else {
        head->next = newBag;
    }

    return head;
}

void handleBaggage(Passenger* passenger) {
    printf("Passenger: %s, Number of bags: %d\n", passenger->name, passenger->numBags);

    for (Bag* bag = passenger->numBags; bag != NULL; bag = bag->next) {
        printf("Bag weight: %d\n", bag->weight);
    }
}

int main() {
    Passenger* head = NULL;
    Bag* headBag = NULL;

    insertPassenger(head, "John Doe", 3);
    insertPassenger(head, "Jane Doe", 2);
    insertPassenger(head, "Peter Pan", 1);

    insertBag(headBag, 20);
    insertBag(headBag, 10);
    insertBag(headBag, 30);

    handleBaggage(head->next);

    return 0;
}