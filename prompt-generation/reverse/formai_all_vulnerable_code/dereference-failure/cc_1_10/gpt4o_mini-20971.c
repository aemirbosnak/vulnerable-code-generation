//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

#define NUM_CONVEYORS 3
#define NUM_BAGGAGE 10

sem_t sem_conveyors[NUM_CONVEYORS];

void* baggageHandler(void* arg) {
    int baggage_id = *((int*)arg);
    free(arg);
    int conveyor_id = baggage_id % NUM_CONVEYORS;

    printf("Baggage %d is waiting for conveyor %d\n", baggage_id, conveyor_id);
    sem_wait(&sem_conveyors[conveyor_id]);

    printf("Baggage %d is being handled on conveyor %d\n", baggage_id, conveyor_id);
    sleep(rand() % 3 + 1); // Simulate handling time

    printf("Baggage %d has been handled on conveyor %d\n", baggage_id, conveyor_id);
    sem_post(&sem_conveyors[conveyor_id]);

    return NULL;
}

int main() {
    pthread_t threads[NUM_BAGGAGE];
    srand(time(NULL));

    for(int i = 0; i < NUM_CONVEYORS; ++i) {
        sem_init(&sem_conveyors[i], 0, 1); // Initialize each conveyor with a binary semaphore
    }

    for(int i = 0; i < NUM_BAGGAGE; ++i) {
        int* baggage_id = malloc(sizeof(int));
        *baggage_id = i + 1;
        if(pthread_create(&threads[i], NULL, baggageHandler, baggage_id)) {
            fprintf(stderr, "Error creating thread for baggage %d\n", *baggage_id);
            free(baggage_id);
        }
        sleep(rand() % 2); // Simulate time between baggage arrivals
    }

    for(int i = 0; i < NUM_BAGGAGE; ++i) {
        pthread_join(threads[i], NULL);
    }

    for(int i = 0; i < NUM_CONVEYORS; ++i) {
        sem_destroy(&sem_conveyors[i]); // Clean up semaphores
    }

    printf("All baggage has been handled. Simulation complete.\n");
    return 0;
}