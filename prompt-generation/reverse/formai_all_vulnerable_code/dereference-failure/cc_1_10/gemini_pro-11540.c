//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

// Baggage types
#define NORMAL 1
#define OVERSIZED 2
#define FRAGILE 3

// Baggage states
#define WAITING_FOR_CHECKIN 1
#define IN_CHECKIN 2
#define WAITING_FOR_SCANNING 3
#define IN_SCANNING 4
#define WAITING_FOR_LOADING 5
#define IN_LOADING 6
#define IN_TRANSIT 7
#define WAITING_FOR_UNLOADING 8
#define IN_UNLOADING 9
#define DELIVERED 10

// Airport resources
#define CHECKIN_COUNTERS 4
#define SCANNING_MACHINES 2
#define LOADING_BAYS 3
#define UNLOADING_BAYS 2

// Semaphores
sem_t checkin_counters;
sem_t scanning_machines;
sem_t loading_bays;
sem_t unloading_bays;

// Mutexes
pthread_mutex_t baggage_mutex;

// Baggage queue
struct baggage {
    int id;
    int type;
    int state;
    struct baggage *next;
};

struct baggage *head = NULL;
struct baggage *tail = NULL;

// Passenger thread
void *passenger(void *arg) {
    int id = *(int *)arg;

    // Create baggage
    struct baggage *baggage = (struct baggage *)malloc(sizeof(struct baggage));
    baggage->id = id;
    baggage->type = rand() % 3 + 1;
    baggage->state = WAITING_FOR_CHECKIN;

    // Enqueue baggage
    pthread_mutex_lock(&baggage_mutex);
    if (head == NULL) {
        head = baggage;
    } else {
        tail->next = baggage;
    }
    tail = baggage;
    pthread_mutex_unlock(&baggage_mutex);

    // Wait for baggage to be checked in
    sem_wait(&checkin_counters);

    // Check in baggage
    baggage->state = IN_CHECKIN;
    sleep(rand() % 5);
    baggage->state = WAITING_FOR_SCANNING;

    // Signal that baggage is ready for scanning
    sem_post(&checkin_counters);

    // Wait for baggage to be scanned
    sem_wait(&scanning_machines);

    // Scan baggage
    baggage->state = IN_SCANNING;
    sleep(rand() % 3);
    baggage->state = WAITING_FOR_LOADING;

    // Signal that baggage is ready for loading
    sem_post(&scanning_machines);

    // Wait for baggage to be loaded
    sem_wait(&loading_bays);

    // Load baggage
    baggage->state = IN_LOADING;
    sleep(rand() % 7);
    baggage->state = IN_TRANSIT;

    // Signal that baggage is loaded
    sem_post(&loading_bays);

    // Wait for baggage to be unloaded
    sem_wait(&unloading_bays);

    // Unload baggage
    baggage->state = IN_UNLOADING;
    sleep(rand() % 5);
    baggage->state = DELIVERED;

    // Signal that baggage is unloaded
    sem_post(&unloading_bays);

    // Free baggage
    free(baggage);

    return NULL;
}

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Initialize semaphores and mutexes
    sem_init(&checkin_counters, 0, CHECKIN_COUNTERS);
    sem_init(&scanning_machines, 0, SCANNING_MACHINES);
    sem_init(&loading_bays, 0, LOADING_BAYS);
    sem_init(&unloading_bays, 0, UNLOADING_BAYS);
    pthread_mutex_init(&baggage_mutex, NULL);

    // Create passenger threads
    pthread_t passengers[100];
    int passenger_ids[100];
    for (int i = 0; i < 100; i++) {
        passenger_ids[i] = i;
        pthread_create(&passengers[i], NULL, passenger, &passenger_ids[i]);
    }

    // Join passenger threads
    for (int i = 0; i < 100; i++) {
        pthread_join(passengers[i], NULL);
    }

    // Destroy semaphores and mutexes
    sem_destroy(&checkin_counters);
    sem_destroy(&scanning_machines);
    sem_destroy(&loading_bays);
    sem_destroy(&unloading_bays);
    pthread_mutex_destroy(&baggage_mutex);

    return 0;
}