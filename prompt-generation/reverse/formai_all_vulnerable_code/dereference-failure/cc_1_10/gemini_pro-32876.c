//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
struct Queue {
    int front, rear;
    int capacity;
    int *array;
};

// Create a new queue
struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->front = queue->rear = -1;
    queue->capacity = capacity;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

// Check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->rear == queue->capacity - 1);
}

// Check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

// Add an element to the queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->array[queue->rear] = item;
}

// Remove an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }
    return item;
}

// Print the queue
void printQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

// Driver program to test the queue
int main() {
    struct Queue* queue = createQueue(5);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    printQueue(queue);
    dequeue(queue);
    printQueue(queue);
    dequeue(queue);
    printQueue(queue);
    dequeue(queue);
    printQueue(queue);
    dequeue(queue);
    printQueue(queue);
    dequeue(queue);
    printQueue(queue);
    return 0;
}