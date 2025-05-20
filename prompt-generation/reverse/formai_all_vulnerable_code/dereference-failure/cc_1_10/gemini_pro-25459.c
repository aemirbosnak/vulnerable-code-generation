//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
struct Queue {
    int front;
    int rear;
    int size;
    int *array;
};

// Create a new queue
struct Queue* createQueue(int size) {
    struct Queue *q = malloc(sizeof(struct Queue));
    q->front = q->rear = -1;
    q->size = size;
    q->array = malloc(q->size * sizeof(int));
    return q;
}

// Check if the queue is full
int isFull(struct Queue *q) {
    return (q->rear == q->size - 1);
}

// Check if the queue is empty
int isEmpty(struct Queue *q) {
    return (q->front == -1);
}

// Add an element to the queue
void enqueue(struct Queue *q, int data) {
    if (isFull(q)) {
        printf("Queue is full!\n");
    } else {
        q->rear++;
        q->array[q->rear] = data;
        if (q->front == -1) {
            q->front = 0;
        }
    }
}

// Remove an element from the queue
int dequeue(struct Queue *q) {
    int data;
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        data = q->array[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
        return data;
    }
}

// Print the queue
void printQueue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->array[i]);
        }
        printf("\n");
    }
}

// Destroy the queue
void destroyQueue(struct Queue *q) {
    if (q) {
        free(q->array);
        free(q);
    }
}

// Test the queue
int main() {
    // Create a queue of size 5
    struct Queue *q = createQueue(5);

    // Enqueue some elements
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    // Print the queue
    printQueue(q);

    // Dequeue some elements
    dequeue(q);
    dequeue(q);

    // Print the queue
    printQueue(q);

    // Destroy the queue
    destroyQueue(q);

    return 0;
}