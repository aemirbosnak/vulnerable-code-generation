//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int id;
    double weight;
    int destination;
} Baggage;

typedef struct {
    size_t baggage_count;
    Baggage *baggage_list;
} ConveyorBelt;

typedef struct {
    size_t destination_count;
    ConveyorBelt *conveyor_belts;
} Airport;

Airport *airport_create() {
    Airport *airport = malloc(sizeof(Airport));
    if (airport == NULL) {
        return NULL;
    }

    airport->destination_count = 0;
    airport->conveyor_belts = NULL;

    return airport;
}

void airport_destroy(Airport *airport) {
    if (airport == NULL) {
        return;
    }

    for (size_t i = 0; i < airport->destination_count; i++) {
        free(airport->conveyor_belts[i].baggage_list);
    }

    free(airport->conveyor_belts);
    free(airport);
}

bool airport_add_destination(Airport *airport, int destination) {
    if (airport == NULL) {
        return false;
    }

    ConveyorBelt *conveyor_belts = realloc(airport->conveyor_belts,
                                          (airport->destination_count + 1) * sizeof(ConveyorBelt));
    if (conveyor_belts == NULL) {
        return false;
    }

    airport->conveyor_belts = conveyor_belts;
    airport->conveyor_belts[airport->destination_count].baggage_count = 0;
    airport->conveyor_belts[airport->destination_count].baggage_list = NULL;
    airport->destination_count++;

    return true;
}

bool airport_check_in_baggage(Airport *airport, Baggage baggage) {
    if (airport == NULL || baggage.destination < 0 || baggage.destination >= airport->destination_count) {
        return false;
    }

    ConveyorBelt *conveyor_belt = &airport->conveyor_belts[baggage.destination];
    Baggage *baggage_list = realloc(conveyor_belt->baggage_list,
                                   (conveyor_belt->baggage_count + 1) * sizeof(Baggage));
    if (baggage_list == NULL) {
        return false;
    }

    conveyor_belt->baggage_list = baggage_list;
    conveyor_belt->baggage_list[conveyor_belt->baggage_count] = baggage;
    conveyor_belt->baggage_count++;

    return true;
}

void airport_print_conveyor_belt(Airport *airport, int destination) {
    if (airport == NULL || destination < 0 || destination >= airport->destination_count) {
        return;
    }

    ConveyorBelt *conveyor_belt = &airport->conveyor_belts[destination];
    printf("Conveyor belt for destination %d:\n", destination);
    for (size_t i = 0; i < conveyor_belt->baggage_count; i++) {
        Baggage baggage = conveyor_belt->baggage_list[i];
        printf("Baggage %d: weight = %.2f kg\n", baggage.id, baggage.weight);
    }
}

int main() {
    // Create the airport
    Airport *airport = airport_create();

    // Add some destinations
    airport_add_destination(airport, 1);
    airport_add_destination(airport, 2);
    airport_add_destination(airport, 3);

    // Check in some baggage
    Baggage baggage1 = {1, 20.0, 1};
    Baggage baggage2 = {2, 15.0, 2};
    Baggage baggage3 = {3, 25.0, 3};
    airport_check_in_baggage(airport, baggage1);
    airport_check_in_baggage(airport, baggage2);
    airport_check_in_baggage(airport, baggage3);

    // Print the conveyor belts
    airport_print_conveyor_belt(airport, 1);
    airport_print_conveyor_belt(airport, 2);
    airport_print_conveyor_belt(airport, 3);

    // Destroy the airport
    airport_destroy(airport);

    return 0;
}