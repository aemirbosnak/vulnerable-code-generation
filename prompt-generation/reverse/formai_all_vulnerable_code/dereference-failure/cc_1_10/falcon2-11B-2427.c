//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for the queue
typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
} Queue;

// Initialize the queue
Queue *initQueue(int size) {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->arr = (int *) malloc(size * sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->size = size;
    return q;
}

// Check if the queue is empty
int isEmpty(Queue *q) {
    return (q->front == -1);
}

// Enqueue an element
void enqueue(Queue *q, int data) {
    if (q->rear == q->size - 1) {
        printf("Queue is full.\n");
        return;
    }

    q->rear++;
    q->arr[q->rear] = data;
}

// Dequeue an element
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }

    int data = q->arr[q->front];
    q->front++;
    return data;
}

// Display the queue
void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue:\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    Queue *q = initQueue(10);

    enqueue(q, 5);
    enqueue(q, 10);
    enqueue(q, 15);
    enqueue(q, 20);

    displayQueue(q);

    printf("Dequeued element: %d\n", dequeue(q));

    displayQueue(q);

    return 0;
}