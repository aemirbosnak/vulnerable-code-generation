//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
typedef struct Queue {
    int front, rear;
    int size;
    int *array;
} Queue;

// Create a new queue
Queue *createQueue(int size) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = -1;
    queue->size = size;
    queue->array = (int *)malloc(queue->size * sizeof(int));
    return queue;
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
    return queue->front == -1;
}

// Check if the queue is full
int isFull(Queue *queue) {
    return queue->rear == queue->size - 1;
}

// Add an element to the queue
void enqueue(Queue *queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    else {
        if (queue->front == -1) {
            queue->front = queue->rear = 0;
        }
        else {
            queue->rear++;
        }
        queue->array[queue->rear] = data;
    }
}

// Remove an element from the queue
int dequeue(Queue *queue) {
    int data;
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    else {
        data = queue->array[queue->front];
        if (queue->front == queue->rear) {
            queue->front = queue->rear = -1;
        }
        else {
            queue->front++;
        }
        return data;
    }
}

// Print the queue
void printQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
    }
    else {
        int i;
        printf("Queue: ");
        for (i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->array[i]);
        }
        printf("\n");
    }
}

// Destroy the queue
void destroyQueue(Queue *queue) {
    free(queue->array);
    free(queue);
}

// Main function
int main() {
    // Create a queue of size 5
    Queue *queue = createQueue(5);

    // Enqueue elements into the queue
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Print the queue
    printQueue(queue);

    // Dequeue elements from the queue
    dequeue(queue);
    dequeue(queue);

    // Print the queue
    printQueue(queue);

    // Destroy the queue
    destroyQueue(queue);

    return 0;
}