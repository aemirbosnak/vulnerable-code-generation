//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
typedef struct Queue {
    int *array;
    int front;
    int rear;
    int size;
} Queue;

// Initialize the queue
Queue *createQueue(int size) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->array = (int *)malloc(size * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    return queue;
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
    return queue->front == -1;
}

// Check if the queue is full
int isFull(Queue *queue) {
    return queue->front == queue->rear + 1;
}

// Enqueue an element to the queue
void enqueue(Queue *queue, int element) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear = queue->rear + 1;
        queue->array[queue->rear] = element;
    }
}

// Dequeue an element from the queue
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        int element = queue->array[queue->front];
        queue->front = queue->front + 1;
        if (queue->front > queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        }
        return element;
    }
}

// Print the queue
void printQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    } else {
        int i;
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

// Test the queue
int main() {
    // Create a queue of size 5
    Queue *queue = createQueue(5);

    // Enqueue elements to the queue
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
    dequeue(queue);

    // Print the queue
    printQueue(queue);

    // Destroy the queue
    destroyQueue(queue);

    return 0;
}