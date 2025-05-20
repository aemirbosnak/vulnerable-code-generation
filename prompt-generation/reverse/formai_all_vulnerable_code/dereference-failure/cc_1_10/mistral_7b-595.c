//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

// Define queue structure
typedef struct {
    int front;
    int rear;
    int size;
    int *queue;
} Queue;

// Function to initialize queue
Queue* initQueue(int size) {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->front = q->rear = -1;
    q->size = size;
    q->queue = (int *) calloc(q->size, sizeof(int));
    return q;
}

// Function to check if queue is full
int isFull(Queue *q) {
    return (q->rear + 1) % q->size == q->front;
}

// Function to check if queue is empty
int isEmpty(Queue *q) {
    return q->front == q->rear;
}

// Function to add an element to the queue
void enqueue(Queue *q, int data) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    q->queue[++q->rear] = data;
}

// Function to remove an element from the queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->queue[++q->front];
}

// Function to print queue contents
void printQueue(Queue *q) {
    int i = q->front + 1;
    printf("Queue Contents: ");
    while (i != q->rear) {
        printf("%d ", q->queue[i]);
        i = (i + 1) % q->size;
    }
    printf("%d\n", q->queue[i]);
}

// Main function
int main() {
    int i;
    Queue *q = initQueue(5);

    // Enqueue elements
    for (i = 0; i < 6; i++) {
        enqueue(q, i);
        printQueue(q);
    }

    // Dequeue elements
    for (i = 0; i < 5; i++) {
        dequeue(q);
        printQueue(q);
    }

    // Free memory
    free(q->queue);
    free(q);

    return 0;
}