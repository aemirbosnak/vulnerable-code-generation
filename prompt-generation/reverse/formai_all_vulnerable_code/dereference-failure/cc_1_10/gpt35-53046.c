//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BAGS 100 // maximum number of bags in the system
#define MAX_CONVEYOR_BELTS 3 // maximum number of conveyor belts
#define MAX_BAG_WEIGHT 50 // maximum weight of a bag in pounds
#define MAX_FLIGHTS 10 // maximum number of flights
#define MAX_FLIGHT_NAME 6 // maximum number of characters in a flight name

typedef struct {
    char id[6];
    int weight;
    char flight[MAX_FLIGHT_NAME];
} Baggage;

typedef struct {
    Baggage* bags[MAX_BAGS];
    int last_bag_index;
    int weight;
} ConveyorBelt;

typedef struct {
    char name[MAX_FLIGHT_NAME];
    int weight_limit;
    ConveyorBelt* conveyor_belts[MAX_CONVEYOR_BELTS];
    int last_conveyor_belt_index;
    int total_weights[MAX_CONVEYOR_BELTS];
} Flight;

void generate_baggage_id(char* id) {
    srand(time(NULL));
    int i;
    for(i = 0; i < 5; i++) {
        id[i] = rand() % 26 + 'A';
    }
    id[5] = '\0';
}

Baggage* create_baggage(char* flight) {
    Baggage* new_bag = malloc(sizeof(Baggage));
    generate_baggage_id(new_bag->id);
    new_bag->weight = rand() % MAX_BAG_WEIGHT + 1;
    strncpy(new_bag->flight, flight, MAX_FLIGHT_NAME);
    return new_bag;
}

ConveyorBelt* create_conveyor_belt() {
    ConveyorBelt* new_conveyor_belt = malloc(sizeof(ConveyorBelt));
    new_conveyor_belt->last_bag_index = -1;
    new_conveyor_belt->weight = 0;
    return new_conveyor_belt;
}

Flight* create_flight(char* name, int weight_limit) {
    Flight* new_flight = malloc(sizeof(Flight));
    strncpy(new_flight->name, name, MAX_FLIGHT_NAME);
    new_flight->weight_limit = weight_limit;
    int i;
    for(i = 0; i < MAX_CONVEYOR_BELTS; i++) {
        new_flight->conveyor_belts[i] = create_conveyor_belt();
        new_flight->total_weights[i] = 0;
    }
    return new_flight;
}

void add_bag_to_conveyor_belt(ConveyorBelt* conveyor_belt, Baggage* bag) {
    if(conveyor_belt->last_bag_index == MAX_BAGS - 1) {
        printf("Error: Conveyor belt is full. Cannot add more bags.\n");
        return;
    }
    conveyor_belt->last_bag_index++;
    conveyor_belt->bags[conveyor_belt->last_bag_index] = bag;
    conveyor_belt->weight += bag->weight;
}

void unload_bag_from_conveyor_belt(ConveyorBelt* conveyor_belt, Baggage* bag) {
    int i;
    for(i = 0; i <= conveyor_belt->last_bag_index; i++) {
        if(conveyor_belt->bags[i] == bag) {
            conveyor_belt->bags[i] = NULL;
            conveyor_belt->weight -= bag->weight;
            if(i == conveyor_belt->last_bag_index) {
                conveyor_belt->last_bag_index--;
            }
            break;
        }
    }
}

void add_conveyor_belt_to_flight(Flight* flight, ConveyorBelt* conveyor_belt) {
    if(flight->last_conveyor_belt_index == MAX_CONVEYOR_BELTS - 1) {
        printf("Error: Maximum number of conveyor belts reached for this flight.\n");
        return;
    }
    if(flight->total_weights[flight->last_conveyor_belt_index] + conveyor_belt->weight > flight->weight_limit) {
        printf("Error: Total weight would exceed the limit for this flight. Cannot add conveyor belt.\n");
        return;
    }
    flight->last_conveyor_belt_index++;
    flight->conveyor_belts[flight->last_conveyor_belt_index] = conveyor_belt;
    flight->total_weights[flight->last_conveyor_belt_index] = conveyor_belt->weight;
}

void remove_conveyor_belt_from_flight(Flight* flight, ConveyorBelt* conveyor_belt) {
    int i;
    for(i = 0; i <= flight->last_conveyor_belt_index; i++) {
        if(flight->conveyor_belts[i] == conveyor_belt) {
            flight->conveyor_belts[i] = NULL;
            flight->total_weights[i] = 0;
            if(i == flight->last_conveyor_belt_index) {
                flight->last_conveyor_belt_index--;
            }
            break;
        }
    }
}

void transfer_bag(Flight* from_flight, Flight* to_flight, Baggage* bag) {
    int i;
    for(i = 0; i <= from_flight->last_conveyor_belt_index; i++) {
        ConveyorBelt* conveyor_belt = from_flight->conveyor_belts[i];
        int j;
        for(j = 0; j <= conveyor_belt->last_bag_index; j++) {
            if(conveyor_belt->bags[j] == bag) {
                unload_bag_from_conveyor_belt(conveyor_belt, bag);
                from_flight->total_weights[i] -= bag->weight;
                add_bag_to_conveyor_belt(to_flight->conveyor_belts[i], bag);
                to_flight->total_weights[i] += bag->weight;
                return;
            }
        }
    }
    printf("Error: Bag not found on any conveyor belt in the specified flight.\n");
}

int main() {
    printf("Welcome to the Airport Baggage Handling Simulation!\n");
    Flight* flight1 = create_flight("AA123", 1000);
    Flight* flight2 = create_flight("DL456", 800);
    int i;
    for(i = 0; i < 10; i++) {
        Baggage* new_bag = create_baggage("AA123");
        add_bag_to_conveyor_belt(flight1->conveyor_belts[i % 3], new_bag);
        flight1->total_weights[i % 3] += new_bag->weight;
    }
    for(i = 0; i < 7; i++) {
        Baggage* new_bag = create_baggage("DL456");
        add_bag_to_conveyor_belt(flight2->conveyor_belts[i % 2], new_bag);
        flight2->total_weights[i % 2] += new_bag->weight;
    }
    transfer_bag(flight1, flight2, flight1->conveyor_belts[1]->bags[2]);
    for(i = 0; i < 3; i++) {
        printf("Conveyor belt %d for flight %s has a total weight of %d pounds.\n", i + 1, flight1->name, flight1->total_weights[i]);
    }
    for(i = 0; i < 2; i++) {
        printf("Conveyor belt %d for flight %s has a total weight of %d pounds.\n", i + 1, flight2->name, flight2->total_weights[i]);
    }
    return 0;
}