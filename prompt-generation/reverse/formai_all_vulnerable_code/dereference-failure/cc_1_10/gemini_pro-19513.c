//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Define the queue structure
typedef struct queue {
    int *items;
    int front;
    int rear;
    int size;
} queue;

// Define the mutex and condition variables
pthread_mutex_t lock;
pthread_cond_t not_full;
pthread_cond_t not_empty;

// Create a new queue
queue *create_queue(int size) {
    queue *q = (queue *) malloc(sizeof(queue));
    q->items = (int *) malloc(sizeof(int) * size);
    q->front = 0;
    q->rear = 0;
    q->size = size;
    return q;
}

// Destroy the queue
void destroy_queue(queue *q) {
    free(q->items);
    free(q);
}

// Enqueue an item
void enqueue(queue *q, int item) {
    pthread_mutex_lock(&lock);
    while (q->rear == (q->front + q->size) % q->size) {
        pthread_cond_wait(&not_full, &lock);
    }
    q->items[q->rear] = item;
    q->rear = (q->rear + 1) % q->size;
    pthread_cond_signal(&not_empty);
    pthread_mutex_unlock(&lock);
}

// Dequeue an item
int dequeue(queue *q) {
    pthread_mutex_lock(&lock);
    while (q->front == q->rear) {
        pthread_cond_wait(&not_empty, &lock);
    }
    int item = q->items[q->front];
    q->front = (q->front + 1) % q->size;
    pthread_cond_signal(&not_full);
    pthread_mutex_unlock(&lock);
    return item;
}

// Producer thread
void *producer(void *arg) {
    queue *q = (queue *) arg;
    int i = 0;
    while (1) {
        sleep(1);
        enqueue(q, i);
        printf("Produced %d\n", i);
        i++;
    }
}

// Consumer thread
void *consumer(void *arg) {
    queue *q = (queue *) arg;
    while (1) {
        sleep(2);
        int item = dequeue(q);
        printf("Consumed %d\n", item);
    }
}

int main() {
    // Create the queue
    queue *q = create_queue(10);

    // Initialize the mutex and condition variables
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&not_full, NULL);
    pthread_cond_init(&not_empty, NULL);

    // Create the producer and consumer threads
    pthread_t producer_thread;
    pthread_t consumer_thread;
    pthread_create(&producer_thread, NULL, producer, q);
    pthread_create(&consumer_thread, NULL, consumer, q);

    // Join the threads
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // Destroy the queue
    destroy_queue(q);

    return 0;
}