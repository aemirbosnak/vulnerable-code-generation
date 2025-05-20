//FormAI DATASET v1.0 Category: Queue Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

// C Queue Struct Definition
typedef struct queue {
    int items[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

// Function to create a queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is full
int isFull(Queue* queue) {
    if(queue->rear == MAX_QUEUE_SIZE - 1) {
        return 1;
    }
    return 0;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    if(queue->front == -1) {
        return 1;
    }
    return 0;
}

// Function to add an item to the queue
void enqueue(Queue* queue, int value) {
    if(isFull(queue)) {
        printf("Queue is full\n");
    }
    else {
        if(queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = value;
        printf("Inserted %d into the queue\n", value);
    }
}

// Function to remove an item from the queue
int dequeue(Queue* queue) {
    int item;
    if(isEmpty(queue)) {
        printf("Queue is empty\n");
        item = -1;
    }
    else {
        item = queue->items[queue->front];
        queue->front++;
        if(queue->front > queue->rear) {
            printf("Resetting queue\n");
            queue->front = queue->rear = -1;
        }
    }
    return item;
}

void main() {
    Queue* queue = createQueue();

    enqueue(queue, 10); // Inserting 10
    enqueue(queue, 20); // Inserting 20
    enqueue(queue, 30); // Inserting 30
    enqueue(queue, 40); // Inserting 40

    printf("Dequeue operation: %d\n", dequeue(queue)); // Removing an item
    printf("Dequeue operation: %d\n", dequeue(queue)); // Removing an item

    enqueue(queue, 50); // Inserting 50

    printf("Dequeue operation: %d\n", dequeue(queue)); // Removing an item
    printf("Dequeue operation: %d\n", dequeue(queue)); // Removing an item
    printf("Dequeue operation: %d\n", dequeue(queue)); // Removing the last item
}