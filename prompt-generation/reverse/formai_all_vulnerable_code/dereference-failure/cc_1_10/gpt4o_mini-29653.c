//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_BAGGAGE_CLAIMS 3
#define NUM_BAGGAGE_HANDLERS 2
#define MAX_BAGS 10

typedef struct {
    int id;
    int weight;
} Baggage;

Baggage *baggageQueue[MAX_BAGS];
int front = 0, rear = 0;

sem_t empty;
sem_t full;
pthread_mutex_t queueLock;

void *baggageHandler(void *arg) {
    int handlerId = *((int *)arg);

    while (1) {
        sem_wait(&full);
        pthread_mutex_lock(&queueLock);

        Baggage *bag = baggageQueue[front];
        front = (front + 1) % MAX_BAGS;

        pthread_mutex_unlock(&queueLock);
        sem_post(&empty);

        printf("Baggage Handler %d is processing baggage %d with weight %dkg\n", 
                handlerId, bag->id, bag->weight);
        free(bag);
        sleep(1); // Simulate baggage processing time
    }
    return NULL;
}

void *baggageProducer(void *arg) {
    while (1) {
        Baggage *newBag = (Baggage *)malloc(sizeof(Baggage));
        if (!newBag) {
            perror("Failed to allocate memory for new baggage");
            exit(EXIT_FAILURE);
        }
        newBag->id = rand() % 1000; // Unique ID for baggage
        newBag->weight = (rand() % 20) + 1; // Random weight between 1-20kg

        sem_wait(&empty);
        pthread_mutex_lock(&queueLock);

        baggageQueue[rear] = newBag;
        rear = (rear + 1) % MAX_BAGS;

        pthread_mutex_unlock(&queueLock);
        sem_post(&full);

        printf("Generated baggage %d with weight %dkg\n", newBag->id, newBag->weight);
        sleep(rand() % 3 + 1); // Sleep to simulate time taken between baggage arrivals
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    pthread_t handlers[NUM_BAGGAGE_HANDLERS];
    pthread_t producer;

    sem_init(&empty, 0, MAX_BAGS);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&queueLock, NULL);

    for (int i = 0; i < NUM_BAGGAGE_HANDLERS; i++) {
        int *handlerId = malloc(sizeof(int));
        *handlerId = i + 1;
        pthread_create(&handlers[i], NULL, baggageHandler, (void *)handlerId);
        free(handlerId);
    }

    pthread_create(&producer, NULL, baggageProducer, NULL);

    pthread_join(producer, NULL);
    for (int i = 0; i < NUM_BAGGAGE_HANDLERS; i++) {
        pthread_cancel(handlers[i]);
        pthread_join(handlers[i], NULL);
    }

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&queueLock);

    return 0;
}