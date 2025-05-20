//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_BAGS 10
#define NUM_CONVEYORS 3

typedef struct {
    int id;
} Bag;

typedef struct {
    Bag *bags[MAX_BAGS];
    int front;
    int rear;
    sem_t sem_empty;
    sem_t sem_full;
    pthread_mutex_t lock;
} BaggageQueue;

BaggageQueue queue;

void initQueue() {
    queue.front = queue.rear = 0;
    sem_init(&queue.sem_empty, 0, MAX_BAGS);
    sem_init(&queue.sem_full, 0, 0);
    pthread_mutex_init(&queue.lock, NULL);
}

void enqueue(Bag *bag) {
    sem_wait(&queue.sem_empty);
    pthread_mutex_lock(&queue.lock);
    queue.bags[queue.rear] = bag;
    queue.rear = (queue.rear + 1) % MAX_BAGS;
    pthread_mutex_unlock(&queue.lock);
    sem_post(&queue.sem_full);
}

Bag* dequeue() {
    sem_wait(&queue.sem_full);
    pthread_mutex_lock(&queue.lock);
    Bag *bag = queue.bags[queue.front];
    queue.front = (queue.front + 1) % MAX_BAGS;
    pthread_mutex_unlock(&queue.lock);
    sem_post(&queue.sem_empty);
    return bag;
}

void* conveyorBelt(void* arg) {
    int conveyorID = *((int*) arg);
    while (1) {
        sleep(rand() % 3 + 1); // Simulate the time taken to grab a bag
        Bag *bag = malloc(sizeof(Bag));
        bag->id = rand() % 1000;
        printf("Conveyor %d: Bag %d added to queue\n", conveyorID, bag->id);
        enqueue(bag);
    }
    return NULL;
}

void* baggageHandler(void* arg) {
    while (1) {
        Bag *bag = dequeue();
        printf("Baggage Handler: Processing Bag %d\n", bag->id);
        sleep(rand() % 3 + 1); // Simulate processing time
        printf("Baggage Handler: Bag %d processed\n", bag->id);
        free(bag);
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    initQueue();
    
    pthread_t conveyors[NUM_CONVEYORS];
    pthread_t handler;

    for (int i = 0; i < NUM_CONVEYORS; i++) {
        int *conveyorID = malloc(sizeof(int));
        *conveyorID = i + 1;
        pthread_create(&conveyors[i], NULL, conveyorBelt, conveyorID);
    }
    
    pthread_create(&handler, NULL, baggageHandler, NULL);

    for (int i = 0; i < NUM_CONVEYORS; i++) {
        pthread_join(conveyors[i], NULL);
    }

    pthread_join(handler, NULL);
    
    pthread_mutex_destroy(&queue.lock);
    sem_destroy(&queue.sem_empty);
    sem_destroy(&queue.sem_full);
    
    return 0;
}