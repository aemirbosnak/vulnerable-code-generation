//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_BAGS 100
#define NUM_CONVEYORS 5
#define NUM_TERMINALS 3

typedef struct {
    int id;
    char destination[30];
} Bag;

Bag baggageQueue[MAX_BAGS];
int bagCount = 0;
sem_t bagSemaphore;

void* conveyorBelt(void* arg) {
    int conveyorId = *((int *)arg);
    while (1) {
        sem_wait(&bagSemaphore);
        if (bagCount > 0) {
            Bag movingBag = baggageQueue[--bagCount];

            printf("Conveyor %d is processing Bag ID %d to %s\n", conveyorId, movingBag.id, movingBag.destination);
            sleep(2);
            printf("Bag ID %d has been dispatched to Terminal!\n", movingBag.id);
        }
        sem_post(&bagSemaphore);
        sleep(1);
    }
    return NULL;
}

void* createBags(void* arg) {
    int bagId = 1;
    char* destinations[] = {"New York", "London", "Tokyo", "Paris", "Sydney"};
    
    while (1) {
        sem_wait(&bagSemaphore);
        if (bagCount < MAX_BAGS) {
            Bag newBag;
            newBag.id = bagId++;
            strcpy(newBag.destination, destinations[rand() % 5]);
            baggageQueue[bagCount++] = newBag;

            printf("New Bag ID %d for %s added to the queue.\n", newBag.id, newBag.destination);
        }
        sem_post(&bagSemaphore);
        sleep(rand() % 3 + 1);
    }
    return NULL;
}

int main() {
    pthread_t conveyors[NUM_CONVEYORS];
    pthread_t bagCreator;
    
    srand(time(NULL));
    sem_init(&bagSemaphore, 0, 1);

    // Start threads for conveyors
    for (int i = 0; i < NUM_CONVEYORS; i++) {
        int* conveyorId = malloc(sizeof(int));
        *conveyorId = i + 1;
        pthread_create(&conveyors[i], NULL, conveyorBelt, conveyorId);
    }

    // Start thread for creating bags
    pthread_create(&bagCreator, NULL, createBags, NULL);

    // Run the system for a specified duration
    printf("Baggage Handling System Initiated. Press Ctrl+C to exit.\n");
    while (1) {
        sleep(60); // Keep the system running
    }

    // Clean up (will never reach here)
    sem_destroy(&bagSemaphore);
    return 0;
}