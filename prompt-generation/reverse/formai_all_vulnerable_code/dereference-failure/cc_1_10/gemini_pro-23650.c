//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the queue structure
typedef struct Queue {
    int *data;
    int head;
    int tail;
    int size;
} Queue;

// Create a new queue
Queue *queue_create(int size) {
    Queue *queue = malloc(sizeof(Queue));
    queue->data = malloc(sizeof(int) * size);
    queue->head = 0;
    queue->tail = 0;
    queue->size = size;
    return queue;
}

// Destroy a queue
void queue_destroy(Queue *queue) {
    free(queue->data);
    free(queue);
}

// Enqueue an item to the queue
void queue_enqueue(Queue *queue, int item) {
    if ((queue->tail + 1) % queue->size == queue->head) {
        printf("Queue is full!\n");
        return;
    }

    queue->data[queue->tail] = item;
    queue->tail = (queue->tail + 1) % queue->size;
}

// Dequeue an item from the queue
int queue_dequeue(Queue *queue) {
    if (queue->head == queue->tail) {
        printf("Queue is empty!\n");
        return -1;
    }

    int item = queue->data[queue->head];
    queue->head = (queue->head + 1) % queue->size;
    return item;
}

// Get the size of the queue
int queue_size(Queue *queue) {
    return (queue->tail - queue->head + queue->size) % queue->size;
}

// Print the queue
void queue_print(Queue *queue) {
    printf("Queue: [");
    for (int i = queue->head; i != queue->tail; i = (i + 1) % queue->size) {
        printf("%d, ", queue->data[i]);
    }
    printf("]\n");
}

// Producer thread function
void *producer(void *arg) {
    Queue *queue = (Queue *)arg;

    // Produce 100 random numbers and enqueue them to the queue
    for (int i = 0; i < 100; i++) {
        int item = rand() % 100;
        queue_enqueue(queue, item);
        printf("Producer enqueued: %d\n", item);
    }

    return NULL;
}

// Consumer thread function
void *consumer(void *arg) {
    Queue *queue = (Queue *)arg;

    // Consume 100 items from the queue
    for (int i = 0; i < 100; i++) {
        int item = queue_dequeue(queue);
        printf("Consumer dequeued: %d\n", item);
    }

    return NULL;
}

int main() {
    // Create a queue
    Queue *queue = queue_create(10);

    // Create producer and consumer threads
    pthread_t producer_thread, consumer_thread;

    // Create the producer thread
    pthread_create(&producer_thread, NULL, producer, queue);

    // Create the consumer thread
    pthread_create(&consumer_thread, NULL, consumer, queue);

    // Join the producer thread
    pthread_join(producer_thread, NULL);

    // Join the consumer thread
    pthread_join(consumer_thread, NULL);

    // Destroy the queue
    queue_destroy(queue);

    return 0;
}