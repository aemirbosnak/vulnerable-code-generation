//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_PASSENGERS 10

typedef struct Passenger {
    char name[50];
    int baggage_weight;
    struct Passenger* next;
} Passenger;

Passenger* head = NULL;

void addPassenger(char* name, int baggage_weight) {
    Passenger* newPassenger = malloc(sizeof(Passenger));
    strcpy(newPassenger->name, name);
    newPassenger->baggage_weight = baggage_weight;
    newPassenger->next = NULL;

    if (head == NULL) {
        head = newPassenger;
    } else {
        Passenger* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newPassenger;
    }
}

void handleBaggage(char* name) {
    Passenger* passenger = head;
    while (passenger) {
        if (strcmp(passenger->name, name) == 0) {
            int baggage_weight = passenger->baggage_weight;
            printf("Passenger: %s, Baggage weight: %d\n", passenger->name, baggage_weight);
            break;
        }
        passenger = passenger->next;
    }
}

int main() {
    addPassenger("Romeo", 20);
    addPassenger("Juliet", 15);
    addPassenger("Benvolio", 10);
    addPassenger("Mercutio", 25);

    handleBaggage("Romeo");

    return 0;
}