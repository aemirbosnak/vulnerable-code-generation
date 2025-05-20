//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSENGER_NAME_LENGTH 25
#define MAX_BAGgage_WEIGHT 50

typedef struct Passenger {
    char name[MAX_PASSENGER_NAME_LENGTH];
    int baggage_weight;
    struct Passenger* next;
} Passenger;

typedef struct Baggage {
    int weight;
    struct Baggage* next;
} Baggage;

void addPassenger(Passenger** head, char* name, int baggage_weight) {
    Passenger* newPassenger = malloc(sizeof(Passenger));
    strcpy(newPassenger->name, name);
    newPassenger->baggage_weight = baggage_weight;
    newPassenger->next = NULL;

    if (*head == NULL) {
        *head = newPassenger;
    } else {
        ((*head)->next = newPassenger);
        *head = newPassenger;
    }
}

void addBaggage(Baggage** head, int weight) {
    Baggage* newBaggage = malloc(sizeof(Baggage));
    newBaggage->weight = weight;
    newBaggage->next = NULL;

    if (*head == NULL) {
        *head = newBaggage;
    } else {
        ((*head)->next = newBaggage);
        *head = newBaggage;
    }
}

int main() {
    Passenger* passengers = NULL;
    Baggage* baggage = NULL;

    addPassenger(&passengers, "John Doe", 20);
    addPassenger(&passengers, "Jane Doe", 15);
    addPassenger(&passengers, "Peter Pan", 30);

    addBaggage(&baggage, 10);
    addBaggage(&baggage, 20);
    addBaggage(&baggage, 15);

    printf("Passengers:");
    for (Passenger* passenger = passengers; passenger; passenger = passenger->next) {
        printf(" %s (%d)", passenger->name, passenger->baggage_weight);
    }

    printf("\nBags:");
    for (Baggage* bag = baggage; bag; bag = bag->next) {
        printf(" %d", bag->weight);
    }

    return 0;
}