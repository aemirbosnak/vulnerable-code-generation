//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

// Constants
#define NUM_BAGS 100
#define NUM_CHECKIN_COUNTERS 5
#define NUM_BAGGAGE_CLAIM_CONVEYORS 3
#define CONVEYOR_SPEED 2 // bags per second
#define CHECKIN_TIME 5 // seconds
#define SECURITY_TIME 10 // seconds

// Baggage
typedef struct {
    int id;
    int weight;
    int destination;
    int status; // 0 = checked in, 1 = in security, 2 = on conveyor, 3 = claimed
} Baggage;

// Baggage handling system
typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    Baggage *bags[NUM_BAGS];
    int num_bags;
    int num_checked_in;
    int num_in_security;
    int num_on_conveyor;
    int num_claimed;
} BaggageHandlingSystem;

// Checkin counter
typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int id;
    int num_bags_checked_in;
} CheckinCounter;

// Security checkpoint
typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int num_bags_in_security;
} SecurityCheckpoint;

// Baggage claim conveyor
typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int id;
    int num_bags_claimed;
} BaggageClaimConveyor;

// Initialize the baggage handling system
BaggageHandlingSystem *init_baggage_handling_system() {
    BaggageHandlingSystem *system = malloc(sizeof(BaggageHandlingSystem));
    pthread_mutex_init(&system->mutex, NULL);
    pthread_cond_init(&system->cond, NULL);
    system->num_bags = 0;
    system->num_checked_in = 0;
    system->num_in_security = 0;
    system->num_on_conveyor = 0;
    system->num_claimed = 0;
    return system;
}

// Initialize a checkin counter
CheckinCounter *init_checkin_counter(int id) {
    CheckinCounter *counter = malloc(sizeof(CheckinCounter));
    pthread_mutex_init(&counter->mutex, NULL);
    pthread_cond_init(&counter->cond, NULL);
    counter->id = id;
    counter->num_bags_checked_in = 0;
    return counter;
}

// Initialize a security checkpoint
SecurityCheckpoint *init_security_checkpoint() {
    SecurityCheckpoint *checkpoint = malloc(sizeof(SecurityCheckpoint));
    pthread_mutex_init(&checkpoint->mutex, NULL);
    pthread_cond_init(&checkpoint->cond, NULL);
    checkpoint->num_bags_in_security = 0;
    return checkpoint;
}

// Initialize a baggage claim conveyor
BaggageClaimConveyor *init_baggage_claim_conveyor(int id) {
    BaggageClaimConveyor *conveyor = malloc(sizeof(BaggageClaimConveyor));
    pthread_mutex_init(&conveyor->mutex, NULL);
    pthread_cond_init(&conveyor->cond, NULL);
    conveyor->id = id;
    conveyor->num_bags_claimed = 0;
    return conveyor;
}

// Add a bag to the baggage handling system
void add_bag(BaggageHandlingSystem *system, Baggage *bag) {
    pthread_mutex_lock(&system->mutex);
    system->bags[system->num_bags++] = bag;
    pthread_cond_signal(&system->cond);
    pthread_mutex_unlock(&system->mutex);
}

// Check in a bag
void check_in_bag(CheckinCounter *counter, Baggage *bag) {
    pthread_mutex_lock(&counter->mutex);
    while (counter->num_bags_checked_in >= NUM_BAGS) {
        pthread_cond_wait(&counter->cond, &counter->mutex);
    }
    sleep(CHECKIN_TIME);
    bag->status = 1;
    counter->num_bags_checked_in++;
    pthread_cond_signal(&counter->cond);
    pthread_mutex_unlock(&counter->mutex);
}

// Send a bag to security
void send_bag_to_security(SecurityCheckpoint *checkpoint, Baggage *bag) {
    pthread_mutex_lock(&checkpoint->mutex);
    while (checkpoint->num_bags_in_security >= NUM_BAGS) {
        pthread_cond_wait(&checkpoint->cond, &checkpoint->mutex);
    }
    sleep(SECURITY_TIME);
    bag->status = 2;
    checkpoint->num_bags_in_security++;
    pthread_cond_signal(&checkpoint->cond);
    pthread_mutex_unlock(&checkpoint->mutex);
}

// Put a bag on the conveyor
void put_bag_on_conveyor(BaggageHandlingSystem *system, Baggage *bag) {
    pthread_mutex_lock(&system->mutex);
    while (system->num_on_conveyor >= NUM_BAGS) {
        pthread_cond_wait(&system->cond, &system->mutex);
    }
    bag->status = 3;
    system->num_on_conveyor++;
    pthread_cond_signal(&system->cond);
    pthread_mutex_unlock(&system->mutex);
}

// Claim a bag
void claim_bag(BaggageClaimConveyor *conveyor, Baggage *bag) {
    pthread_mutex_lock(&conveyor->mutex);
    while (conveyor->num_bags_claimed >= NUM_BAGS) {
        pthread_cond_wait(&conveyor->cond, &conveyor->mutex);
    }
    bag->status = 4;
    conveyor->num_bags_claimed++;
    pthread_cond_signal(&conveyor->cond);
    pthread_mutex_unlock(&conveyor->mutex);
}

// Thread function for a passenger
void *passenger(void *args) {
    BaggageHandlingSystem *system = (BaggageHandlingSystem *)args;
    Baggage *bag = malloc(sizeof(Baggage));
    bag->id = rand() % 5;
    bag->weight = rand() % 10;
    bag->destination = rand() % 3;
    bag->status = 0;
    add_bag(system, bag);
    sleep(rand() % 5);
    check_in_bag(init_checkin_counter(rand() % 4), bag);
    sleep(rand() % 5);
    send_bag_to_security(init_security_checkpoint(), bag);
    sleep(rand() % 5);
    put_bag_on_conveyor(system, bag);
    claim_bag(init_baggage_claim_conveyor(rand() % 2), bag);
    return NULL;
}

// Main function
int main() {
    srand(time(NULL));
    BaggageHandlingSystem *system = init_baggage_handling_system();
    for (int i = 0; i < NUM_BAGS; i++) {
        pthread_t thread;
        pthread_create(&thread, NULL, passenger, system);
    }
    while (system->num_claimed < NUM_BAGS) {
        pthread_cond_wait(&system->cond, &system->mutex);
    }
    pthread_mutex_destroy(&system->mutex);
    pthread_cond_destroy(&system->cond);
    free(system);
    return 0;
}