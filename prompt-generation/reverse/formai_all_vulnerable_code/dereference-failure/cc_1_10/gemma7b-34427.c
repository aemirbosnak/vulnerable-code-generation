//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: expert-level
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_PASSENGERS 100
#define MAX_BAGS 200

typedef struct Passenger {
    char name[50];
    int baggage_count;
    struct Passenger* next;
} Passenger;

typedef struct Bag {
    char tag[20];
    int weight;
    struct Bag* next;
} Bag;

Passenger* passenger_list_head = NULL;
Bag* baggage_list_head = NULL;

void add_passenger(char* name, int baggage_count) {
    Passenger* new_passenger = malloc(sizeof(Passenger));
    strcpy(new_passenger->name, name);
    new_passenger->baggage_count = baggage_count;
    new_passenger->next = passenger_list_head;
    passenger_list_head = new_passenger;
}

void add_bag(char* tag, int weight) {
    Bag* new_bag = malloc(sizeof(Bag));
    strcpy(new_bag->tag, tag);
    new_bag->weight = weight;
    new_bag->next = baggage_list_head;
    baggage_list_head = new_bag;
}

void simulate_airport() {
    time_t t = time(NULL);
    srand(t);

    // Create a random number of passengers and bags
    int num_passengers = rand() % MAX_PASSENGERS;
    int num_bags = rand() % MAX_BAGS;

    // Add passengers and bags to the list
    for (int i = 0; i < num_passengers; i++) {
        add_passenger("Passenger", rand() % 5);
    }
    for (int i = 0; i < num_bags; i++) {
        add_bag("Bag", rand() % 20);
    }

    // Simulate passenger check-in and baggage handling
    for (Passenger* passenger = passenger_list_head; passenger; passenger++) {
        printf("Passenger: %s, baggage count: %d\n", passenger->name, passenger->baggage_count);
        for (Bag* bag = baggage_list_head; bag; bag++) {
            printf("Bag tag: %s, weight: %d\n", bag->tag, bag->weight);
        }
    }
}

int main() {
    simulate_airport();

    return 0;
}