//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Linus Torvalds
// Linus Torvalds-style Airport Baggage Handling Simulation

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

// Define the number of baggage handlers and conveyor belts
#define NUM_HANDLERS 5
#define NUM_BELTS 3

// Define the maximum number of bags on a conveyor belt
#define MAX_BAGS_PER_BELT 10

// Define the semaphore for the conveyor belts
sem_t belts[NUM_BELTS];

// Define the mutex for the baggage handlers
pthread_mutex_t handlers_mutex;

// Define the condition variable for the baggage handlers
pthread_cond_t handlers_cond;

// Define the baggage handler thread function
void *baggage_handler(void *arg)
{
    int i;
    int belt;
    int bag;

    while (1)
    {
        // Lock the mutex
        pthread_mutex_lock(&handlers_mutex);

        // Wait for a signal from the main thread
        pthread_cond_wait(&handlers_cond, &handlers_mutex);

        // Unlock the mutex
        pthread_mutex_unlock(&handlers_mutex);

        // Get the next belt to handle
        belt = (int)arg;

        // Get the next bag from the belt
        sem_wait(&belts[belt]);
        bag = rand() % MAX_BAGS_PER_BELT;

        // Handle the bag
        printf("Baggage handler %d handled bag %d from belt %d\n", (int)pthread_self(), bag, belt);

        // Release the semaphore for the belt
        sem_post(&belts[belt]);
    }

    return NULL;
}

// Define the main thread function
int main(void)
{
    int i;
    int j;
    int bag;

    // Initialize the semaphore for the conveyor belts
    for (i = 0; i < NUM_BELTS; i++)
    {
        sem_init(&belts[i], 0, 0);
    }

    // Initialize the mutex for the baggage handlers
    pthread_mutex_init(&handlers_mutex, NULL);

    // Initialize the condition variable for the baggage handlers
    pthread_cond_init(&handlers_cond, NULL);

    // Create the baggage handler threads
    pthread_t handlers[NUM_HANDLERS];
    for (i = 0; i < NUM_HANDLERS; i++)
    {
        pthread_create(&handlers[i], NULL, baggage_handler, (void *)i);
    }

    // Load the conveyor belts with bags
    while (1)
    {
        // Sleep for a random amount of time
        sleep(rand() % 5);

        // Get the next belt to load
        i = rand() % NUM_BELTS;

        // Get the next bag to load
        bag = rand() % MAX_BAGS_PER_BELT;

        // Load the bag onto the belt
        sem_post(&belts[i]);
        printf("Loaded bag %d onto belt %d\n", bag, i);

        // Signal the baggage handlers
        pthread_cond_broadcast(&handlers_cond);
    }

    // Join the baggage handler threads
    for (i = 0; i < NUM_HANDLERS; i++)
    {
        pthread_join(handlers[i], NULL);
    }

    // Destroy the semaphore for the conveyor belts
    for (i = 0; i < NUM_BELTS; i++)
    {
        sem_destroy(&belts[i]);
    }

    // Destroy the mutex for the baggage handlers
    pthread_mutex_destroy(&handlers_mutex);

    // Destroy the condition variable for the baggage handlers
    pthread_cond_destroy(&handlers_cond);

    return 0;
}