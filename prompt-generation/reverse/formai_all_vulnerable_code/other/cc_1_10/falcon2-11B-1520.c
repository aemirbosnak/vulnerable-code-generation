//Falcon2-11B DATASET v1.0 Category: Threading Library Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

#define NUM_ITEMS 10
#define NUM_PRODUCERS 2
#define NUM_CONSUMERS 2

// Define the structure for the producer
typedef struct {
    int item_index;
    int item;
    sem_t semaphore;
} producer_t;

// Define the structure for the consumer
typedef struct {
    int item_index;
    int item;
    sem_t semaphore;
} consumer_t;

// Define the function prototypes
void* producer(void* arg);
void* consumer(void* arg);
void print_results(int producer_result, int consumer_result);

// Create a shared buffer for the producer and consumer
int buffer[NUM_ITEMS];

// Create the semaphore for the producer
sem_t producer_semaphore;

// Create the semaphore for the consumer
sem_t consumer_semaphore;

// Initialize the semaphores
void initialize_semaphores() {
    sem_init(&producer_semaphore, 0, 0);
    sem_init(&consumer_semaphore, 0, 0);
}

// Define the function for the producer
void* producer(void* arg) {
    producer_t* producer = (producer_t*) arg;
    for (int i = 0; i < NUM_ITEMS; i++) {
        sem_wait(&producer_semaphore);
        producer->item = rand() % 100;
        producer->item_index = i;
        sem_post(&producer_semaphore);
        usleep(100000); // Sleep for 0.1 seconds
    }
    sem_destroy(&producer_semaphore);
    pthread_exit(NULL);
}

// Define the function for the consumer
void* consumer(void* arg) {
    consumer_t* consumer = (consumer_t*) arg;
    for (int i = 0; i < NUM_ITEMS; i++) {
        sem_wait(&consumer_semaphore);
        printf("Consumed item %d with index %d\n", consumer->item, consumer->item_index);
        sem_post(&consumer_semaphore);
        usleep(100000); // Sleep for 0.1 seconds
    }
    sem_destroy(&consumer_semaphore);
    pthread_exit(NULL);
}

// Define the function to print the results
void print_results(int producer_result, int consumer_result) {
    printf("Producer produced %d items\n", producer_result);
    printf("Consumer consumed %d items\n", consumer_result);
}

int main() {
    pthread_t producer_thread, consumer_thread;

    // Create the producer and consumer threads
    pthread_create(&producer_thread, NULL, producer, (void*) malloc(sizeof(producer_t)));
    pthread_create(&consumer_thread, NULL, consumer, (void*) malloc(sizeof(consumer_t)));

    // Wait for the producer and consumer threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // Free the memory allocated for the producer and consumer
    free((void*) malloc(sizeof(producer_t)));
    free((void*) malloc(sizeof(consumer_t)));

    // Destroy the semaphores
    sem_destroy(&producer_semaphore);
    sem_destroy(&consumer_semaphore);

    // Call the function to print the results
    print_results(NUM_ITEMS, NUM_ITEMS);

    return 0;
}