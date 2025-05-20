//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSENGERS 100
#define MAX_Luggage_WEIGHT 50

typedef struct Passenger {
    char name[50];
    int flight_number;
    int baggage_weight;
    struct Passenger* next;
} Passenger;

typedef struct Baggage {
    int weight;
    struct Baggage* next;
} Baggage;

Passenger* createPassenger(char* name, int flight_number, int baggage_weight) {
    Passenger* newPassenger = (Passenger*)malloc(sizeof(Passenger));
    strcpy(newPassenger->name, name);
    newPassenger->flight_number = flight_number;
    newPassenger->baggage_weight = baggage_weight;
    newPassenger->next = NULL;
    return newPassenger;
}

Baggage* createBaggage(int weight) {
    Baggage* newBaggage = (Baggage*)malloc(sizeof(Baggage));
    newBaggage->weight = weight;
    newBaggage->next = NULL;
    return newBaggage;
}

void handleBaggage(Passenger* passenger) {
    printf("Passenger: %s, Flight Number: %d, Baggage Weight: %d\n", passenger->name, passenger->flight_number, passenger->baggage_weight);
    Baggage* baggage = passenger->baggage_weight;
    while (baggage) {
        printf("Baggage Weight: %d\n", baggage->weight);
        baggage = baggage->next;
    }
}

int main() {
    Passenger* head = createPassenger("John Doe", 123, 25);
    head->next = createPassenger("Jane Doe", 456, 30);
    head->next->next = createPassenger("Peter Pan", 789, 40);

    handleBaggage(head);

    return 0;
}