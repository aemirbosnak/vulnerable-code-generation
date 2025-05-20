//FormAI DATASET v1.0 Category: Queue Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10 // Maximum size of the queue

typedef struct {
    int* data; // Pointer to int array storing data
    int front; // Position of front element
    int rear; // Position of rear element
    int size; // Current size of the queue
} Queue;

// Function to create a new queue
Queue* createQueue() {
    Queue* q = malloc(sizeof(Queue));
    q->data = malloc(MAX_SIZE * sizeof(int));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    return q;
}

// Function to check if queue is full
int isFull(Queue* q) {
    return q->size == MAX_SIZE;
}

// Function to check if queue is empty
int isEmpty(Queue* q) {
    return q->size == 0;
}

// Function to add an element to the rear of the queue
void enqueue(Queue* q, int element) {
    if (isFull(q)) {
        printf("Queue is full!\n");
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
        q->data[q->rear] = element;
        q->size++;
    }
}

// Function to remove the front element from the queue
void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
        q->size--;
    }
}

// Function to print the queue
void printQueue(Queue* q) {
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i % MAX_SIZE]);
    }
    printf("\n");
}

int main() {
    Queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    printQueue(q);

    dequeue(q);
    dequeue(q);

    printQueue(q);

    enqueue(q, 50);
    enqueue(q, 60);

    printQueue(q);

    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    printQueue(q);

    dequeue(q);

    return 0;
}