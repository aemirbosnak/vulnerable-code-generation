//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

typedef struct {
    int id;
    int weight;
    int destination;
} Baggage;

#define NUM_BAGGAGE_GENERATORS 10
#define NUM_BAGGAGE_HANDLERS 5
#define MAX_BAGGAGE_WEIGHT 100
#define MAX_BAGGAGE_DESTINATIONS 10

sem_t baggage_queue;
Baggage *baggage_queue_array[100];
int baggage_queue_head = 0;
int baggage_queue_tail = 0;

pthread_t baggage_generators[NUM_BAGGAGE_GENERATORS];
pthread_t baggage_handlers[NUM_BAGGAGE_HANDLERS];

void *baggage_generator(void *arg) {
    while (1) {
        // Generate a random baggage item
        Baggage *baggage = malloc(sizeof(Baggage));
        baggage->id = rand() % 1000;
        baggage->weight = rand() % MAX_BAGGAGE_WEIGHT;
        baggage->destination = rand() % MAX_BAGGAGE_DESTINATIONS;

        // Add the baggage item to the queue
        sem_wait(&baggage_queue);
        baggage_queue_array[baggage_queue_tail] = baggage;
        baggage_queue_tail = (baggage_queue_tail + 1) % 100;
        sem_post(&baggage_queue);
    }

    return NULL;
}

void *baggage_handler(void *arg) {
    while (1) {
        // Get the next baggage item from the queue
        sem_wait(&baggage_queue);
        Baggage *baggage = baggage_queue_array[baggage_queue_head];
        baggage_queue_head = (baggage_queue_head + 1) % 100;
        sem_post(&baggage_queue);

        // Handle the baggage item
        printf("Baggage item %d, weight %d, destination %d\n", baggage->id, baggage->weight, baggage->destination);

        // Free the baggage item
        free(baggage);
    }

    return NULL;
}

int main() {
    // Initialize the baggage queue
    sem_init(&baggage_queue, 0, 0);

    // Create the baggage generators
    for (int i = 0; i < NUM_BAGGAGE_GENERATORS; i++) {
        pthread_create(&baggage_generators[i], NULL, baggage_generator, NULL);
    }

    // Create the baggage handlers
    for (int i = 0; i < NUM_BAGGAGE_HANDLERS; i++) {
        pthread_create(&baggage_handlers[i], NULL, baggage_handler, NULL);
    }

    // Join the baggage generators and handlers
    for (int i = 0; i < NUM_BAGGAGE_GENERATORS; i++) {
        pthread_join(baggage_generators[i], NULL);
    }

    for (int i = 0; i < NUM_BAGGAGE_HANDLERS; i++) {
        pthread_join(baggage_handlers[i], NULL);
    }

    // Destroy the baggage queue
    sem_destroy(&baggage_queue);

    return 0;
}