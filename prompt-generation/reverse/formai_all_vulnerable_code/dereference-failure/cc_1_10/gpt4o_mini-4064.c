//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define MAX_BAGS 10
#define NUM_CARTS 3

typedef struct {
    int id; // Bag ID
    int destination; // Destination gate
} Bag;

typedef struct {
    Bag *bags[MAX_BAGS];
    int front, rear;
} Queue;

sem_t queue_sem;
Queue bagQueue;

void initializeQueue(Queue *q) {
    q->front = q->rear = 0;
}

int isFull(Queue *q) {
    return (q->rear + 1) % MAX_BAGS == q->front;
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

void enqueue(Queue *q, Bag *bag) {
    if (!isFull(q)) {
        q->bags[q->rear] = bag;
        q->rear = (q->rear + 1) % MAX_BAGS;
    } else {
        printf("Queue is full, cannot enqueue bag ID: %d\n", bag->id);
    }
}

Bag* dequeue(Queue *q) {
    if (!isEmpty(q)) {
        Bag *bag = q->bags[q->front];
        q->front = (q->front + 1) % MAX_BAGS;
        return bag;
    }
    printf("Queue is empty, nothing to dequeue.\n");
    return NULL;
}

void* checkIn(void *arg) {
    int id = *((int *)arg);
    for (int i = 0; i < MAX_BAGS; i++) {
        Bag *newBag = (Bag *)malloc(sizeof(Bag));
        newBag->id = id * MAX_BAGS + i;
        newBag->destination = rand() % 5; // random destination from 0 to 4
        sem_wait(&queue_sem);
        enqueue(&bagQueue, newBag);
        printf("Checked in Bag ID: %d to Destination: %d\n", newBag->id, newBag->destination);
        sem_post(&queue_sem);
        sleep(1);
    }
    return NULL;
}

void* sortAndLoad(void *arg) {
    int cart_id = *((int *)arg);
    while (1) {
        sem_wait(&queue_sem);
        Bag *bag = dequeue(&bagQueue);
        sem_post(&queue_sem);
        if (bag != NULL) {
            printf("Cart %d loading Bag ID: %d to Destination: %d\n", cart_id, bag->id, bag->destination);
            free(bag);
            sleep(2);
        } else {
            break;
        }
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    pthread_t checkInThreads[NUM_CARTS], loadThreads[NUM_CARTS];
    int cart_ids[NUM_CARTS];

    sem_init(&queue_sem, 0, 1);
    initializeQueue(&bagQueue);

    // Start check-in threads
    for (int i = 0; i < NUM_CARTS; i++) {
        cart_ids[i] = i + 1;
        pthread_create(&checkInThreads[i], NULL, checkIn, (void *)&cart_ids[i]);
    }
    // Start loading threads
    for (int i = 0; i < NUM_CARTS; i++) {
        pthread_create(&loadThreads[i], NULL, sortAndLoad, (void *)&cart_ids[i]);
    }

    // Wait for check-in to finish
    for (int i = 0; i < NUM_CARTS; i++) {
        pthread_join(checkInThreads[i], NULL);
    }

    // Finish off remaining bags in queue
    for (int i = 0; i < NUM_CARTS; i++) {
        sem_wait(&queue_sem);
        while (!isEmpty(&bagQueue)) {
            sem_post(&queue_sem);
            loadThreads[i] = pthread_self(); // just to use the thread id
            printf("Cart %d finished loading remaining bags.\n", cart_ids[i]);
            sem_wait(&queue_sem);
        }
        sem_post(&queue_sem);
        pthread_exit(NULL);
    }

    for (int i = 0; i < NUM_CARTS; i++) {
        pthread_join(loadThreads[i], NULL);
    }

    sem_destroy(&queue_sem);
    return 0;
}