//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_BAGS 1000
#define NUM_WORKERS 10

typedef struct {
    int id;
    int destination;
} Baggage;

typedef struct {
    int id;
    int numBags;
    Baggage *bags;
} Worker;

void *baggageHandler(void *arg) {
    Worker *worker = arg;
    int i;

    for (i = 0; i < worker->numBags; i++) {
        Baggage *bag = &(worker->bags[i]);

        // Simulate handling the baggage
        printf("Worker %d is handling baggage %d to destination %d\n", worker->id, bag->id, bag->destination);

        // Add a delay to simulate the time it takes to handle the baggage
        usleep(500000); // 0.5 seconds
    }

    return NULL;
}

int main() {
    int i;
    pthread_t threads[NUM_WORKERS];
    Worker workers[NUM_WORKERS];

    // Initialize worker data
    for (i = 0; i < NUM_WORKERS; i++) {
        workers[i].id = i;
        workers[i].numBags = NUM_BAGS / NUM_WORKERS;
        workers[i].bags = malloc(workers[i].numBags * sizeof(Baggage));

        int j;
        for (j = 0; j < workers[i].numBags; j++) {
            Baggage *bag = &(workers[i].bags[j]);
            bag->id = i * NUM_BAGS / NUM_WORKERS + j;
            bag->destination = rand() % 10 + 1; // Simulate random destination
        }
    }

    // Create worker threads
    for (i = 0; i < NUM_WORKERS; i++) {
        pthread_create(&threads[i], NULL, baggageHandler, &workers[i]);
    }

    // Join worker threads
    for (i = 0; i < NUM_WORKERS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}