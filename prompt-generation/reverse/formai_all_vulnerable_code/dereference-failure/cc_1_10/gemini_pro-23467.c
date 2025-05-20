//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
typedef struct Queue {
    int front, rear, size;
    int *arr;
} Queue;

// Create a new queue
Queue *createQueue(int size) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = -1;
    q->size = size;
    q->arr = (int *)malloc(q->size * sizeof(int));
    return q;
}

// Check if the queue is empty
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Check if the queue is full
int isFull(Queue *q) {
    return (q->rear + 1) % q->size == q->front;
}

// Enqueue an element
void enQueue(Queue *q, int data) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = data;
    }
}

// Dequeue an element
int deQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    else {
        int data = q->arr[q->front];
        if (q->front == q->rear)
            q->front = q->rear = -1;
        else
            q->front = (q->front + 1) % q->size;
        return data;
    }
}

// Print the queue
void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    }
    else {
        printf("Queue: ");
        int i = q->front;
        while (i != q->rear) {
            printf("%d ", q->arr[i]);
            i = (i + 1) % q->size;
        }
        printf("%d\n", q->arr[i]);
    }
}

// Destroy the queue
void destroyQueue(Queue *q) {
    if (q) {
        free(q->arr);
        free(q);
    }
}

// Driver code
int main() {
    // Create a queue of size 5
    Queue *q = createQueue(5);

    // Enqueue some elements
    enQueue(q, 10);
    enQueue(q, 20);
    enQueue(q, 30);
    enQueue(q, 40);
    enQueue(q, 50);

    // Print the queue
    printQueue(q);

    // Dequeue some elements
    deQueue(q);
    deQueue(q);

    // Print the queue
    printQueue(q);

    // Destroy the queue
    destroyQueue(q);

    return 0;
}