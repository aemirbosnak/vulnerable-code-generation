//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_BAGS 5
#define MAX_CONVEYORS 3

sem_t freeBags; 
pthread_mutex_t mutex;

typedef struct {
    int bagId;
    int conveyorId;
} Baggage;

void* conveyor(void* arg) {
    int conveyorId = *((int*)arg);
    while (1) {
        sem_wait(&freeBags);
        pthread_mutex_lock(&mutex);

        Baggage* baggage = (Baggage*)malloc(sizeof(Baggage));
        baggage->bagId = rand() % 1000;
        baggage->conveyorId = conveyorId;

        printf("Conveyor %d: Created Bag %d\n", conveyorId, baggage->bagId);
        sleep(1); // Simulate time delay for bag creation

        printf("Conveyor %d: Sending Bag %d to the system\n", conveyorId, baggage->bagId);
        free(baggage);
        
        pthread_mutex_unlock(&mutex);
        sleep(rand() % 3); // Simulate time interval before creating the next bag
    }
}

void* baggageHandler(void* arg) {
    while (1) {
        sleep(2); // Simulate time interval for baggage handling
        printf("Baggage Handler: Processing a bag\n");

        // Simulate fulfilling a task, which would be a more complex operation in a real system
        sleep(1); // Simulating bag processing time
        printf("Baggage Handler: Finished processing a bag\n");
        
        sem_post(&freeBags);
    }
}

int main() {
    srand(time(0));
    pthread_t conveyors[MAX_CONVEYORS], handler;
    sem_init(&freeBags, 0, MAX_BAGS); // Initialize the semaphore with MAX_BAGS
    pthread_mutex_init(&mutex, NULL);

    printf("Starting the Baggage Handling System...\n");

    // Create baggage handler thread
    pthread_create(&handler, NULL, baggageHandler, NULL);

    // Create conveyor threads
    int conveyorIds[MAX_CONVEYORS];
    for (int i = 0; i < MAX_CONVEYORS; i++) {
        conveyorIds[i] = i + 1; // Assign conveyor ID
        pthread_create(&conveyors[i], NULL, conveyor, (void*)&conveyorIds[i]);
    }

    // Wait for all threads to finish (they won't in this simulation, but it's good practice)
    pthread_join(handler, NULL);
    for (int i = 0; i < MAX_CONVEYORS; i++) {
        pthread_join(conveyors[i], NULL);
    }

    // Clean up resources
    sem_destroy(&freeBags);
    pthread_mutex_destroy(&mutex);
    printf("Baggage Handling System shutting down...\n");
    
    return 0;
}