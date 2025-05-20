//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CAPACITY 30   // Maximum capacity of the conveyor belt
#define MAX_BAGGAGE_PIECES 5    // Maximum baggage pieces that can be handled by the baggage handling system at a time

int conveyorBelt[MAX_CAPACITY];   // The conveyor belt to store luggage

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t full = PTHREAD_COND_INITIALIZER;
pthread_cond_t empty = PTHREAD_COND_INITIALIZER;

int count = 0;     // Number of luggage pieces currently on the conveyor belt

void *airport_attendant(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);     
        
        while (count == 0) {
            // Wait for a signal once the conveyor belt is empty
            pthread_cond_wait(&full, &mutex);
        }
        
        // Remove baggage from the conveyor and process it
        int luggage = conveyorBelt[--count];
        printf("Processing luggage #%d\n", luggage);
        fflush(stdout);
        
        pthread_cond_signal(&empty);      // Signal that the conveyor belt is no longer full
        
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void *passenger(void *arg) {
    int passenger_id = *(int*)arg;
    int luggage_pieces = rand() % MAX_BAGGAGE_PIECES + 1;
    
    while (luggage_pieces > 0) {
        pthread_mutex_lock(&mutex);     
        
        while (count == MAX_CAPACITY) {
            // Wait for a signal once the conveyor belt is full
            pthread_cond_wait(&empty, &mutex);
        }
        
        // Add luggage to the conveyor belt
        conveyorBelt[count++] = passenger_id * 10 + luggage_pieces;
        printf("Passenger #%d added luggage #%d to conveyor belt\n", passenger_id, passenger_id * 10 + luggage_pieces);
        fflush(stdout);
        
        luggage_pieces -= 1;
        
        pthread_cond_signal(&full);      // Signal that the conveyor belt is no longer empty
        
        pthread_mutex_unlock(&mutex);
        
        sleep(rand() % 3);      // Simulates time taken by passenger to add luggage
    }
    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));     // Seed the random number generator
    
    // Creating threads
    pthread_t attendant_thread;
    pthread_create(&attendant_thread, NULL, airport_attendant, NULL);
    
    pthread_t passenger_threads[MAX_CAPACITY * 2];    // Maximum 60 passengers on the conveyor belt
    for (int i = 0; i < MAX_CAPACITY * 2; i++) {
        int *passenger_id = malloc(sizeof(*passenger_id));
        *passenger_id = i;
        pthread_create(&passenger_threads[i], NULL, passenger, (void*)passenger_id);
    }
    
    // Joining threads
    pthread_join(attendant_thread, NULL);
    for (int i = 0; i < MAX_CAPACITY * 2; i++) {
        pthread_join(passenger_threads[i], NULL);
    }
    
    // Clean up
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&full);
    pthread_cond_destroy(&empty);
    
    return 0;
}