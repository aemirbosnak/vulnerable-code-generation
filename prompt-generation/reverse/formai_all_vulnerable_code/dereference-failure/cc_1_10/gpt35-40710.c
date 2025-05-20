//FormAI DATASET v1.0 Category: Queue ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

// Define the queue structure
struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

typedef struct Queue Queue;

// Create a new empty queue
Queue* newQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check whether the queue is full
int isFull(Queue* q) {
    if (q->rear == MAX_SIZE - 1) {
        return 1;
    }
    return 0;
}

// Check whether the queue is empty
int isEmpty(Queue* q) {
    if (q->front == -1 && q->rear == -1) {
        return 1;
    }
    return 0;
}

// Add an item to the queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
    } else {
        if (isEmpty(q)) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Remove an item from the queue
int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        item = -1;
    } else {
        item = q->items[q->front];
        if (q->front >= q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front++;
        }
    }
    return item;
}

int main() {
    // Create a new queue
    Queue* q = newQueue();

    // Add some items to the queue
    printf("Adding items to the queue:\n");
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);

    // Remove an item from the queue
    printf("Removing an item from the queue:\n");
    dequeue(q);

    // Add some more items to the queue
    printf("Adding more items to the queue:\n");
    enqueue(q, 4);
    enqueue(q, 5);

    // Remove all items from the queue
    printf("Removing all items from the queue:\n");
    while (!isEmpty(q)) {
        int item = dequeue(q);
        printf("%d\n", item);
    }

    // Free the memory used by the queue
    free(q);

    return 0;
}