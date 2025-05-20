//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

#define NUM_BAGGAGE_CLAIMS 3
#define MAX_BAGS 10
#define MAX_LOOPS 5

sem_t baggage_claims[NUM_BAGGAGE_CLAIMS];

typedef struct {
    int id;
    int bags;
} Passenger;

void* handle_baggage(void* arg) {
    Passenger* passenger = (Passenger*) arg;
    printf("Passenger %d has arrived with %d bag(s).\n", passenger->id, passenger->bags);

    for (int i = 0; i < passenger->bags; i++) {
        int claim_id = rand() % NUM_BAGGAGE_CLAIMS;
        printf("Passenger %d is waiting for baggage claim %d for bag %d.\n", passenger->id, claim_id, i + 1);

        sem_wait(&baggage_claims[claim_id]);
        
        printf("Passenger %d is retrieving bag %d from baggage claim %d.\n", passenger->id, i + 1, claim_id);
        sleep(rand() % 3); // Simulating time taken to retrieve the bag
        printf("Passenger %d has retrieved bag %d from baggage claim %d.\n", passenger->id, i + 1, claim_id);

        sem_post(&baggage_claims[claim_id]);
    }

    printf("Passenger %d has finished retrieving all bags.\n", passenger->id);
    free(passenger);
    return NULL;
}

int main() {
    srand(time(NULL));
    
    pthread_t passengers[MAX_BAGS];
    int passenger_count = 0;

    // Initialize semaphores for baggage claims
    for (int i = 0; i < NUM_BAGGAGE_CLAIMS; i++) {
        sem_init(&baggage_claims[i], 0, 1);
    }

    // Simulating passenger arrivals
    for (int loop = 0; loop < MAX_LOOPS; loop++) {
        int bags_for_passenger = rand() % MAX_BAGS + 1; // Random number of bags between 1 and 10
        Passenger* passenger = (Passenger*) malloc(sizeof(Passenger));
        passenger->id = passenger_count;
        passenger->bags = bags_for_passenger;

        pthread_create(&passengers[passenger_count], NULL, handle_baggage, passenger);
        passenger_count++;
        sleep(rand() % 2 + 1); // Simulating time gap between arriving passengers
    }

    // Wait for all passenger threads to finish
    for (int i = 0; i < passenger_count; i++) {
        pthread_join(passengers[i], NULL);
    }

    // Destroy semaphores
    for (int i = 0; i < NUM_BAGGAGE_CLAIMS; i++) {
        sem_destroy(&baggage_claims[i]);
    }

    printf("All passengers have finished retrieving their bags.\n");
    return 0;
}