//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_BAGS 100
#define MAX_FLIGHTS 10

typedef struct Bag {
    int id;
    int weight;
    char destination[20];
    struct Bag *next;
} Bag;

typedef struct Flight {
    int id;
    char destination[20];
    int capacity;
    struct Bag *bags;
    struct Flight *next;
} Flight;

Flight *flights[MAX_FLIGHTS];
Bag *bags[MAX_BAGS];

void create_bags() {
    for (int i = 0; i < MAX_BAGS; i++) {
        bags[i] = malloc(sizeof(Bag));
        bags[i]->id = i;
        bags[i]->weight = rand() % 50 + 1;
        strcpy(bags[i]->destination, "Unknown");
        bags[i]->next = NULL;
    }
}

void create_flights() {
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        flights[i] = malloc(sizeof(Flight));
        flights[i]->id = i;
        strcpy(flights[i]->destination, "Unknown");
        flights[i]->capacity = rand() % 100 + 1;
        flights[i]->bags = NULL;
        flights[i]->next = NULL;
    }
}

void assign_bags_to_flights() {
    for (int i = 0; i < MAX_BAGS; i++) {
        int flight_id = rand() % MAX_FLIGHTS;
        Bag *bag = bags[i];
        Flight *flight = flights[flight_id];
        bag->next = flight->bags;
        flight->bags = bag;
        strcpy(bag->destination, flight->destination);
    }
}

void print_bags() {
    for (int i = 0; i < MAX_BAGS; i++) {
        Bag *bag = bags[i];
        printf("Bag %d: weight = %d, destination = %s\n", bag->id, bag->weight, bag->destination);
    }
}

void print_flights() {
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        Flight *flight = flights[i];
        printf("Flight %d: destination = %s, capacity = %d\n", flight->id, flight->destination, flight->capacity);
        Bag *bag = flight->bags;
        while (bag) {
            printf("\tBag %d: weight = %d, destination = %s\n", bag->id, bag->weight, bag->destination);
            bag = bag->next;
        }
    }
}

int main() {
    srand(time(NULL));
    create_bags();
    create_flights();
    assign_bags_to_flights();
    print_bags();
    print_flights();
    return 0;
}