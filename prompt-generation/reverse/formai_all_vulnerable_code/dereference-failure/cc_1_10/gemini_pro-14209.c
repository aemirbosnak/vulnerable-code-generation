//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <pthread.h>

// Baggage types
typedef enum {
    NORMAL,
    OVERWEIGHT,
    SPECIAL
} baggage_type;

// Baggage details
typedef struct {
    int id;
    baggage_type type;
    double weight;
} baggage;

// Flight details
typedef struct {
    int id;
    char destination[20];
    int num_bags;
    baggage *bags;
} flight;

// Passenger details
typedef struct {
    int id;
    char name[20];
    flight *flight;
} passenger;

// Baggage handling system
typedef struct {
    pthread_mutex_t lock;
    int num_normal_bags;
    int num_overweight_bags;
    int num_special_bags;
} baggage_handling_system;

// Baggage handling thread
void *baggage_handling_thread(void *args) {
    baggage_handling_system *bhs = (baggage_handling_system *)args;

    while (true) {
        // Acquire lock
        pthread_mutex_lock(&bhs->lock);

        // Check if there are any bags to handle
        if (bhs->num_normal_bags == 0 && bhs->num_overweight_bags == 0 && bhs->num_special_bags == 0) {
            // Release lock
            pthread_mutex_unlock(&bhs->lock);

            // Sleep for a while
            sleep(1);

            // Continue
            continue;
        }

        // Handle normal bags
        while (bhs->num_normal_bags > 0) {
            // Remove a normal bag from the system
            bhs->num_normal_bags--;

            // Release lock
            pthread_mutex_unlock(&bhs->lock);

            // Sleep for a while
            sleep(1);

            // Acquire lock
            pthread_mutex_lock(&bhs->lock);
        }

        // Handle overweight bags
        while (bhs->num_overweight_bags > 0) {
            // Remove an overweight bag from the system
            bhs->num_overweight_bags--;

            // Release lock
            pthread_mutex_unlock(&bhs->lock);

            // Sleep for a while
            sleep(2);

            // Acquire lock
            pthread_mutex_lock(&bhs->lock);
        }

        // Handle special bags
        while (bhs->num_special_bags > 0) {
            // Remove a special bag from the system
            bhs->num_special_bags--;

            // Release lock
            pthread_mutex_unlock(&bhs->lock);

            // Sleep for a while
            sleep(3);

            // Acquire lock
            pthread_mutex_lock(&bhs->lock);
        }

        // Release lock
        pthread_mutex_unlock(&bhs->lock);
    }

    return NULL;
}

// Main function
int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Create baggage handling system
    baggage_handling_system bhs;
    pthread_mutex_init(&bhs.lock, NULL);
    bhs.num_normal_bags = 0;
    bhs.num_overweight_bags = 0;
    bhs.num_special_bags = 0;

    // Create baggage handling thread
    pthread_t baggage_handling_thread_id;
    pthread_create(&baggage_handling_thread_id, NULL, baggage_handling_thread, &bhs);

    // Simulation loop
    while (true) {
        // Generate a random passenger
        passenger passenger;
        passenger.id = rand() % 100000;
        sprintf(passenger.name, "Passenger %d", passenger.id);

        // Generate a random flight
        flight flight;
        flight.id = rand() % 10000;
        sprintf(flight.destination, "Destination %d", flight.id);
        flight.num_bags = rand() % 10;
        flight.bags = malloc(sizeof(baggage) * flight.num_bags);

        // Generate random baggage
        for (int i = 0; i < flight.num_bags; i++) {
            baggage baggage;
            baggage.id = rand() % 100000;
            baggage.type = rand() % 3;
            baggage.weight = rand() % 100;
            flight.bags[i] = baggage;
        }

        // Assign passenger to flight
        passenger.flight = &flight;

        // Add passenger to baggage handling system
        pthread_mutex_lock(&bhs.lock);
        for (int i = 0; i < flight.num_bags; i++) {
            switch (flight.bags[i].type) {
                case NORMAL:
                    bhs.num_normal_bags++;
                    break;
                case OVERWEIGHT:
                    bhs.num_overweight_bags++;
                    break;
                case SPECIAL:
                    bhs.num_special_bags++;
                    break;
            }
        }
        pthread_mutex_unlock(&bhs.lock);

        // Sleep for a while
        sleep(1);
    }

    // Join baggage handling thread
    pthread_join(baggage_handling_thread_id, NULL);

    // Destroy baggage handling system
    pthread_mutex_destroy(&bhs.lock);

    return 0;
}