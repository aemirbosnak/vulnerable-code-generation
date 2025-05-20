//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define MAX_BAGS 10
#define NUM_CONVEYOR_BELTS 3
#define NUM_WORKERS 2

sem_t available_bags_sem;
sem_t workers_sem;
int bag_count = 0;

typedef struct {
    int bag_id;
} baggage_t;

baggage_t *baggages[MAX_BAGS];

void* worker(void* arg) {
    while (1) {
        sem_wait(&workers_sem);
        
        baggage_t *bag = malloc(sizeof(baggage_t));
        bag->bag_id = bag_count++;
        
        printf("Worker picked up bag ID: %d\n", bag->bag_id);
        sleep(rand() % 2 + 1);  // Simulate time taken to process the bag
        
        sem_post(&available_bags_sem);
        free(bag);
    }
    return NULL;
}

void* conveyor_belt(void* arg) {
    while (1) {
        sem_wait(&available_bags_sem);
        
        printf("Conveyor belt is processing a bag...\n");
        sleep(rand() % 3 + 1);  // Simulate time taken for the conveyor
        
        sem_post(&workers_sem);
    }
    return NULL;
}

int main() {
    pthread_t workers[NUM_WORKERS], belts[NUM_CONVEYOR_BELTS];
    
    // Initialize semaphores
    sem_init(&available_bags_sem, 0, 0);
    sem_init(&workers_sem, 0, NUM_WORKERS);
    
    // Create worker threads
    for (int i = 0; i < NUM_WORKERS; i++) {
        pthread_create(&workers[i], NULL, worker, NULL);
    }
    
    // Create conveyor belt threads
    for (int i = 0; i < NUM_CONVEYOR_BELTS; i++) {
        pthread_create(&belts[i], NULL, conveyor_belt, NULL);
    }
    
    // Let the simulation run for a while
    sleep(20);
    
    // Cleanup and exit
    for (int i = 0; i < NUM_WORKERS; i++) {
        pthread_cancel(workers[i]);
    }
    for (int i = 0; i < NUM_CONVEYOR_BELTS; i++) {
        pthread_cancel(belts[i]);
    }

    sem_destroy(&available_bags_sem);
    sem_destroy(&workers_sem);
    
    printf("Airport baggage handling simulation finished.\n");
    return 0;
}