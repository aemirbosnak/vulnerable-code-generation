//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Airport {
    char name[50];
    int passengers;
    int bags;
    int bagsChecked;
    int bagsLost;
};

struct Baggage {
    char origin[50];
    char destination[50];
    int weight;
};

void initializeAirport(struct Airport *airport) {
    srand(time(NULL));
    airport->passengers = rand() % 1000 + 1;
    airport->bags = rand() % 10000 + 1;
    airport->bagsChecked = rand() % airport->bags;
    airport->bagsLost = rand() % airport->bags;
    strcpy(airport->name, "Alan Turing Airport");
}

void printAirportStats(struct Airport *airport) {
    printf("Airport Name: %s\n", airport->name);
    printf("Passengers: %d\n", airport->passengers);
    printf("Total Bags: %d\n", airport->bags);
    printf("Bags Checked: %d\n", airport->bagsChecked);
    printf("Bags Lost: %d\n", airport->bagsLost);
}

void initializeBaggage(struct Baggage *bag) {
    srand(time(NULL));
    bag->origin[0] = 'A';
    bag->destination[0] = 'Z';
    bag->weight = rand() % 100 + 1;
    strcpy(bag->origin, "Alan Turing");
    strcpy(bag->destination, "Alan Turing");
}

void printBaggageStats(struct Baggage *bag) {
    printf("Origin: %s\n", bag->origin);
    printf("Destination: %s\n", bag->destination);
    printf("Weight: %d\n", bag->weight);
}

int main() {
    struct Airport *airport = malloc(sizeof(struct Airport));
    struct Baggage *bag = malloc(sizeof(struct Baggage));
    initializeAirport(airport);
    printAirportStats(airport);
    initializeBaggage(bag);
    printBaggageStats(bag);
    return 0;
}