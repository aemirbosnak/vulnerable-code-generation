//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_BAGS 100
#define NUM_CHECK_IN_COUNTERS 5
#define NUM_SECURITY_CHECKS 3
#define NUM_BAGGAGE_CLAIM_BELTS 4

// Semaphores to control access to shared resources
sem_t check_in_counters;
sem_t security_checks;
sem_t baggage_claim_belts;

// Mutex to protect shared data
pthread_mutex_t data_mutex;

// Condition variable to wait for baggage to be checked in
pthread_cond_t check_in_cond;

// Condition variable to wait for baggage to be cleared through security
pthread_cond_t security_cond;

// Condition variable to wait for baggage to be claimed
pthread_cond_t claim_cond;

// Baggage queue
struct baggage {
    int id;
    int status; // 0: checked in, 1: cleared through security, 2: claimed
} baggage_queue[NUM_BAGS];

// Function to simulate a passenger checking in their baggage
void *check_in_baggage(void *arg) {
    int id = *(int *)arg;

    // Wait for a check-in counter to become available
    sem_wait(&check_in_counters);

    // Acquire the mutex to protect shared data
    pthread_mutex_lock(&data_mutex);

    // Check in the baggage
    baggage_queue[id].status = 0;

    // Signal that the baggage has been checked in
    pthread_cond_signal(&check_in_cond);

    // Release the mutex
    pthread_mutex_unlock(&data_mutex);

    // Release the check-in counter
    sem_post(&check_in_counters);

    return NULL;
}

// Function to simulate security checking baggage
void *security_check_baggage(void *arg) {
    int id = *(int *)arg;

    // Wait for baggage to be checked in
    pthread_mutex_lock(&data_mutex);
    while (baggage_queue[id].status != 0) {
        pthread_cond_wait(&check_in_cond, &data_mutex);
    }
    pthread_mutex_unlock(&data_mutex);

    // Wait for a security check to become available
    sem_wait(&security_checks);

    // Acquire the mutex to protect shared data
    pthread_mutex_lock(&data_mutex);

    // Clear the baggage through security
    baggage_queue[id].status = 1;

    // Signal that the baggage has been cleared through security
    pthread_cond_signal(&security_cond);

    // Release the mutex
    pthread_mutex_unlock(&data_mutex);

    // Release the security check
    sem_post(&security_checks);

    return NULL;
}

// Function to simulate a passenger claiming their baggage
void *claim_baggage(void *arg) {
    int id = *(int *)arg;

    // Wait for baggage to be cleared through security
    pthread_mutex_lock(&data_mutex);
    while (baggage_queue[id].status != 1) {
        pthread_cond_wait(&security_cond, &data_mutex);
    }
    pthread_mutex_unlock(&data_mutex);

    // Wait for a baggage claim belt to become available
    sem_wait(&baggage_claim_belts);

    // Acquire the mutex to protect shared data
    pthread_mutex_lock(&data_mutex);

    // Claim the baggage
    baggage_queue[id].status = 2;

    // Signal that the baggage has been claimed
    pthread_cond_signal(&claim_cond);

    // Release the mutex
    pthread_mutex_unlock(&data_mutex);

    // Release the baggage claim belt
    sem_post(&baggage_claim_belts);

    return NULL;
}

// Main function
int main() {
    // Initialize semaphores
    sem_init(&check_in_counters, 0, NUM_CHECK_IN_COUNTERS);
    sem_init(&security_checks, 0, NUM_SECURITY_CHECKS);
    sem_init(&baggage_claim_belts, 0, NUM_BAGGAGE_CLAIM_BELTS);

    // Initialize mutex and condition variables
    pthread_mutex_init(&data_mutex, NULL);
    pthread_cond_init(&check_in_cond, NULL);
    pthread_cond_init(&security_cond, NULL);
    pthread_cond_init(&claim_cond, NULL);

    // Create threads to simulate passengers checking in their baggage
    pthread_t check_in_threads[NUM_BAGS];
    for (int i = 0; i < NUM_BAGS; i++) {
        int *id = malloc(sizeof(int));
        *id = i;
        pthread_create(&check_in_threads[i], NULL, check_in_baggage, id);
    }

    // Create threads to simulate security checking baggage
    pthread_t security_check_threads[NUM_BAGS];
    for (int i = 0; i < NUM_BAGS; i++) {
        int *id = malloc(sizeof(int));
        *id = i;
        pthread_create(&security_check_threads[i], NULL, security_check_baggage, id);
    }

    // Create threads to simulate passengers claiming their baggage
    pthread_t claim_threads[NUM_BAGS];
    for (int i = 0; i < NUM_BAGS; i++) {
        int *id = malloc(sizeof(int));
        *id = i;
        pthread_create(&claim_threads[i], NULL, claim_baggage, id);
    }

    // Join all threads
    for (int i = 0; i < NUM_BAGS; i++) {
        pthread_join(check_in_threads[i], NULL);
        pthread_join(security_check_threads[i], NULL);
        pthread_join(claim_threads[i], NULL);
    }

    // Destroy semaphores, mutex, and condition variables
    sem_destroy(&check_in_counters);
    sem_destroy(&security_checks);
    sem_destroy(&baggage_claim_belts);
    pthread_mutex_destroy(&data_mutex);
    pthread_cond_destroy(&check_in_cond);
    pthread_cond_destroy(&security_cond);
    pthread_cond_destroy(&claim_cond);

    return 0;
}