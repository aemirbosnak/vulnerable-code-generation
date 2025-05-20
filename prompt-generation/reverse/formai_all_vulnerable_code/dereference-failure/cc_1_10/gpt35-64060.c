//FormAI DATASET v1.0 Category: Queue Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Custom queue struct
typedef struct {
    int* array;
    int head;
    int tail;
    int capacity;
} queue;

// Initialize a new queue with a given capacity
queue* initializeQueue(int capacity) {
    queue* q = (queue*) malloc(sizeof(queue));

    q->array = (int*) malloc(sizeof(int) * capacity);
    q->head = 0;
    q->tail = 0;
    q->capacity = capacity;

    return q;
}

// Deallocate a queue from memory
void deleteQueue(queue* q) {
    free(q->array);
    free(q);
}

// Get the current size of the queue
int size(queue* q) {
    return (q->tail - q->head + q->capacity) % q->capacity;
}

// Enqueue a new value onto the tail of the queue
void enqueue(queue* q, int value) {
    if (size(q) == q->capacity - 1) {
        printf("Error: queue is full\n");
        return;
    }

    q->array[q->tail] = value;
    q->tail = (q->tail + 1) % q->capacity;
}

// Dequeue the value at the head of the queue
int dequeue(queue* q) {
    if (size(q) == 0) {
        printf("Error: queue is empty\n");
        return -1;
    }

    int value = q->array[q->head];
    q->head = (q->head + 1) % q->capacity;

    return value;
}

// Main function to test the queue implementation
int main() {
    queue* q = initializeQueue(10);

    // Enqueue some values onto the queue
    enqueue(q, 5);
    enqueue(q, 10);
    enqueue(q, 15);
    enqueue(q, 20);

    // Dequeue some of the values from the queue
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));

    // Enqueue some more values onto the queue
    enqueue(q, 25);
    enqueue(q, 30);

    // Dequeue all remaining values from the queue
    while (size(q) > 0) {
        printf("%d\n", dequeue(q));
    }

    deleteQueue(q);

    return 0;
}