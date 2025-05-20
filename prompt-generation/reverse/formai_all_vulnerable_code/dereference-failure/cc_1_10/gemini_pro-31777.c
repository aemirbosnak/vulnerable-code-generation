//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
struct Queue {
    int *items;
    int front;
    int rear;
    int size;
};

// Create a new queue
struct Queue *createQueue(int size) {
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->items = (int *)malloc(sizeof(int) * size);
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    return queue;
}

// Check if the queue is empty
int isEmpty(struct Queue *queue) {
    if (queue->front == -1)
        return 1;
    else
        return 0;
}

// Check if the queue is full
int isFull(struct Queue *queue) {
    if ((queue->rear + 1) % queue->size == queue->front)
        return 1;
    else
        return 0;
}

// Add an element to the queue
void enqueue(struct Queue *queue, int element) {
    if (isFull(queue))
        printf("Queue is full!\n");
    else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear = (queue->rear + 1) % queue->size;
        queue->items[queue->rear] = element;
        printf("%d inserted\n", element);
    }
}

// Remove an element from the queue
int dequeue(struct Queue *queue) {
    int element;
    if (isEmpty(queue))
        printf("Queue is empty!\n");
    else {
        element = queue->items[queue->front];
        queue->front = (queue->front + 1) % queue->size;
        if (queue->front == -1)
            queue->rear = -1;
        printf("%d deleted\n", element);
        return element;
    }
    return (-1);
}

// Print the queue
void printQueue(struct Queue *queue) {
    int i;
    if (isEmpty(queue))
        printf("Queue is empty!\n");
    else {
        printf("Queue: ");
        for (i = queue->front; i != queue->rear; i = (i + 1) % queue->size) {
            printf("%d ", queue->items[i]);
        }
        printf("%d", queue->items[queue->rear]);
        printf("\n");
    }
}

// Destroy the queue
void destroyQueue(struct Queue *queue) {
    free(queue->items);
    free(queue);
}

// Main function
int main() {
    // Create a queue of size 5
    struct Queue *queue = createQueue(5);

    // Enqueue some elements
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Print the queue
    printQueue(queue);

    // Dequeue some elements
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    // Print the queue
    printQueue(queue);

    // Destroy the queue
    destroyQueue(queue);

    return 0;
}