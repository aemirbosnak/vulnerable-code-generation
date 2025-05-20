//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_BAGGAGE_HANDLERS 3
#define NUM_BAGS 10

typedef struct {
    int bag_id;
} Baggage;

Baggage baggage_queue[NUM_BAGS];
int bag_count = 0;

sem_t empty_slots;
sem_t filled_slots;
pthread_mutex_t lock;

void* baggage_handler(void* arg) {
    int handler_id = *((int*)arg);
    
    while (1) {
        sem_wait(&filled_slots); // Wait for a bag to be available
        pthread_mutex_lock(&lock);
        
        if (bag_count > 0) {
            Baggage bag = baggage_queue[--bag_count];
            pthread_mutex_unlock(&lock);
            sem_post(&empty_slots); // Signal that there is an empty slot
            
            printf("Handler %d processing bag %d\n", handler_id, bag.bag_id);
            sleep(rand() % 3); // Simulate time taken to handle the bag
        } else {
            pthread_mutex_unlock(&lock);
        }
    }
}

void* baggage_producer(void* arg) {
    for (int i = 0; i < NUM_BAGS; i++) {
        sem_wait(&empty_slots); // Wait for an empty slot
        pthread_mutex_lock(&lock);

        baggage_queue[bag_count++] = (Baggage){.bag_id = i + 1};
        printf("Produced bag %d\n", i + 1);
        
        pthread_mutex_unlock(&lock);
        sem_post(&filled_slots); // Signal that there is a new bag available
        
        sleep(rand() % 3); // Simulate time taken to produce a bag
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    
    pthread_t handlers[NUM_BAGGAGE_HANDLERS];
    pthread_t producer;
    
    // Initialize semaphores and mutex
    sem_init(&empty_slots, 0, NUM_BAGS); // Maximum number of bags
    sem_init(&filled_slots, 0, 0); // No filled slots at start
    pthread_mutex_init(&lock, NULL);
    
    // Create baggage handler threads
    int handler_ids[NUM_BAGGAGE_HANDLERS];
    for (int i = 0; i < NUM_BAGGAGE_HANDLERS; i++) {
        handler_ids[i] = i + 1;
        pthread_create(&handlers[i], NULL, baggage_handler, &handler_ids[i]);
    }
    
    // Create baggage producer thread
    pthread_create(&producer, NULL, baggage_producer, NULL);
    
    // Wait for the producer to finish
    pthread_join(producer, NULL);

    // Cancel the handlers since there are no more bags to process
    for (int i = 0; i < NUM_BAGGAGE_HANDLERS; i++) {
        pthread_cancel(handlers[i]);
    }

    // Clean up
    sem_destroy(&empty_slots);
    sem_destroy(&filled_slots);
    pthread_mutex_destroy(&lock);
    
    printf("Baggage handling complete\n");
    return 0;
}