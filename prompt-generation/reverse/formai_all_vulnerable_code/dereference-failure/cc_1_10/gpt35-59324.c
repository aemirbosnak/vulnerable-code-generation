//FormAI DATASET v1.0 Category: Queue Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

// Struct for a queue
typedef struct Queue {
    int front;
    int rear;
    int size;
    int* arr;
} Queue;

// Create a queue
Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->arr = (int*) malloc(MAX_QUEUE_SIZE * sizeof(int));
    return q;
}

// Check if the queue is full
int isFull(Queue* q) {
    return q->size == MAX_QUEUE_SIZE;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return q->size == 0;
}

// Add an element to the rear of the queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue overflow!\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->arr[q->rear] = value;
    q->size++;
    printf("Enqueued %d\n", value);
}

// Remove an element from the front of the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue underflow!\n");
        return -1;
    }
    int value = q->arr[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    q->size--;
    printf("Dequeued %d\n", value);
    return value;
}

int main() {
    Queue* q = createQueue();

    // Enqueue 3 elements
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    // Dequeue 2 elements
    dequeue(q);
    dequeue(q);

    // Enqueue 2 elements
    enqueue(q, 40);
    enqueue(q, 50);

    // Try to enqueue a 6th element
    enqueue(q, 60);

    // Dequeue all elements
    while (!isEmpty(q)) {
        dequeue(q);
    }

    return 0;
}