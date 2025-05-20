//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_BAGGAGE 10
#define MAX_PLANE 5
#define MAX_CONVEYOR 2

sem_t baggage_semaphore;
sem_t conveyor_semaphore;
int total_baggage = 0;

// Structure to represent a baggage
typedef struct {
    int id;
    int weight;
} Baggage;

// Function to simulate baggage check-in
void* baggage_check_in(void* args) {
    for (int i = 0; i < MAX_BAGGAGE; i++) {
        Baggage* baggage = (Baggage*)malloc(sizeof(Baggage));
        baggage->id = i + 1;
        baggage->weight = rand() % 20 + 5; // Random weight between 5kg and 24kg
        
        printf("Baggage %d (Weight: %d kg) is checked in\n", baggage->id, baggage->weight);
        
        sem_wait(&baggage_semaphore);

        total_baggage++;
        
        printf("Baggage %d is put on the conveyor\n", baggage->id);
        sleep(1); // Simulate time to put baggage on conveyor
        sem_post(&conveyor_semaphore);
    }
    return NULL;
}

// Function to simulate baggage movement on the conveyor
void* conveyor_belt(void* args) {
    while (1) {
        sem_wait(&conveyor_semaphore);

        if (total_baggage <= 0) {
            printf("Conveyor: No baggage to process. Waiting...\n");
            sem_post(&conveyor_semaphore);
            continue;
        }

        total_baggage--;
        sleep(2); // Simulate time to move baggage
        printf("Conveyor: A baggage has been moved! Total baggage remaining: %d\n", total_baggage);
        
        sem_post(&baggage_semaphore);
    }
    return NULL;
}

// Function to simulate plane boarding
void* boarding_plane(void* args) {
    int plane_number = *(int*)args;
    while (1) {
        printf("Plane %d is waiting for baggage...\n", plane_number);
        sleep(rand() % 5 + 2); // Random wait before picking up baggage
        printf("Plane %d is loading baggage...\n", plane_number);
        
        sleep(3); // Simulate time to load baggages into the plane
        printf("Plane %d has finished loading.\n", plane_number);
    }
    return NULL;
}

int main() {
    srand(time(0));

    sem_init(&baggage_semaphore, 0, MAX_CONVEYOR);
    sem_init(&conveyor_semaphore, 0, 0);
    
    pthread_t baggage_thread;
    pthread_t conveyor_threads[MAX_CONVEYOR];
    pthread_t plane_threads[MAX_PLANE];
    int plane_numbers[MAX_PLANE] = {1, 2, 3, 4, 5};

    // Create baggage check-in thread
    pthread_create(&baggage_thread, NULL, baggage_check_in, NULL);
    
    // Create conveyor threads
    for (int i = 0; i < MAX_CONVEYOR; i++) {
        pthread_create(&conveyor_threads[i], NULL, conveyor_belt, NULL);
    }
    
    // Create plane threads
    for (int i = 0; i < MAX_PLANE; i++) {
        pthread_create(&plane_threads[i], NULL, boarding_plane, &plane_numbers[i]);
    }
    
    // Wait for baggage check-in thread to finish
    pthread_join(baggage_thread, NULL);
    
    // Program never ends, as planes and conveyors are in infinite loops
    pthread_exit(NULL);

    sem_destroy(&baggage_semaphore);
    sem_destroy(&conveyor_semaphore);
    return 0;
}