//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BAGS 100
#define NUM_CHECKIN_COUNTERS 5
#define NUM_BAGGAGE_HANDLERS 10

typedef struct {
    int id;
    int weight;
    int destination;
} baggage_t;

typedef struct {
    int id;
    int num_bags;
    baggage_t *bags;
} checkin_counter_t;

typedef struct {
    int id;
    int num_bags;
    baggage_t *bags;
} baggage_handler_t;

// Generate a random baggage
baggage_t generate_baggage() {
    baggage_t baggage;
    baggage.id = rand() % 1000;
    baggage.weight = rand() % 50;
    baggage.destination = rand() % 10;
    return baggage;
}

// Generate a random checkin counter
checkin_counter_t generate_checkin_counter() {
    checkin_counter_t checkin_counter;
    checkin_counter.id = rand() % 100;
    checkin_counter.num_bags = rand() % 100;
    checkin_counter.bags = malloc(sizeof(baggage_t) * checkin_counter.num_bags);
    for (int i = 0; i < checkin_counter.num_bags; i++) {
        checkin_counter.bags[i] = generate_baggage();
    }
    return checkin_counter;
}

// Generate a random baggage handler
baggage_handler_t generate_baggage_handler() {
    baggage_handler_t baggage_handler;
    baggage_handler.id = rand() % 100;
    baggage_handler.num_bags = rand() % 100;
    baggage_handler.bags = malloc(sizeof(baggage_t) * baggage_handler.num_bags);
    for (int i = 0; i < baggage_handler.num_bags; i++) {
        baggage_handler.bags[i] = generate_baggage();
    }
    return baggage_handler;
}

// Simulate the airport baggage handling system
void simulate_airport_baggage_handling_system() {
    // Generate random baggage, checkin counters, and baggage handlers
    baggage_t *bags = malloc(sizeof(baggage_t) * NUM_BAGS);
    for (int i = 0; i < NUM_BAGS; i++) {
        bags[i] = generate_baggage();
    }

    checkin_counter_t *checkin_counters = malloc(sizeof(checkin_counter_t) * NUM_CHECKIN_COUNTERS);
    for (int i = 0; i < NUM_CHECKIN_COUNTERS; i++) {
        checkin_counters[i] = generate_checkin_counter();
    }

    baggage_handler_t *baggage_handlers = malloc(sizeof(baggage_handler_t) * NUM_BAGGAGE_HANDLERS);
    for (int i = 0; i < NUM_BAGGAGE_HANDLERS; i++) {
        baggage_handlers[i] = generate_baggage_handler();
    }

    // Simulate the baggage handling process
    for (int i = 0; i < NUM_BAGS; i++) {
        // Check in the baggage at a random checkin counter
        int checkin_counter_id = rand() % NUM_CHECKIN_COUNTERS;
        checkin_counter_t *checkin_counter = &checkin_counters[checkin_counter_id];
        checkin_counter->bags[checkin_counter->num_bags++] = bags[i];

        // Load the baggage onto a random baggage handler
        int baggage_handler_id = rand() % NUM_BAGGAGE_HANDLERS;
        baggage_handler_t *baggage_handler = &baggage_handlers[baggage_handler_id];
        baggage_handler->bags[baggage_handler->num_bags++] = bags[i];

        // Unload the baggage at the baggage claim area
        int destination = bags[i].destination;
        printf("Baggage %d unloaded at baggage claim area %d\n", bags[i].id, destination);
    }

    // Free the allocated memory
    free(bags);
    for (int i = 0; i < NUM_CHECKIN_COUNTERS; i++) {
        free(checkin_counters[i].bags);
    }
    free(checkin_counters);
    for (int i = 0; i < NUM_BAGGAGE_HANDLERS; i++) {
        free(baggage_handlers[i].bags);
    }
    free(baggage_handlers);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Simulate the airport baggage handling system
    simulate_airport_baggage_handling_system();

    return 0;
}