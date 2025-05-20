//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_BAGS 10
#define NUM_PLATFORMS 3
#define BAG_ARRIVAL_TIME 1
#define BAG_HANDLING_TIME 2

typedef struct {
    int id;
    int platformNo;
} Bag;

Bag* bagsQueue[MAX_BAGS];
int front = -1, rear = -1;
sem_t empty, full;
pthread_mutex_t mutexQueue;

void* baggageArrival(void* arg) {
    int bagId = 1;
    while (1) {
        sleep(BAG_ARRIVAL_TIME);  // Simulating time taken for a bag to arrive
        Bag* newBag = malloc(sizeof(Bag));
        newBag->id = bagId++;
        newBag->platformNo = rand() % NUM_PLATFORMS;

        sem_wait(&empty);
        pthread_mutex_lock(&mutexQueue);

        rear = (rear + 1) % MAX_BAGS;
        bagsQueue[rear] = newBag;
        
        if (front == -1) {
            front = 0;
        }

        printf("Bag ID: %d arrived at Platform: %d\n", newBag->id, newBag->platformNo);
        
        pthread_mutex_unlock(&mutexQueue);
        sem_post(&full);
    }
    return NULL;
}

void* baggageHandling(void* arg) {
    while (1) {
        sem_wait(&full);
        pthread_mutex_lock(&mutexQueue);

        Bag* bagToHandle = bagsQueue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_BAGS;
        }

        printf("Handling Bag ID: %d at Platform: %d\n", bagToHandle->id, bagToHandle->platformNo);
        pthread_mutex_unlock(&mutexQueue);
        sem_post(&empty);

        sleep(BAG_HANDLING_TIME);  // Simulating time taken to handle a bag
        free(bagToHandle);  // Freeing the memory allocated for the handled bag
    }
    return NULL;
}

int main() {
    pthread_t arrivalThread, handlingThreads[NUM_PLATFORMS];
    sem_init(&empty, 0, MAX_BAGS);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutexQueue, NULL);

    // Create baggage arrival thread
    pthread_create(&arrivalThread, NULL, baggageArrival, NULL);

    // Create baggage handling threads
    for (int i = 0; i < NUM_PLATFORMS; i++) {
        pthread_create(&handlingThreads[i], NULL, baggageHandling, NULL);
    }

    // Wait for arrival thread to finish (it won't in this simulation)
    pthread_join(arrivalThread, NULL);

    // Wait for handling threads to finish (they won't in this simulation)
    for (int i = 0; i < NUM_PLATFORMS; i++) {
        pthread_join(handlingThreads[i], NULL);
    }

    // Clean up
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutexQueue);

    return 0;
}