//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: surprised
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
Queue *createQueue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->items = (int *)malloc(sizeof(int) * capacity);
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = capacity;
    return queue;
}

// Check if the queue is full
int isFull(Queue *queue) {
    return (queue->rear == queue->capacity - 1);
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
    return (queue->front == -1);
}

// Add an element to the queue
void enQueue(Queue *queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }

    if (queue->front == -1) {
        queue->front = 0;
    }

    queue->rear++;
    queue->items[queue->rear] = item;
    printf("%d inserted into the queue\n", item);
}

// Remove an element from the queue
int deQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }

    int item = queue->items[queue->front];
    queue->front++;

    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }

    printf("%d removed from the queue\n", item);
    return item;
}

// Peek at the front element of the queue
int peek(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }

    return queue->items[queue->front];
}

// Print the queue
void printQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->items[i]);
    }
    printf("\n");
}

// Destroy the queue
void destroyQueue(Queue *queue) {
    if (queue) {
        free(queue->items);
        free(queue);
    }
}

// Example driver code
int main() {
    // Create a queue of capacity 5
    Queue *queue = createQueue(5);

    // Enqueue some elements
    enQueue(queue, 10);
    enQueue(queue, 20);
    enQueue(queue, 30);
    enQueue(queue, 40);
    enQueue(queue, 50);

    // Print the queue
    printQueue(queue);

    // Dequeue some elements
    deQueue(queue);
    deQueue(queue);

    // Print the queue again
    printQueue(queue);

    // Peek at the front element
    int front = peek(queue);
    printf("Front element: %d\n", front);

    // Destroy the queue
    destroyQueue(queue);

    return 0;
}