//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

// Define the queue data structure
typedef struct queue {
    int *items;
    int head, tail;
    int size;
} queue_t;

// Create a new queue
queue_t *queue_create(int size) {
    queue_t *queue = malloc(sizeof(queue_t));
    queue->items = malloc(sizeof(int) * size);
    queue->head = 0;
    queue->tail = 0;
    queue->size = size;
    return queue;
}

// Destroy a queue
void queue_destroy(queue_t *queue) {
    free(queue->items);
    free(queue);
}

// Check if the queue is empty
bool queue_is_empty(queue_t *queue) {
    return queue->head == queue->tail;
}

// Check if the queue is full
bool queue_is_full(queue_t *queue) {
    return (queue->tail + 1) % queue->size == queue->head;
}

// Add an item to the queue
void queue_enqueue(queue_t *queue, int item) {
    if (queue_is_full(queue)) {
        fprintf(stderr, "Queue is full!\n");
        return;
    }
    queue->items[queue->tail] = item;
    queue->tail = (queue->tail + 1) % queue->size;
}

// Remove an item from the queue
int queue_dequeue(queue_t *queue) {
    if (queue_is_empty(queue)) {
        fprintf(stderr, "Queue is empty!\n");
        return -1;
    }
    int item = queue->items[queue->head];
    queue->head = (queue->head + 1) % queue->size;
    return item;
}

// Print the queue
void queue_print(queue_t *queue) {
    if (queue_is_empty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for (int i = queue->head; i != queue->tail; i = (i + 1) % queue->size) {
        printf("%d ", queue->items[i]);
    }
    printf("\n");
}

// Thread function to produce items for the queue
void *producer_thread(void *args) {
    queue_t *queue = (queue_t *)args;
    int i = 0;
    while (true) {
        queue_enqueue(queue, i++);
        sleep(1);
    }
    return NULL;
}

// Thread function to consume items from the queue
void *consumer_thread(void *args) {
    queue_t *queue = (queue_t *)args;
    while (true) {
        int item = queue_dequeue(queue);
        if (item != -1) {
            printf("Consumed item: %d\n", item);
        }
        sleep(1);
    }
    return NULL;
}

int main() {
    // Create a queue
    queue_t *queue = queue_create(10);

    // Create producer and consumer threads
    pthread_t producer_tid, consumer_tid;
    pthread_create(&producer_tid, NULL, producer_thread, queue);
    pthread_create(&consumer_tid, NULL, consumer_thread, queue);

    // Join the threads
    pthread_join(producer_tid, NULL);
    pthread_join(consumer_tid, NULL);

    // Destroy the queue
    queue_destroy(queue);

    return 0;
}