//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Queue structure
typedef struct Queue {
    int front, rear, size;
    int *arr;
} Queue;

// Create a queue
Queue* createQueue(int size) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = -1;
    q->size = size;
    q->arr = (int *)malloc(q->size * sizeof(int));
    return q;
}

// Check if the queue is empty
int isEmpty(Queue *q) {
    return (q->front == -1);
}

// Check if the queue is full
int isFull(Queue *q) {
    return (q->rear == q->size - 1);
}

// Add an element to the queue
void enqueue(Queue *q, int data) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }

    // Insert element at the rear
    q->rear++;
    q->arr[q->rear] = data;

    // If this is the first element, update the front
    if (q->front == -1) {
        q->front = q->rear;
    }
}

// Remove an element from the queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }

    // Store the front element
    int data = q->arr[q->front];

    // Move the front one position ahead
    q->front++;

    // If the front has reached the end, update it
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }

    return data;
}

// Print the queue
void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    // Create a queue
    Queue *q = createQueue(5);

    // Enqueue elements
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    // Print the queue
    printQueue(q);

    // Dequeue elements
    printf("Removed %d\n", dequeue(q));
    printf("Removed %d\n", dequeue(q));
    printf("Removed %d\n", dequeue(q));

    // Print the queue
    printQueue(q);

    // Enqueue more elements
    enqueue(q, 60);
    enqueue(q, 70);

    // Print the queue
    printQueue(q);

    // Dequeue remaining elements
    while (!isEmpty(q)) {
        printf("Removed %d\n", dequeue(q));
    }

    // Print the queue
    printQueue(q);

    return 0;
}