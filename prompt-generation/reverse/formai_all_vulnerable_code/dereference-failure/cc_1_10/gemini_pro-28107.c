//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

// Constants
#define NUM_BAGS 100
#define NUM_CHECKIN_COUNTERS 5
#define NUM_SECURITY_CHECKS 3
#define NUM_BAGGAGE_CLAIM_BELTS 4

// Semaphores
sem_t checkin_counters;
sem_t security_checks;
sem_t baggage_claim_belts;

// Mutexes
pthread_mutex_t baggage_mutex;

// Baggage struct
typedef struct
{
    int id;
    int status; // 0: checked in, 1: security check, 2: baggage claim
} baggage;

// Baggage list
baggage *baggage_list;

// Thread functions
void *checkin_thread(void *arg);
void *security_check_thread(void *arg);
void *baggage_claim_thread(void *arg);

// Main function
int main()
{
    // Initialize semaphores and mutexes
    sem_init(&checkin_counters, 0, NUM_CHECKIN_COUNTERS);
    sem_init(&security_checks, 0, NUM_SECURITY_CHECKS);
    sem_init(&baggage_claim_belts, 0, NUM_BAGGAGE_CLAIM_BELTS);
    pthread_mutex_init(&baggage_mutex, NULL);

    // Create baggage list
    baggage_list = malloc(sizeof(baggage) * NUM_BAGS);
    for (int i = 0; i < NUM_BAGS; i++)
    {
        baggage_list[i].id = i;
        baggage_list[i].status = 0;
    }

    // Create threads
    pthread_t checkin_threads[NUM_CHECKIN_COUNTERS];
    pthread_t security_check_threads[NUM_SECURITY_CHECKS];
    pthread_t baggage_claim_threads[NUM_BAGGAGE_CLAIM_BELTS];

    for (int i = 0; i < NUM_CHECKIN_COUNTERS; i++)
    {
        pthread_create(&checkin_threads[i], NULL, checkin_thread, NULL);
    }

    for (int i = 0; i < NUM_SECURITY_CHECKS; i++)
    {
        pthread_create(&security_check_threads[i], NULL, security_check_thread, NULL);
    }

    for (int i = 0; i < NUM_BAGGAGE_CLAIM_BELTS; i++)
    {
        pthread_create(&baggage_claim_threads[i], NULL, baggage_claim_thread, NULL);
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_CHECKIN_COUNTERS; i++)
    {
        pthread_join(checkin_threads[i], NULL);
    }

    for (int i = 0; i < NUM_SECURITY_CHECKS; i++)
    {
        pthread_join(security_check_threads[i], NULL);
    }

    for (int i = 0; i < NUM_BAGGAGE_CLAIM_BELTS; i++)
    {
        pthread_join(baggage_claim_threads[i], NULL);
    }

    // Destroy semaphores and mutexes
    sem_destroy(&checkin_counters);
    sem_destroy(&security_checks);
    sem_destroy(&baggage_claim_belts);
    pthread_mutex_destroy(&baggage_mutex);

    // Free baggage list
    free(baggage_list);

    return 0;
}

// Checkin thread function
void *checkin_thread(void *arg)
{
    while (1)
    {
        // Wait for a free checkin counter
        sem_wait(&checkin_counters);

        // Get a random bag
        pthread_mutex_lock(&baggage_mutex);
        int bag_index = rand() % NUM_BAGS;
        pthread_mutex_unlock(&baggage_mutex);

        // Check in the bag
        baggage_list[bag_index].status = 1;

        // Signal that the bag has been checked in
        sem_post(&security_checks);
    }

    return NULL;
}

// Security check thread function
void *security_check_thread(void *arg)
{
    while (1)
    {
        // Wait for a bag to be checked in
        sem_wait(&security_checks);

        // Get a random bag
        pthread_mutex_lock(&baggage_mutex);
        int bag_index = rand() % NUM_BAGS;
        pthread_mutex_unlock(&baggage_mutex);

        // Security check the bag
        baggage_list[bag_index].status = 2;

        // Signal that the bag has been security checked
        sem_post(&baggage_claim_belts);
    }

    return NULL;
}

// Baggage claim thread function
void *baggage_claim_thread(void *arg)
{
    while (1)
    {
        // Wait for a bag to be security checked
        sem_wait(&baggage_claim_belts);

        // Get a random bag
        pthread_mutex_lock(&baggage_mutex);
        int bag_index = rand() % NUM_BAGS;
        pthread_mutex_unlock(&baggage_mutex);

        // Claim the bag
        printf("Bag %d claimed\n", baggage_list[bag_index].id);
    }

    return NULL;
}