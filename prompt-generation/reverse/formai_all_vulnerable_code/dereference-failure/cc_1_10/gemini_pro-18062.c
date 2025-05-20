//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
typedef struct Queue {
    int front, rear, size;
    int *arr;
} Queue;

// Create a new queue
Queue* createQueue(int size) {
    Queue *q = (Queue*) malloc(sizeof(Queue));
    q->front = q->rear = -1;
    q->size = size;
    q->arr = (int*) malloc(q->size * sizeof(int));
    return q;
}

// Check if the queue is full
int isFull(Queue *q) {
    return (q->rear == q->size - 1);
}

// Check if the queue is empty
int isEmpty(Queue *q) {
    return (q->front == -1);
}

// Add an element to the queue
void enqueue(Queue *q, int data) {
    if (isFull(q))
        printf("Queue is full!\n");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->arr[q->rear] = data;
    }
}

// Remove an element from the queue
int dequeue(Queue *q) {
    int data;
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        data = q->arr[q->front];
        q->front++;
        if (q->front > q->rear)
            q->front = q->rear = -1;
    }
    return data;
}

// Peek at the front element of the queue
int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        return q->arr[q->front];
    }
}

// Print the queue
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

// Destroy the queue
void destroyQueue(Queue *q) {
    if (q != NULL) {
        free(q->arr);
        free(q);
    }
}

// Driver code
int main() {
    Queue *q = createQueue(5);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    display(q);
    printf("Dequeued element: %d\n", dequeue(q));
    printf("Dequeued element: %d\n", dequeue(q));
    printf("Dequeued element: %d\n", dequeue(q));
    display(q);
    enqueue(q, 60);
    enqueue(q, 70);
    display(q);
    destroyQueue(q);
    return 0;
}