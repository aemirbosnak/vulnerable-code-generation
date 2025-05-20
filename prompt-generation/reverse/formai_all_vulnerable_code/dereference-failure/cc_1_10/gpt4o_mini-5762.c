//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define NUM_BAGGAGE_CARRIERS 3
#define NUM_BAGGAGE_ITEMS 10
#define MAX_QUEUE_LENGTH 5

typedef struct {
    int id;
    int weight;
} Baggage;

typedef struct {
    Baggage *items[MAX_QUEUE_LENGTH];
    int front, rear;
    sem_t empty, full, mutex;
} BaggageQueue;

BaggageQueue queue;

void initQueue() {
    queue.front = queue.rear = 0;
    sem_init(&queue.empty, 0, MAX_QUEUE_LENGTH);
    sem_init(&queue.full, 0, 0);
    sem_init(&queue.mutex, 0, 1);
}

void enqueue(Baggage *baggage) {
    sem_wait(&queue.empty);
    sem_wait(&queue.mutex);

    queue.items[queue.rear] = baggage;
    queue.rear = (queue.rear + 1) % MAX_QUEUE_LENGTH;

    sem_post(&queue.mutex);
    sem_post(&queue.full);
}

Baggage* dequeue() {
    sem_wait(&queue.full);
    sem_wait(&queue.mutex);

    Baggage *baggage = queue.items[queue.front];
    queue.front = (queue.front + 1) % MAX_QUEUE_LENGTH;

    sem_post(&queue.mutex);
    sem_post(&queue.empty);

    return baggage;
}

void* baggageCarrier(void* arg) {
    int carrier_id = *(int*)arg;
    while (1) {
        Baggage *baggage = dequeue();
        printf("Carrier %d is handling baggage %d with weight %d kg\n",
               carrier_id, baggage->id, baggage->weight);
        sleep(1); // Simulate time taken to handle baggage
        free(baggage);
    }
    return NULL;
}

int main() {
    pthread_t carriers[NUM_BAGGAGE_CARRIERS];
    initQueue();
    
    // Initialize baggage carriers
    for (int i = 0; i < NUM_BAGGAGE_CARRIERS; i++) {
        int *id = malloc(sizeof(int));
        *id = i + 1;
        pthread_create(&carriers[i], NULL, baggageCarrier, id);
    }

    // Simulate adding baggage
    for (int i = 0; i < NUM_BAGGAGE_ITEMS; i++) {
        Baggage *baggage = malloc(sizeof(Baggage));
        baggage->id = i + 1;
        baggage->weight = rand() % 20 + 1; // Random weight between 1 and 20kg
        enqueue(baggage);
        printf("Added baggage %d with weight %d kg\n", baggage->id, baggage->weight);
        sleep(2); // Simulate time taken to add baggage
    }

    // Clean up the baggage carriers
    for (int i = 0; i < NUM_BAGGAGE_CARRIERS; i++) {
        pthread_cancel(carriers[i]);
        pthread_join(carriers[i], NULL);
    }

    sem_destroy(&queue.empty);
    sem_destroy(&queue.full);
    sem_destroy(&queue.mutex);

    return 0;
}