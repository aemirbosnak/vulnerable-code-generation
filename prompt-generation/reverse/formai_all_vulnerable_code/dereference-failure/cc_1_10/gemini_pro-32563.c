//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: single-threaded
#include <stdlib.h>
#include <stdio.h>

// Baggage item
typedef struct baggage {
    int id;             // Unique ID
    int weight;         // Weight in kilograms
    int destination;    // Destination airport code
    struct baggage *next; // Pointer to next baggage item
} baggage_t;

// Baggage belt
typedef struct belt {
    baggage_t *head;    // Head of the belt
    baggage_t *tail;    // Tail of the belt
    int capacity;       // Maximum number of baggage items
} belt_t;

// Airport
typedef struct airport {
    belt_t *belts;      // Array of baggage belts
    int num_belts;      // Number of baggage belts
    int *destinations;  // Array of destination airport codes
    int num_destinations; // Number of destination airport codes
} airport_t;

// Create a new baggage item
baggage_t *create_baggage(int id, int weight, int destination) {
    baggage_t *baggage = malloc(sizeof(baggage_t));
    baggage->id = id;
    baggage->weight = weight;
    baggage->destination = destination;
    baggage->next = NULL;
    return baggage;
}

// Enqueue a baggage item onto a belt
void enqueue(belt_t *belt, baggage_t *baggage) {
    if (belt->head == NULL) {
        belt->head = baggage;
        belt->tail = baggage;
    } else {
        belt->tail->next = baggage;
        belt->tail = baggage;
    }
}

// Dequeue a baggage item from a belt
baggage_t *dequeue(belt_t *belt) {
    if (belt->head == NULL) {
        return NULL;
    } else {
        baggage_t *baggage = belt->head;
        belt->head = belt->head->next;
        if (belt->head == NULL) {
            belt->tail = NULL;
        }
        return baggage;
    }
}

// Create a new airport
airport_t *create_airport(int num_belts, int num_destinations) {
    airport_t *airport = malloc(sizeof(airport_t));
    airport->belts = malloc(sizeof(belt_t) * num_belts);
    for (int i = 0; i < num_belts; i++) {
        airport->belts[i].head = NULL;
        airport->belts[i].tail = NULL;
        airport->belts[i].capacity = 10;
    }
    airport->num_belts = num_belts;
    airport->destinations = malloc(sizeof(int) * num_destinations);
    for (int i = 0; i < num_destinations; i++) {
        airport->destinations[i] = i;
    }
    airport->num_destinations = num_destinations;
    return airport;
}

// Run the airport simulation
void run_simulation(airport_t *airport) {
    // Initialize random number generator
    srand(time(NULL));

    // Create a random number of baggage items
    int num_baggage = rand() % 100;
    for (int i = 0; i < num_baggage; i++) {
        // Create a random baggage item
        int id = rand() % 1000;
        int weight = rand() % 50;
        int destination = rand() % airport->num_destinations;
        baggage_t *baggage = create_baggage(id, weight, destination);

        // Enqueue the baggage item onto a random belt
        int belt_index = rand() % airport->num_belts;
        enqueue(&airport->belts[belt_index], baggage);
    }

    // Run the simulation for a random number of time steps
    int num_time_steps = rand() % 100;
    for (int i = 0; i < num_time_steps; i++) {
        // Dequeue baggage items from each belt
        for (int j = 0; j < airport->num_belts; j++) {
            while (airport->belts[j].head != NULL) {
                baggage_t *baggage = dequeue(&airport->belts[j]);

                // Check if the baggage item has reached its destination
                if (baggage->destination == airport->destinations[j]) {
                    printf("Baggage item %d has arrived at its destination.\n", baggage->id);
                    free(baggage);
                } else {
                    // Enqueue the baggage item onto the next belt
                    int next_belt_index = (j + 1) % airport->num_belts;
                    enqueue(&airport->belts[next_belt_index], baggage);
                }
            }
        }
    }
}

// Free the memory allocated by the airport
void destroy_airport(airport_t *airport) {
    for (int i = 0; i < airport->num_belts; i++) {
        while (airport->belts[i].head != NULL) {
            baggage_t *baggage = dequeue(&airport->belts[i]);
            free(baggage);
        }
    }
    free(airport->belts);
    free(airport->destinations);
    free(airport);
}

int main() {
    // Create an airport with 5 belts and 3 destinations
    airport_t *airport = create_airport(5, 3);

    // Run the airport simulation
    run_simulation(airport);

    // Free the memory allocated by the airport
    destroy_airport(airport);

    return 0;
}