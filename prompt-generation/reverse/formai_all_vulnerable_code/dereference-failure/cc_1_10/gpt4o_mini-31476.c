//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define CONVEYOR_BELT_SIZE 5
#define NUMBER_OF_BAGS 20

typedef struct {
    int id;
    char *destination;
} Bag;

Bag *conveyor_belt[CONVEYOR_BELT_SIZE];
int conveyor_index = 0;

sem_t empty_slots;
sem_t filled_slots;
pthread_mutex_t mutex;

void *producer(void *arg) {
    for (int i = 0; i < NUMBER_OF_BAGS; i++) {
        // Simulate bag creation
        Bag *new_bag = (Bag *)malloc(sizeof(Bag));
        new_bag->id = i + 1;
        new_bag->destination = (char *)malloc(20 * sizeof(char));
        sprintf(new_bag->destination, "Dest_%d", (i % 5) + 1);
        
        // Wait for an empty slot
        sem_wait(&empty_slots);
        pthread_mutex_lock(&mutex);
        
        // Place bag on the conveyor belt
        conveyor_belt[conveyor_index++] = new_bag;
        printf("Generated Bag ID: %d for %s\n", new_bag->id, new_bag->destination);
        
        pthread_mutex_unlock(&mutex);
        sem_post(&filled_slots);
        
        // Simulate time taken to generate a bag
        sleep(rand() % 2);
    }
    return NULL;
}

void *consumer(void *arg) {
    for (int i = 0; i < NUMBER_OF_BAGS; i++) {
        // Wait for a filled slot
        sem_wait(&filled_slots);
        pthread_mutex_lock(&mutex);

        // Retrieve bag from the conveyor belt
        Bag *processing_bag = conveyor_belt[--conveyor_index];
        printf("Processing Bag ID: %d for %s\n", processing_bag->id, processing_bag->destination);
        
        pthread_mutex_unlock(&mutex);
        sem_post(&empty_slots);
        
        // Simulate time taken to process a bag
        sleep(rand() % 3);
        
        // Free the bag memory
        free(processing_bag->destination);
        free(processing_bag);
    }
    return NULL;
}

int main() {
    pthread_t producer_thread, consumer_thread;

    // Initialize semaphores and mutex
    sem_init(&empty_slots, 0, CONVEYOR_BELT_SIZE);
    sem_init(&filled_slots, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    // Seed the random number generator
    srand(time(NULL));

    // Create producer and consumer threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Wait for both threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // Destroy semaphores and mutex
    sem_destroy(&empty_slots);
    sem_destroy(&filled_slots);
    pthread_mutex_destroy(&mutex);

    return 0;
}