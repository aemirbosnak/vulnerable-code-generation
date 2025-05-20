//FormAI DATASET v1.0 Category: Queue ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

// Structure representing a Queue
typedef struct Queue {
    int queueArray[MAX_QUEUE_SIZE];
    int front, rear;
    int size;
} Queue;

// Function to create a new queue
Queue* createQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = -1;
    q->size = 0;
    return q;
}

// Function to check if the queue is empty
int isEmpty(Queue *q) {
    return q->size == 0;
}

// Function to check if the queue is full
int isFull(Queue *q) {
    return q->size == MAX_QUEUE_SIZE;
}

// Function to add an element to the queue
void enqueue(Queue *q, int data) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
    q->queueArray[q->rear] = data;
    q->size++;
    if (q->front == -1)
        q->front = q->rear;
}

// Function to remove an element from the queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = q->queueArray[q->front];
    q->front = (q->front+1) % MAX_QUEUE_SIZE;
    q->size--;
    if (q->size == 0)
        q->front = q->rear = -1;
    return data;
}

// Function to print the queue elements
void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->queueArray[i]);
    }
    printf("\n");
}

int main() {
    Queue *q = createQueue();

    // Inserting 5 elements
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    // Printing queue elements
    printQueue(q);

    // Removing 2 elements
    printf("Removed element: %d\n", dequeue(q));
    printf("Removed element: %d\n", dequeue(q));

    // Printing queue elements
    printQueue(q);

    // Inserting 3 elements
    enqueue(q, 60);
    enqueue(q, 70);
    enqueue(q, 80);

    // Printing queue elements
    printQueue(q);

    return 0;
}