//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a piece of luggage
typedef struct {
    int id;
    char *destination;
    int weight;
} Luggage;

// Define a struct to represent a conveyor belt
typedef struct {
    Luggage **luggage_list;
    int capacity;
    int count;
} ConveyorBelt;

// Define a struct to represent a baggage handler
typedef struct {
    char *name;
    int max_capacity;
    int current_capacity;
    ConveyorBelt *conveyor_belt;
} BaggageHandler;

// Function to create a new piece of luggage
Luggage *create_luggage(int id, char *destination, int weight) {
    Luggage *l = malloc(sizeof(Luggage));
    l->id = id;
    l->destination = strdup(destination);
    l->weight = weight;
    return l;
}

// Function to free memory allocated to a piece of luggage
void free_luggage(Luggage *l) {
    free(l->destination);
    free(l);
}

// Function to create a new conveyor belt
ConveyorBelt *create_conveyor_belt(int capacity) {
    ConveyorBelt *c = malloc(sizeof(ConveyorBelt));
    c->luggage_list = malloc(capacity * sizeof(Luggage *));
    c->capacity = capacity;
    c->count = 0;
    return c;
}

// Function to free memory allocated to a conveyor belt
void free_conveyor_belt(ConveyorBelt *c) {
    for (int i = 0; i < c->count; i++) {
        free_luggage(c->luggage_list[i]);
    }
    free(c->luggage_list);
    free(c);
}

// Function to add a piece of luggage to a conveyor belt
void add_luggage_to_conveyor_belt(ConveyorBelt *c, Luggage *l) {
    if (c->count < c->capacity) {
        c->luggage_list[c->count] = l;
        c->count++;
    } else {
        printf("Conveyor belt is full, cannot add more luggage!\n");
    }
}

// Function to remove a piece of luggage from a conveyor belt by ID
Luggage *remove_luggage_from_conveyor_belt_by_id(ConveyorBelt *c, int id) {
    for (int i = 0; i < c->count; i++) {
        if (c->luggage_list[i]->id == id) {
            Luggage *l = c->luggage_list[i];
            for (int j = i; j < c->count - 1; j++) {
                c->luggage_list[j] = c->luggage_list[j+1];
            }
            c->count--;
            return l;
        }
    }
    printf("Luggage with ID %d not found on conveyor belt!\n", id);
    return NULL;
}

// Function to create a new baggage handler
BaggageHandler *create_baggage_handler(char *name, int max_capacity) {
    BaggageHandler *bh = malloc(sizeof(BaggageHandler));
    bh->name = strdup(name);
    bh->max_capacity = max_capacity;
    bh->current_capacity = 0;
    bh->conveyor_belt = create_conveyor_belt(max_capacity);
    return bh;
}

// Function to free memory allocated to a baggage handler
void free_baggage_handler(BaggageHandler *bh) {
    free_conveyor_belt(bh->conveyor_belt);
    free(bh->name);
    free(bh);
}

// Function to add a piece of luggage to a baggage handler's conveyor belt
void add_luggage_to_baggage_handler(BaggageHandler *bh, Luggage *l) {
    if (bh->current_capacity + l->weight <= bh->max_capacity) {
        add_luggage_to_conveyor_belt(bh->conveyor_belt, l);
        bh->current_capacity += l->weight;
    } else {
        printf("%s's conveyor belt is full, cannot add more luggage!\n", bh->name);
    }
}

// Function to remove a piece of luggage from a baggage handler's conveyor belt by ID
Luggage *remove_luggage_from_baggage_handler_by_id(BaggageHandler *bh, int id) {
    Luggage *l = remove_luggage_from_conveyor_belt_by_id(bh->conveyor_belt, id);
    if (l != NULL) {
        bh->current_capacity -= l->weight;
    }
    return l;
}

int main() {
    // Create three pieces of luggage
    Luggage *l1 = create_luggage(1, "London", 20);
    Luggage *l2 = create_luggage(2, "New York", 30);
    Luggage *l3 = create_luggage(3, "Paris", 25);

    // Create two baggage handlers
    BaggageHandler *bh1 = create_baggage_handler("Bob", 50);
    BaggageHandler *bh2 = create_baggage_handler("Alice", 40);

    // Add luggage to baggage handler 1
    add_luggage_to_baggage_handler(bh1, l1);
    add_luggage_to_baggage_handler(bh1, l2);

    // Try to add too much luggage to baggage handler 1
    add_luggage_to_baggage_handler(bh1, l3);

    // Add remaining luggage to baggage handler 2
    add_luggage_to_baggage_handler(bh2, l3);

    // Remove a piece of luggage from baggage handler 1
    Luggage *removed_luggage = remove_luggage_from_baggage_handler_by_id(bh1, 1);
    printf("Removed luggage with ID %d from %s's conveyor belt.\n", removed_luggage->id, bh1->name);
    free_luggage(removed_luggage);

    // Remove a piece of luggage from baggage handler 2 that does not exist
    removed_luggage = remove_luggage_from_baggage_handler_by_id(bh2, 1);
    free_luggage(removed_luggage);  // This will safely do nothing since removed_luggage is NULL

    // Clean up memory allocated to objects
    free_baggage_handler(bh1);
    free_baggage_handler(bh2);
    free_luggage(l1);
    free_luggage(l2);
    free_luggage(l3);

    return 0;
}