//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: unmistakable
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int *elems;
    int capacity;
    int count;
    int front;
    int rear;
} Queue;

// Create a new queue
Queue* create_queue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->elems = (int *)malloc(sizeof(int) * capacity);
    queue->capacity = capacity;
    queue->count = 0;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

// Destroy a queue
void destroy_queue(Queue *queue) {
    free(queue->elems);
    free(queue);
}

// Check if a queue is empty
bool is_empty(Queue *queue) {
    return queue->count == 0;
}

// Check if a queue is full
bool is_full(Queue *queue) {
    return queue->count == queue->capacity;
}

// Enqueue an element to a queue
void enqueue(Queue *queue, int elem) {
    if (is_full(queue)) {
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->elems[queue->rear] = elem;
    queue->count++;
}

// Dequeue an element from a queue
int dequeue(Queue *queue) {
    if (is_empty(queue)) {
        return -1;
    }
    int elem = queue->elems[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->count--;
    return elem;
}

// Get the front element of a queue
int peek(Queue *queue) {
    if (is_empty(queue)) {
        return -1;
    }
    return queue->elems[queue->front];
}

int main() {
    // Create a queue
    int capacity = 5;
    Queue *queue = create_queue(capacity);

    // Enqueue some elements
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Check if the queue is full
    if (is_full(queue)) {
        printf("Queue is full\n");
    }

    // Dequeue some elements
    printf("Dequeue: %d\n", dequeue(queue));
    printf("Dequeue: %d\n", dequeue(queue));
    printf("Dequeue: %d\n", dequeue(queue));

    // Check if the queue is empty
    if (is_empty(queue)) {
        printf("Queue is empty\n");
    }

    // Get the front element
    printf("Front element: %d\n", peek(queue));

    // Destroy the queue
    destroy_queue(queue);

    return 0;
}