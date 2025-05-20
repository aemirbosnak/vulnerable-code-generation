//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: grateful
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

// Global variables
int num_threads;
int num_bags;
int num_belts;
sem_t *belts;
sem_t *bags;
pthread_mutex_t mutex;

// Function to simulate a passenger 
void *passenger(void *arg) {
    // Get the passenger's ID
    int id = *(int *)arg;

    // Create a bag
    int bag = rand() % num_bags;

    // Acquire the lock on the belts
    pthread_mutex_lock(&mutex);

    // Find an empty belt
    int belt = -1;
    for (int i = 0; i < num_belts; i++) {
        if (sem_trywait(&belts[i]) == 0) {
            belt = i;
            break;
        }
    }

    // If no belt is available, wait for one to become available
    if (belt == -1) {
        sem_wait(&bags);
        belt = rand() % num_belts;
        sem_wait(&belts[belt]);
    }

    // Put the bag on the belt
    printf("Passenger %d put bag %d on belt %d\n", id, bag, belt);

    // Release the lock on the belts
    pthread_mutex_unlock(&mutex);

    // Release the bag
    sem_post(&bags);

    return NULL;
}

// Function to simulate a baggage handler 
void *baggage_handler(void *arg) {
    // Get the baggage handler's ID
    int id = *(int *)arg;

    // Acquire the lock on the belts
    pthread_mutex_lock(&mutex);

    // Find a belt with a bag on it
    int belt = -1;
    for (int i = 0; i < num_belts; i++) {
        if (sem_trywait(&belts[i]) == 0) {
            belt = i;
            break;
        }
    }

    // If no belt has a bag on it, wait for one to become available
    if (belt == -1) {
        sem_wait(&bags);
        belt = rand() % num_belts;
        sem_wait(&belts[belt]);
    }

    // Take the bag off the belt
    int bag = rand() % num_bags;
    printf("Baggage handler %d took bag %d from belt %d\n", id, bag, belt);

    // Release the lock on the belts
    pthread_mutex_unlock(&mutex);

    // Release the belt
    sem_post(&belts[belt]);

    return NULL;
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Get the number of threads, bags, and belts from the user
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);
    printf("Enter the number of bags: ");
    scanf("%d", &num_bags);
    printf("Enter the number of belts: ");
    scanf("%d", &num_belts);

    // Create the semaphores
    belts = malloc(sizeof(sem_t) * num_belts);
    bags = malloc(sizeof(sem_t));
    for (int i = 0; i < num_belts; i++) {
        sem_init(&belts[i], 0, 1);
    }
    sem_init(bags, 0, 0);

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create the threads
    pthread_t *threads = malloc(sizeof(pthread_t) * num_threads);
    for (int i = 0; i < num_threads; i++) {
        int *arg = malloc(sizeof(int));
        *arg = i;
        pthread_create(&threads[i], NULL, passenger, arg);
    }

    // Join the threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the semaphores
    for (int i = 0; i < num_belts; i++) {
        sem_destroy(&belts[i]);
    }
    sem_destroy(bags);

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}