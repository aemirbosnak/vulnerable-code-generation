//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_CAPACITY 10 // maximum capacity of each conveyor belt
#define MAX_CYCLES 5 // maximum cycles for the simulation

// structure for baggage
struct Baggage {
    int id; // unique id for the baggage
    int weight; // weight of the baggage in kgs
    char airline[10]; // name of the airline sending the baggage
};

// structure for conveyor belt
struct ConveyorBelt {
    int id; // unique id for the belt
    int current_capacity; // current capacity of the belt
    struct Baggage *baggage_list[MAX_CAPACITY]; // list of baggages on the belt
    bool is_empty; // flag to represent if the belt is empty
    bool is_full; // flag to represent if the belt is full
};

// function to add baggage to the conveyor belt
void add_baggage(struct ConveyorBelt *belt, struct Baggage *baggage) {
    if(!belt->is_full) {
        belt->baggage_list[belt->current_capacity] = baggage;
        belt->current_capacity++;
        if(belt->current_capacity == MAX_CAPACITY)
            belt->is_full = true;
        belt->is_empty = false;
    }
}

//function to remove baggage from the conveyor belt
struct Baggage* remove_baggage(struct ConveyorBelt *belt) {
    if(!belt->is_empty) {
        belt->current_capacity--;
        struct Baggage *baggage = belt->baggage_list[belt->current_capacity];
        if(belt->current_capacity == 0)
            belt->is_empty = true;
        belt->is_full = false;
        return baggage;
    }
    else
        return NULL;
}

int main() {
    struct ConveyorBelt belt1 = {1, 0, {}, true, false}; // creating conveyor belt1 with id 1
    struct ConveyorBelt belt2 = {2, 0, {}, true, false}; // creating conveyor belt2 with id 2
    int cycles = 0;
    while(cycles < MAX_CYCLES) {
        // Adding baggages to belt1
        for(int i=0; i<MAX_CAPACITY; i++) {
            struct Baggage *baggage = (struct Baggage*)malloc(sizeof(struct Baggage));
            baggage->id = i+1;
            baggage->weight = (i+1)*2;
            sprintf(baggage->airline, "Airline%d", i+1);
            add_baggage(&belt1, baggage);
        }

        // transferring baggages from belt1 to belt2
        while(belt1.current_capacity != 0) {
            struct Baggage *baggage = remove_baggage(&belt1);
            add_baggage(&belt2, baggage);
        }

        // removing baggages from belt2
        while(belt2.current_capacity != 0) {
            struct Baggage *baggage = remove_baggage(&belt2);
            printf("Baggage id: %d, weight: %d kgs, airline: %s\n", baggage->id, baggage->weight, baggage->airline);
            free(baggage);
        }

        cycles++;
    }

    return 0;
}