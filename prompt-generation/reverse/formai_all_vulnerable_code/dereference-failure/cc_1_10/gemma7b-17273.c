//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Claude Shannon
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_PASSENGERS 100
#define MAX_BAG_WEIGHT 50

typedef struct Passenger {
    char name[20];
    int flight_number;
    struct Bag {
        int weight;
        struct Bag *next;
    } *bags;
} Passenger;

void simulate_airport(int num_passengers) {
    Passenger *passengers = (Passenger *)malloc(num_passengers * sizeof(Passenger));
    for (int i = 0; i < num_passengers; i++) {
        passengers[i].name[0] = 'A' + i;
        passengers[i].flight_number = 100 + i;
        passengers[i].bags = NULL;
    }

    for (int i = 0; i < num_passengers; i++) {
        passengers[i].bags = (struct Bag *)malloc(sizeof(struct Bag));
        passengers[i].bags->weight = rand() % MAX_BAG_WEIGHT;
        passengers[i].bags->next = NULL;
    }

    // Check in passengers
    for (int i = 0; i < num_passengers; i++) {
        printf("%s checked in for flight %d.\n", passengers[i].name, passengers[i].flight_number);
    }

    // Baggage claim
    for (int i = 0; i < num_passengers; i++) {
        struct Bag *bag = passengers[i].bags;
        while (bag) {
            printf("%s's bag weighs %d pounds.\n", passengers[i].name, bag->weight);
            bag = bag->next;
        }
    }

    free(passengers);
}

int main() {
    simulate_airport(20);
    return 0;
}