//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_BAGS 100
#define NUM_CHECKIN_COUNTERS 5
#define NUM_SECURITY_LINES 3
#define NUM_BAGGAGE_CLAIM_AREAS 4

// Semaphores to control access to shared resources
sem_t checkin_counters;
sem_t security_lines;
sem_t baggage_claim_areas;

// Mutex to protect the shared bag queue
pthread_mutex_t bag_queue_mutex;

// Queue to store bags waiting to be processed
struct bag_queue {
    int head;
    int tail;
    int size;
    int *bags;
};

// Initialize the bag queue
struct bag_queue bag_queue;

// Function to initialize the simulation
void init_simulation() {
    // Initialize the semaphores
    sem_init(&checkin_counters, 0, NUM_CHECKIN_COUNTERS);
    sem_init(&security_lines, 0, NUM_SECURITY_LINES);
    sem_init(&baggage_claim_areas, 0, NUM_BAGGAGE_CLAIM_AREAS);

    // Initialize the mutex
    pthread_mutex_init(&bag_queue_mutex, NULL);

    // Initialize the bag queue
    bag_queue.head = 0;
    bag_queue.tail = 0;
    bag_queue.size = NUM_BAGS;
    bag_queue.bags = malloc(sizeof(int) * NUM_BAGS);
}

// Function to generate a random bag
int generate_bag() {
    return rand() % NUM_BAGS;
}

// Function to simulate the checkin process
void *checkin(void *args) {
    int bag = 0;

    while (bag < NUM_BAGS) {
        // Wait for a checkin counter to become available
        sem_wait(&checkin_counters);

        // Generate a new bag
        bag = generate_bag();

        // Add the bag to the queue
        pthread_mutex_lock(&bag_queue_mutex);
        bag_queue.bags[bag_queue.tail] = bag;
        bag_queue.tail = (bag_queue.tail + 1) % bag_queue.size;
        pthread_mutex_unlock(&bag_queue_mutex);

        // Signal that the checkin counter is available
        sem_post(&checkin_counters);

        // Sleep for a random amount of time
        usleep(rand() % 1000000);
    }

    return NULL;
}

// Function to simulate the security screening process
void *security(void *args) {
    int bag = 0;

    while (bag < NUM_BAGS) {
        // Wait for a security line to become available
        sem_wait(&security_lines);

        // Get the next bag from the queue
        pthread_mutex_lock(&bag_queue_mutex);
        bag = bag_queue.bags[bag_queue.head];
        bag_queue.head = (bag_queue.head + 1) % bag_queue.size;
        pthread_mutex_unlock(&bag_queue_mutex);

        // Simulate the security screening process
        usleep(rand() % 1000000);

        // Signal that the security line is available
        sem_post(&security_lines);

        // Sleep for a random amount of time
        usleep(rand() % 1000000);
    }

    return NULL;
}

// Function to simulate the baggage claim process
void *baggage_claim(void *args) {
    int bag = 0;

    while (bag < NUM_BAGS) {
        // Wait for a baggage claim area to become available
        sem_wait(&baggage_claim_areas);

        // Get the next bag from the queue
        pthread_mutex_lock(&bag_queue_mutex);
        bag = bag_queue.bags[bag_queue.head];
        bag_queue.head = (bag_queue.head + 1) % bag_queue.size;
        pthread_mutex_unlock(&bag_queue_mutex);

        // Simulate the baggage claim process
        usleep(rand() % 1000000);

        // Signal that the baggage claim area is available
        sem_post(&baggage_claim_areas);

        // Sleep for a random amount of time
        usleep(rand() % 1000000);
    }

    return NULL;
}

// Function to destroy the simulation
void destroy_simulation() {
    // Destroy the semaphores
    sem_destroy(&checkin_counters);
    sem_destroy(&security_lines);
    sem_destroy(&baggage_claim_areas);

    // Destroy the mutex
    pthread_mutex_destroy(&bag_queue_mutex);

    // Free the bag queue
    free(bag_queue.bags);
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Initialize the simulation
    init_simulation();

    // Create the threads
    pthread_t checkin_threads[NUM_CHECKIN_COUNTERS];
    pthread_t security_threads[NUM_SECURITY_LINES];
    pthread_t baggage_claim_threads[NUM_BAGGAGE_CLAIM_AREAS];

    for (int i = 0; i < NUM_CHECKIN_COUNTERS; i++) {
        pthread_create(&checkin_threads[i], NULL, checkin, NULL);
    }

    for (int i = 0; i < NUM_SECURITY_LINES; i++) {
        pthread_create(&security_threads[i], NULL, security, NULL);
    }

    for (int i = 0; i < NUM_BAGGAGE_CLAIM_AREAS; i++) {
        pthread_create(&baggage_claim_threads[i], NULL, baggage_claim, NULL);
    }

    // Join the threads
    for (int i = 0; i < NUM_CHECKIN_COUNTERS; i++) {
        pthread_join(checkin_threads[i], NULL);
    }

    for (int i = 0; i < NUM_SECURITY_LINES; i++) {
        pthread_join(security_threads[i], NULL);
    }

    for (int i = 0; i < NUM_BAGGAGE_CLAIM_AREAS; i++) {
        pthread_join(baggage_claim_threads[i], NULL);
    }

    // Destroy the simulation
    destroy_simulation();

    return 0;
}