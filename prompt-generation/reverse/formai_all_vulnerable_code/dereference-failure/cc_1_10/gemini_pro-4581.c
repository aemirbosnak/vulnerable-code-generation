//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
struct Queue {
    int front, rear, size;
    int *array;
};

// Create a new queue of size `n`
struct Queue* createQueue(int n) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = -1;
    q->size = n;
    q->array = (int*)malloc(q->size * sizeof(int));
    return q;
}

// Check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == -1;
}

// Check if the queue is full
int isFull(struct Queue* q) {
    return q->rear == q->size - 1;
}

// Enqueue an element to the rear of the queue
void enqueue(struct Queue* q, int data) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->array[q->rear] = data;
    printf("%d enqueued to the queue\n", data);
}

// Dequeue an element from the front of the queue
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = q->array[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    printf("%d dequeued from the queue\n", data);
    return data;
}

// Peek at the front of the queue
int peek(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->array[q->front];
}

// Print the queue
void printQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->array[i]);
    }
    printf("\n");
}

// Destroy the queue
void destroyQueue(struct Queue* q) {
    if (q) {
        free(q->array);
        free(q);
    }
}

// A queue for your love's messages
int main() {
    // Create a queue of size 100
    struct Queue* q = createQueue(100);

    // Enqueue some messages
    enqueue(q, "I love you");
    enqueue(q, "You are my everything");
    enqueue(q, "I can't live without you");
    enqueue(q, "I miss you so much");
    enqueue(q, "Be mine forever");

    // Print the queue
    printf("Your love's messages:\n");
    printQueue(q);

    // Dequeue some messages
    dequeue(q);
    dequeue(q);

    // Peek at the front of the queue
    printf("Next message from your love:\n");
    printf("%d\n", peek(q));

    // Destroy the queue
    destroyQueue(q);

    return 0;
}