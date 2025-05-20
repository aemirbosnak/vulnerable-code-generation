//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_BAGS 10
#define NUM_CONVEYORS 3

sem_t empty_bags;  // Semaphore to represent empty bags 
sem_t filled_bags; // Semaphore to represent filled bags
int bags_on_conveyor[NUM_CONVEYORS] = {0}; // Count of bags on each conveyor
pthread_mutex_t mutex[NUM_CONVEYORS]; // Mutex for each conveyor belt

void* conveyor_belt(void* arg) {
    int conveyor_id = *((int*) arg);
    free(arg);
    
    while (1) {
        sem_wait(&filled_bags); // Wait for a filled bag to be available
        pthread_mutex_lock(&mutex[conveyor_id]);

        if (bags_on_conveyor[conveyor_id] > 0) {
            printf("Conveyor %d: Processing bag %d\n", conveyor_id + 1, bags_on_conveyor[conveyor_id]);
            bags_on_conveyor[conveyor_id]--;
            sleep(rand() % 2 + 1); // Simulate processing time
        }

        pthread_mutex_unlock(&mutex[conveyor_id]);
        sem_post(&empty_bags); // Signal that there's an empty bag
    }
    return NULL;
}

void* baggage_handler(void* arg) {
    while (1) {
        sem_wait(&empty_bags); // Wait for an empty bag
        int conveyor_id = rand() % NUM_CONVEYORS; // Randomly choose a conveyor

        pthread_mutex_lock(&mutex[conveyor_id]);
        
        if (bags_on_conveyor[conveyor_id] < MAX_BAGS) {
            bags_on_conveyor[conveyor_id]++;
            printf("Handler: Added bag to conveyor %d. Total bags: %d\n", conveyor_id + 1, bags_on_conveyor[conveyor_id]);
            sleep(rand() % 3 + 1); // Simulate time taken to add a bag 
        }

        pthread_mutex_unlock(&mutex[conveyor_id]);
        sem_post(&filled_bags); // Signal that there's a filled bag
    }
    return NULL;
}

int main() {
    pthread_t conveyor_threads[NUM_CONVEYORS];
    pthread_t handler_thread;

    // Initialize semaphores and mutexes
    sem_init(&empty_bags, 0, MAX_BAGS);
    sem_init(&filled_bags, 0, 0);
    for (int i = 0; i < NUM_CONVEYORS; i++) {
        pthread_mutex_init(&mutex[i], NULL);
        bags_on_conveyor[i] = 0; // Initialize bags on conveyor
    }

    // Create conveyor threads
    for (int i = 0; i < NUM_CONVEYORS; i++) {
        int* conveyor_id = malloc(sizeof(int));
        *conveyor_id = i;
        pthread_create(&conveyor_threads[i], NULL, conveyor_belt, conveyor_id);
    }

    // Create a baggage handler thread
    pthread_create(&handler_thread, NULL, baggage_handler, NULL);

    // Joining conveyor threads (not necessary in this infinite loop case)
    for (int i = 0; i < NUM_CONVEYORS; i++) {
        pthread_join(conveyor_threads[i], NULL);
    }

    pthread_join(handler_thread, NULL);

    // Cleanup
    sem_destroy(&empty_bags);
    sem_destroy(&filled_bags);
    for (int i = 0; i < NUM_CONVEYORS; i++) {
        pthread_mutex_destroy(&mutex[i]);
    }

    return 0;
}