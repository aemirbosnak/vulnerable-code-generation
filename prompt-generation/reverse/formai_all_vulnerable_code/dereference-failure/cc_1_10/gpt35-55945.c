//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    int weight;
    int destination;
} Baggage;

typedef struct {
    int id;
    Baggage *baggage;
    int capacity;
    int count;
} ConveyorBelt;

typedef struct {
    int id;
    int capacity;
    int count;
} DestinationBelt;

void add_baggage_to_conveyor_belt(ConveyorBelt *belt, Baggage *baggage) {
    if (belt->count == belt->capacity) {
        printf("Conveyor belt %d is full. Baggage %d cannot be added.\n", belt->id, baggage->id);
        return;
    }

    belt->baggage[belt->count++] = *baggage;
    printf("Baggage %d added to conveyor belt %d. Current count: %d\n", baggage->id, belt->id, belt->count);
}

void transfer_baggage_from_conveyor_to_destination_belt(ConveyorBelt *conveyor_belt, DestinationBelt *destination_belt) {
    if (destination_belt->count == destination_belt->capacity) {
        printf("Destination belt %d is full. Transfer cannot be completed.\n", destination_belt->id);
        return;
    }

    if (conveyor_belt->count == 0) {
        printf("Conveyor belt %d is empty. Transfer cannot be completed.\n", conveyor_belt->id);
        return;
    }

    Baggage *baggage = &conveyor_belt->baggage[conveyor_belt->count - 1];
    if (baggage->destination != destination_belt->id) {
        printf("Baggage %d doesn't belong to destination belt %d. Transfer cannot be completed.\n", baggage->id, destination_belt->id);
        return;
    }

    conveyor_belt->count--;
    destination_belt->count++;
    printf("Baggage %d transferred from conveyor belt %d to destination belt %d.\n", baggage->id, conveyor_belt->id, destination_belt->id);
}

int main() {
    srand(time(NULL));

    ConveyorBelt conveyor_belt = {1, malloc(sizeof(Baggage) * 10), 10, 0};
    DestinationBelt destination_belt_1 = {1, 5, 0};
    DestinationBelt destination_belt_2 = {2, 5, 0};

    for (int i = 0; i < 15; i++) {
        Baggage baggage = {i+1, rand() % 20 + 1, rand() % 2 + 1};
        add_baggage_to_conveyor_belt(&conveyor_belt, &baggage);
        transfer_baggage_from_conveyor_to_destination_belt(&conveyor_belt, &destination_belt_1);
        transfer_baggage_from_conveyor_to_destination_belt(&conveyor_belt, &destination_belt_2);
    }

    return 0;
}