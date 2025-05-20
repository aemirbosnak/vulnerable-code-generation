//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: Ada Lovelace
// Ada Lovelace's Analytical Engine Queue Implementation

#include <stdio.h>
#include <stdlib.h>

// Define the Queue structure
typedef struct Queue {
    int front, rear, size;
    int *elements;
} Queue;

// Create a new queue
Queue * createQueue(int size) {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->front = q->rear = -1;
    q->size = size;
    q->elements = (int *) malloc(q->size * sizeof(int));
    return q;
}

// Check if the queue is full
int isFull(Queue *q) {
    return q->rear == q->size - 1;
}

// Check if the queue is empty
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Enqueue an element
void enqueue(Queue *q, int element) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }

    if (q->front == -1) q->front = 0;

    q->rear++;
    q->elements[q->rear] = element;
}

// Dequeue an element
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }

    int element = q->elements[q->front];
    q->front++;

    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }

    return element;
}

// Print the queue
void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    int i;
    for (i = q->front; i <= q->rear; i++) {
        printf("%d ", q->elements[i]);
    }
    printf("\n");
}

// Main function
int main() {
    // Create a queue of size 5
    Queue *q = createQueue(5);

    // Enqueue some elements
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    // Print the queue
    printf("Queue: ");
    printQueue(q);

    // Dequeue some elements
    int element = dequeue(q);
    printf("Dequeued element: %d\n", element);

    element = dequeue(q);
    printf("Dequeued element: %d\n", element);

    element = dequeue(q);
    printf("Dequeued element: %d\n", element);

    // Print the queue
    printf("Queue: ");
    printQueue(q);

    // Enqueue some more elements
    enqueue(q, 6);
    enqueue(q, 7);

    // Print the queue
    printf("Queue: ");
    printQueue(q);

    return 0;
}