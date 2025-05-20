//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_BAGS 100
#define NUM_CHECKIN_COUNTERS 4
#define NUM_SECURITY_CHECKS 2
#define NUM_BAGGAGE_CLAIM_BELTS 4

// Baggage status
enum {
    BAGGAGE_CREATED,
    BAGGAGE_CHECKED_IN,
    BAGGAGE_SECURITY_CHECKED,
    BAGGAGE_CLAIMED
};

// Baggage structure
struct baggage {
    int id;
    int status;
    pthread_mutex_t lock;
};

// Shared resources
struct resources {
    // Baggage queues
    struct baggage *checkin_queue[NUM_BAGS];
    struct baggage *security_queue[NUM_BAGS];
    struct baggage *baggage_claim_queue[NUM_BAGS];

    // Semaphores
    sem_t checkin_semaphore;
    sem_t security_semaphore;
    sem_t baggage_claim_semaphore;
};

// Function prototypes
void *checkin_thread(void *arg);
void *security_thread(void *arg);
void *baggage_claim_thread(void *arg);
void create_baggage(struct resources *resources);

int main() {
    // Initialize shared resources
    struct resources resources;
    sem_init(&resources.checkin_semaphore, 0, NUM_CHECKIN_COUNTERS);
    sem_init(&resources.security_semaphore, 0, NUM_SECURITY_CHECKS);
    sem_init(&resources.baggage_claim_semaphore, 0, NUM_BAGGAGE_CLAIM_BELTS);

    // Create baggage
    create_baggage(&resources);

    // Create checkin threads
    pthread_t checkin_threads[NUM_CHECKIN_COUNTERS];
    for (int i = 0; i < NUM_CHECKIN_COUNTERS; i++) {
        pthread_create(&checkin_threads[i], NULL, checkin_thread, &resources);
    }

    // Create security threads
    pthread_t security_threads[NUM_SECURITY_CHECKS];
    for (int i = 0; i < NUM_SECURITY_CHECKS; i++) {
        pthread_create(&security_threads[i], NULL, security_thread, &resources);
    }

    // Create baggage claim threads
    pthread_t baggage_claim_threads[NUM_BAGGAGE_CLAIM_BELTS];
    for (int i = 0; i < NUM_BAGGAGE_CLAIM_BELTS; i++) {
        pthread_create(&baggage_claim_threads[i], NULL, baggage_claim_thread, &resources);
    }

    // Join threads
    for (int i = 0; i < NUM_CHECKIN_COUNTERS; i++) {
        pthread_join(checkin_threads[i], NULL);
    }
    for (int i = 0; i < NUM_SECURITY_CHECKS; i++) {
        pthread_join(security_threads[i], NULL);
    }
    for (int i = 0; i < NUM_BAGGAGE_CLAIM_BELTS; i++) {
        pthread_join(baggage_claim_threads[i], NULL);
    }

    // Destroy semaphores
    sem_destroy(&resources.checkin_semaphore);
    sem_destroy(&resources.security_semaphore);
    sem_destroy(&resources.baggage_claim_semaphore);

    return 0;
}

void *checkin_thread(void *arg) {
    struct resources *resources = (struct resources *)arg;

    while (1) {
        // Wait for a baggage to be created
        sem_wait(&resources->checkin_semaphore);

        // Get the next baggage from the queue
        struct baggage *baggage = resources->checkin_queue[0];

        // Check in the baggage
        pthread_mutex_lock(&baggage->lock);
        baggage->status = BAGGAGE_CHECKED_IN;
        pthread_mutex_unlock(&baggage->lock);

        // Move the baggage to the security queue
        resources->security_queue[resources->security_queue[0] == NULL ? 0 : resources->security_queue[0]->id + 1] = baggage;

        // Signal that the baggage has been checked in
        sem_post(&resources->security_semaphore);
    }

    return NULL;
}

void *security_thread(void *arg) {
    struct resources *resources = (struct resources *)arg;

    while (1) {
        // Wait for a baggage to be checked in
        sem_wait(&resources->security_semaphore);

        // Get the next baggage from the queue
        struct baggage *baggage = resources->security_queue[0];

        // Security check the baggage
        pthread_mutex_lock(&baggage->lock);
        baggage->status = BAGGAGE_SECURITY_CHECKED;
        pthread_mutex_unlock(&baggage->lock);

        // Move the baggage to the baggage claim queue
        resources->baggage_claim_queue[resources->baggage_claim_queue[0] == NULL ? 0 : resources->baggage_claim_queue[0]->id + 1] = baggage;

        // Signal that the baggage has been security checked
        sem_post(&resources->baggage_claim_semaphore);
    }

    return NULL;
}

void *baggage_claim_thread(void *arg) {
    struct resources *resources = (struct resources *)arg;

    while (1) {
        // Wait for a baggage to be security checked
        sem_wait(&resources->baggage_claim_semaphore);

        // Get the next baggage from the queue
        struct baggage *baggage = resources->baggage_claim_queue[0];

        // Claim the baggage
        pthread_mutex_lock(&baggage->lock);
        baggage->status = BAGGAGE_CLAIMED;
        pthread_mutex_unlock(&baggage->lock);

        // Remove the baggage from the queue
        resources->baggage_claim_queue[0] = NULL;

        // Signal that the baggage has been claimed
        sem_post(&resources->checkin_semaphore);
    }

    return NULL;
}

void create_baggage(struct resources *resources) {
    for (int i = 0; i < NUM_BAGS; i++) {
        // Create a new baggage
        struct baggage *baggage = malloc(sizeof(struct baggage));
        baggage->id = i;
        baggage->status = BAGGAGE_CREATED;
        pthread_mutex_init(&baggage->lock, NULL);

        // Add the baggage to the checkin queue
        resources->checkin_queue[i] = baggage;
    }
}