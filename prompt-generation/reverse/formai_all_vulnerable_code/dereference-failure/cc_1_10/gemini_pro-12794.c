//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
typedef struct Queue {
    int *items;
    int front;
    int rear;
    int capacity;
} Queue;

// Create a new queue
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->items = (int*)malloc(sizeof(int) * capacity);
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = capacity;
    return queue;
}

// Check if the queue is full
int isFull(Queue* queue) {
    return queue->rear == queue->capacity - 1;
}

// Check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Add an item to the rear of the queue
void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear++;
    queue->items[queue->rear] = item;
}

// Remove an item from the front of the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue->items[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }
    return item;
}

// Print the queue
void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    int i;
    for (i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->items[i]);
    }
    printf("\n");
}

// Example program
int main() {
    // Create a queue of capacity 5
    Queue* queue = createQueue(5);

    // Enqueue some items to the queue
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Print the queue
    printQueue(queue);

    // Dequeue some items from the queue
    int item = dequeue(queue);
    printf("Dequeued item: %d\n", item);
    item = dequeue(queue);
    printf("Dequeued item: %d\n", item);
    item = dequeue(queue);
    printf("Dequeued item: %d\n", item);

    // Print the queue again
    printQueue(queue);

    // Free the queue
    free(queue->items);
    free(queue);

    return 0;
}