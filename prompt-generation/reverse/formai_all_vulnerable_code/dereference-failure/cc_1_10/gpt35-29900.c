//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 5

// define semaphore for baggage belt
sem_t belt_lock;

// define struct for each piece of baggage
typedef struct {
    int id;
    int weight;
} Baggage;

// function for baggage handler thread
void *baggage_handler(void *thread_id) {
    int id = *(int*)thread_id;
    Baggage baggage;
    
    // loop infinitely, continuously processing baggage
    while(1) {
        // wait for baggage to arrive on the belt
        sem_wait(&belt_lock);
        
        // simulate processing time
        sleep(1);
        
        // simulate weighing the baggage
        baggage.weight = rand() % 50 + 1;
        
        // print information about the processed baggage
        printf("Baggage Handler %d processed baggage with id %d and weight %d kg\n", id, baggage.id, baggage.weight);
    }
    
    pthread_exit(NULL);
}

// function for passenger thread
void *passenger(void *thread_id) {
    int id = *(int*)thread_id;
    Baggage baggage;
    
    // simulate passengers arriving with baggage
    baggage.id = id;
    baggage.weight = rand() % 50 + 1;
    
    // print information about the passenger and their baggage
    printf("Passenger %d has arrived with baggage with id %d and weight %d kg\n", id, baggage.id, baggage.weight);
    
    // wait for a free spot on the baggage belt
    sem_post(&belt_lock);
    
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    int i;
    
    // initialize semaphore for baggage belt
    sem_init(&belt_lock, 0, 0);
    
    // create baggage handler threads
    for(i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, baggage_handler, &thread_ids[i]);
    }
    
    // create passenger threads (10 in this example)
    for(i = 0; i < 10; i++) {
        pthread_create(&threads[i+NUM_THREADS], NULL, passenger, &i);
    }
    
    // join all threads
    for(i = 0; i < NUM_THREADS+10; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // destroy semaphore
    sem_destroy(&belt_lock);
    
    return 0;
}