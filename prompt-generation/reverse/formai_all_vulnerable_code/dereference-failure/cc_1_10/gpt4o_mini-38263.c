//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_BAGGAGE 10
#define CONVEYOR_BELT_LENGTH 5

typedef struct {
    int id;
    char owner[50];
} Baggage;

typedef struct {
    Baggage *baggages[MAX_BAGGAGE];
    int front;
    int rear;
} BaggageQueue;

BaggageQueue queue;
pthread_mutex_t lock;

void initQueue(BaggageQueue *q) {
    q->front = 0;
    q->rear = 0;
}

int isFull(BaggageQueue *q) {
    return (q->rear + 1) % MAX_BAGGAGE == q->front;
}

int isEmpty(BaggageQueue *q) {
    return q->front == q->rear;
}

void enqueue(BaggageQueue *q, Baggage *baggage) {
    if (!isFull(q)) {
        q->baggages[q->rear] = baggage;
        q->rear = (q->rear + 1) % MAX_BAGGAGE;
    } else {
        printf("Queue is full, cannot add baggage ID %d!\n", baggage->id);
    }
}

Baggage* dequeue(BaggageQueue *q) {
    if (!isEmpty(q)) {
        Baggage *baggage = q->baggages[q->front];
        q->front = (q->front + 1) % MAX_BAGGAGE;
        return baggage;
    }
    return NULL; // No baggage to retrieve
}

void* baggageCheckIn(void *arg) {
    for (int i = 0; i < 10; i++) {
        pthread_mutex_lock(&lock);
        
        Baggage *baggage = malloc(sizeof(Baggage));
        baggage->id = i + 1;
        sprintf(baggage->owner, "Owner_%d", i + 1);

        enqueue(&queue, baggage);
        printf("Baggage ID %d checked in by %s.\n", baggage->id, baggage->owner);
        
        pthread_mutex_unlock(&lock);
        sleep(1); // Simulate time delay for checking in
    }
    return NULL;
}

void* baggageTransport(void *arg) {
    for (int i = 0; i < 10; i++) {
        pthread_mutex_lock(&lock);
        
        Baggage *baggage = dequeue(&queue);
        if (baggage != NULL) {
            printf("Transporting Baggage ID %d to the destination...\n", baggage->id);
            sleep(2); // Simulate time taken during transport
            printf("Baggage ID %d has reached the destination!\n", baggage->id);
            free(baggage); // Free memory
        } else {
            printf("No baggage to transport.\n");
        }
        
        pthread_mutex_unlock(&lock);
        sleep(1); // Simulate waiting time
    }
    return NULL;
}

int main() {
    pthread_t checkInThread, transportThread;

    printf("=== Airport Baggage Handling Simulation ===\n");
    pthread_mutex_init(&lock, NULL);
    initQueue(&queue);

    pthread_create(&checkInThread, NULL, baggageCheckIn, NULL);
    pthread_create(&transportThread, NULL, baggageTransport, NULL);
    
    pthread_join(checkInThread, NULL);
    pthread_join(transportThread, NULL);
    
    pthread_mutex_destroy(&lock);
    printf("Baggage handling simulation finished.\n");
    
    return 0;
}