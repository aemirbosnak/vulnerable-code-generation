//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definition for the queue
typedef struct {
    int head;
    int tail;
    int size;
    int capacity;
    int *queue;
} queue_t;

// Function prototypes
void initialize_queue(queue_t *q, int size);
int is_full(queue_t *q);
int is_empty(queue_t *q);
void enqueue(queue_t *q, int data);
int dequeue(queue_t *q);

// Initialize the queue
void initialize_queue(queue_t *q, int size) {
    q->size = size;
    q->capacity = size + 1; // +1 for the head index
    q->queue = (int *)malloc(q->capacity * sizeof(int));
    q->head = 0;
    q->tail = -1;
}

// Check if the queue is full
int is_full(queue_t *q) {
    return ((q->tail + 1) % q->capacity == q->head);
}

// Check if the queue is empty
int is_empty(queue_t *q) {
    return (q->head == q->tail);
}

// Enqueue an integer to the queue
void enqueue(queue_t *q, int data) {
    if (is_full(q)) {
        printf("Queue is full! Data not added.\n");
        return;
    }
    q->queue[++(q->tail) % q->capacity] = data;
}

// Dequeue an integer from the queue
int dequeue(queue_t *q) {
    if (is_empty(q)) {
        printf("Queue is empty! Data not dequeued.\n");
        return -1;
    }
    int data = q->queue[q->head];
    q->head = (q->head + 1) % q->capacity;
    return data;
}

// Main function to test the queue implementation
int main() {
    queue_t my_queue;
    initialize_queue(&my_queue, 10);

    // Test enqueueing
    enqueue(&my_queue, 5);
    enqueue(&my_queue, 10);
    enqueue(&my_queue, 15);

    // Test dequeueing
    printf("Dequeued: %d\n", dequeue(&my_queue));
    printf("Dequeued: %d\n", dequeue(&my_queue));

    // Test enqueueing when the queue is full
    enqueue(&my_queue, 20);

    return 0;
}