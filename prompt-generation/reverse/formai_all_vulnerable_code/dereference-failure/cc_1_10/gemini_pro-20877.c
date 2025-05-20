//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: curious
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_BAGS 100
#define NUM_CONVEYORS 5
#define NUM_CLAIM_BELTS 3

// Baggage structs
typedef struct bag_t {
    int id;
    int destination;
    int status; // 0: checked in, 1: on conveyor, 2: at claim belt, 3: claimed
} bag_t;

// Conveyor structs
typedef struct conveyor_t {
    int id;
    int destination;
    bag_t* bags[NUM_BAGS];
    int num_bags;
} conveyor_t;

// Claim belt structs
typedef struct claim_belt_t {
    int id;
    bag_t* bags[NUM_BAGS];
    int num_bags;
} claim_belt_t;

// Global variables
bag_t bags[NUM_BAGS];
conveyor_t conveyors[NUM_CONVEYORS];
claim_belt_t claim_belts[NUM_CLAIM_BELTS];

// Mutexes
pthread_mutex_t conveyor_mutexes[NUM_CONVEYORS];
pthread_mutex_t claim_belt_mutexes[NUM_CLAIM_BELTS];

// Threads
pthread_t conveyor_threads[NUM_CONVEYORS];
pthread_t claim_belt_threads[NUM_CLAIM_BELTS];

// Function to generate a random number between min and max
int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to create a new bag
bag_t* create_bag() {
    bag_t* bag = malloc(sizeof(bag_t));
    bag->id = rand_range(0, NUM_BAGS - 1);
    bag->destination = rand_range(0, NUM_CLAIM_BELTS - 1);
    bag->status = 0;
    return bag;
}

// Function to create a new conveyor
conveyor_t* create_conveyor(int id, int destination) {
    conveyor_t* conveyor = malloc(sizeof(conveyor_t));
    conveyor->id = id;
    conveyor->destination = destination;
    conveyor->num_bags = 0;
    return conveyor;
}

// Function to create a new claim belt
claim_belt_t* create_claim_belt(int id) {
    claim_belt_t* claim_belt = malloc(sizeof(claim_belt_t));
    claim_belt->id = id;
    claim_belt->num_bags = 0;
    return claim_belt;
}

// Function to initialize the airport
void initialize_airport() {
    // Initialize bags
    for (int i = 0; i < NUM_BAGS; i++) {
        bags[i] = *create_bag();
    }

    // Initialize conveyors
    for (int i = 0; i < NUM_CONVEYORS; i++) {
        conveyors[i] = *create_conveyor(i, rand_range(0, NUM_CLAIM_BELTS - 1));
    }

    // Initialize claim belts
    for (int i = 0; i < NUM_CLAIM_BELTS; i++) {
        claim_belts[i] = *create_claim_belt(i);
    }

    // Initialize mutexes
    for (int i = 0; i < NUM_CONVEYORS; i++) {
        pthread_mutex_init(&conveyor_mutexes[i], NULL);
    }

    for (int i = 0; i < NUM_CLAIM_BELTS; i++) {
        pthread_mutex_init(&claim_belt_mutexes[i], NULL);
    }
}

// Function to run the conveyor threads
void* conveyor_thread(void* arg) {
    conveyor_t* conveyor = (conveyor_t*)arg;

    while (1) {
        // Check if there are any bags on the conveyor
        if (conveyor->num_bags == 0) {
            continue;
        }

        // Get the first bag on the conveyor
        bag_t* bag = conveyor->bags[0];

        // Move the bag to the next conveyor or claim belt
        if (bag->destination == conveyor->destination) {
            // Move the bag to the claim belt
            pthread_mutex_lock(&claim_belt_mutexes[bag->destination]);
            claim_belts[bag->destination].bags[claim_belts[bag->destination].num_bags] = bag;
            claim_belts[bag->destination].num_bags++;
            pthread_mutex_unlock(&claim_belt_mutexes[bag->destination]);
        } else {
            // Move the bag to the next conveyor
            int next_conveyor_id = (conveyor->id + 1) % NUM_CONVEYORS;
            pthread_mutex_lock(&conveyor_mutexes[next_conveyor_id]);
            conveyors[next_conveyor_id].bags[conveyors[next_conveyor_id].num_bags] = bag;
            conveyors[next_conveyor_id].num_bags++;
            pthread_mutex_unlock(&conveyor_mutexes[next_conveyor_id]);
        }

        // Remove the bag from the conveyor
        for (int i = 0; i < conveyor->num_bags - 1; i++) {
            conveyor->bags[i] = conveyor->bags[i + 1];
        }

        conveyor->num_bags--;
    }

    return NULL;
}

// Function to run the claim belt threads
void* claim_belt_thread(void* arg) {
    claim_belt_t* claim_belt = (claim_belt_t*)arg;

    while (1) {
        // Check if there are any bags on the claim belt
        if (claim_belt->num_bags == 0) {
            continue;
        }

        // Get the first bag on the claim belt
        bag_t* bag = claim_belt->bags[0];

        // Set the bag's status to claimed
        bag->status = 3;

        // Remove the bag from the claim belt
        for (int i = 0; i < claim_belt->num_bags - 1; i++) {
            claim_belt->bags[i] = claim_belt->bags[i + 1];
        }

        claim_belt->num_bags--;
    }

    return NULL;
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Initialize the airport
    initialize_airport();

    // Start the conveyor threads
    for (int i = 0; i < NUM_CONVEYORS; i++) {
        pthread_create(&conveyor_threads[i], NULL, conveyor_thread, (void*)&conveyors[i]);
    }

    // Start the claim belt threads
    for (int i = 0; i < NUM_CLAIM_BELTS; i++) {
        pthread_create(&claim_belt_threads[i], NULL, claim_belt_thread, (void*)&claim_belts[i]);
    }

    // Join the conveyor threads
    for (int i = 0; i < NUM_CONVEYORS; i++) {
        pthread_join(conveyor_threads[i], NULL);
    }

    // Join the claim belt threads
    for (int i = 0; i < NUM_CLAIM_BELTS; i++) {
        pthread_join(claim_belt_threads[i], NULL);
    }

    return 0;
}