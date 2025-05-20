//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_TERMINALS 4
#define BAG_SIZE 10
#define NUM_THREADS 50

// Declare a mutex and condition variable for the conveyor belt
pthread_mutex_t conveyor_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t conveyor_cond = PTHREAD_COND_INITIALIZER;

// Declare a mutex and condition variable for the terminals
pthread_mutex_t terminal_mutex[NUM_TERMINALS];
pthread_cond_t terminal_cond[NUM_TERMINALS];

// Declare a struct to represent a baggage
typedef struct Baggage {
    int id;
    int terminal;
} Baggage;

int conveyor_count = 0; // Count of baggages on conveyor belt
int baggage_counter = 1; // Counter to assign unique id to baggages

Baggage conveyor_belt[BAG_SIZE]; // Array representing the conveyor belt
int conveyor_head = 0; // Index of the head of the conveyor belt
int conveyor_tail = 0; // Index of the tail of the conveyor belt

bool is_running = true; // Flag to indicate whether the simulation is running

// Function to add a baggage to the conveyor belt
void add_to_conveyor() {
    Baggage baggage = {baggage_counter++, rand() % NUM_TERMINALS};
    
    pthread_mutex_lock(&conveyor_mutex);
    
    while (conveyor_count == BAG_SIZE) {
        pthread_cond_wait(&conveyor_cond, &conveyor_mutex);
    }
    
    conveyor_belt[conveyor_tail] = baggage;
    conveyor_tail = (conveyor_tail + 1) % BAG_SIZE;
    conveyor_count++;
    
    printf("Added Baggage %d to Conveyor Belt\n", baggage.id);
    
    pthread_cond_broadcast(&terminal_cond[baggage.terminal]);
    pthread_mutex_unlock(&conveyor_mutex);
}

// Function to remove a baggage from the conveyor belt
Baggage remove_from_conveyor() {
    pthread_mutex_lock(&conveyor_mutex);
    
    while (conveyor_count == 0) {
        pthread_cond_wait(&conveyor_cond, &conveyor_mutex);
    }
    
    Baggage baggage = conveyor_belt[conveyor_head];
    conveyor_head = (conveyor_head + 1) % BAG_SIZE;
    conveyor_count--;
    
    printf("Removed Baggage %d from Conveyor Belt\n", baggage.id);
    
    pthread_cond_broadcast(&conveyor_cond);
    pthread_mutex_unlock(&conveyor_mutex);
    
    return baggage;
}

// Function for the baggage handler thread
void* baggage_handler(void* arg) {
    while (is_running) {
        add_to_conveyor();
        usleep(rand() % 100000);
    }
    
    return NULL;
}

// Function for the terminal worker thread
void* terminal_worker(void* arg) {
    int terminal_id = *(int*)arg;
    
    while (is_running) {
        pthread_mutex_lock(&terminal_mutex[terminal_id]);
        
        while (conveyor_count == 0 || conveyor_belt[conveyor_head].terminal != terminal_id) {
            pthread_cond_wait(&terminal_cond[terminal_id], &terminal_mutex[terminal_id]);
        }
        
        Baggage baggage = remove_from_conveyor();
        printf("Baggage %d has arrived at Terminal %d\n", baggage.id, baggage.terminal);
        
        pthread_mutex_unlock(&terminal_mutex[terminal_id]);
        usleep(rand() % 100000);
    }
    
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int* terminal_ids[NUM_TERMINALS];
    
    // Initialize terminal mutexes and condition variables
    for (int i = 0; i < NUM_TERMINALS; i++) {
        pthread_mutex_init(&terminal_mutex[i], NULL);
        pthread_cond_init(&terminal_cond[i], NULL);
    }
    
    // Spawn baggage handler thread
    pthread_create(&threads[0], NULL, baggage_handler, NULL);
    
    // Spawn terminal worker threads
    for (int i = 1; i < NUM_THREADS; i++) {
        int* terminal_id = malloc(sizeof(int));
        *terminal_id = i % NUM_TERMINALS;
        terminal_ids[i % NUM_TERMINALS] = terminal_id;
        pthread_create(&threads[i], NULL, terminal_worker, terminal_id);
    }
    
    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Clean up
    for (int i = 0; i < NUM_TERMINALS; i++) {
        pthread_mutex_destroy(&terminal_mutex[i]);
        pthread_cond_destroy(&terminal_cond[i]);
        free(terminal_ids[i]);
    }
    
    return 0;
}