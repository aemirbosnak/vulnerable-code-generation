//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_TRAVELLERS 5
#define MAX_YEARS 100
#define TIME_TRAVEL_LIMIT 2023

typedef struct {
    int id;
    int target_year;
} Traveller;

void* travel_time(void* arg) {
    Traveller* traveller = (Traveller*) arg;
    int current_year = 2023;
    
    printf("Traveller %d preparing to travel to year %d...\n", traveller->id, traveller->target_year);
    
    // Simulated time travel delay
    sleep(rand() % 3 + 1); // Simulate some time taken to travel

    if (traveller->target_year < TIME_TRAVEL_LIMIT && traveller->target_year >= 0) {
        printf("Traveller %d traveled from %d to %d successfully!\n", traveller->id, current_year, traveller->target_year);
    } else {
        printf("Traveller %d found that year %d is out of bounds!\n", traveller->id, traveller->target_year);
    }
    
    free(traveller); // Clean up the allocated memory for traveller
    return NULL;
}

int main() {
    pthread_t threads[NUM_TRAVELLERS];
    srand(time(NULL)); // Seed the random number generator

    for (int i = 0; i < NUM_TRAVELLERS; i++) {
        Traveller* traveller = (Traveller*) malloc(sizeof(Traveller));
        traveller->id = i + 1;
        traveller->target_year = rand() % (MAX_YEARS + 1); // Random year between 0 and MAX_YEARS

        if (pthread_create(&threads[i], NULL, travel_time, (void*) traveller)) {
            fprintf(stderr, "Error creating thread for traveller %d\n", traveller->id);
            free(traveller);
            exit(EXIT_FAILURE);
        }
    }
    
    // Wait for all threads to finish
    for (int i = 0; i < NUM_TRAVELLERS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All travellers have returned from their time travels!\n");
    return 0;
}