//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 100

// Queue structure
typedef struct {
    int data[QUEUE_SIZE];
    int front;
    int rear;
} Queue;

// Create a new queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Check if the queue is full
int isFull(Queue* queue) {
    return (queue->rear + 1) % QUEUE_SIZE == queue->front;
}

// Enqueue an element
void enqueue(Queue* queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % QUEUE_SIZE;
        queue->data[queue->rear] = data;
    }
}

// Dequeue an element
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        int data = queue->data[queue->front];
        if (queue->front == queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % QUEUE_SIZE;
        }
        return data;
    }
}

// Print the queue
void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
    } else {
        int i;
        for (i = queue->front; i != queue->rear; i = (i + 1) % QUEUE_SIZE) {
            printf("%d ", queue->data[i]);
        }
        printf("%d\n", queue->data[i]);
    }
}

// Destroy the queue
void destroyQueue(Queue* queue) {
    free(queue);
}

// Main function
int main() {
    // Create a queue
    Queue* queue = createQueue();

    // Enqueue some elements
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Print the queue
    printf("Queue: ");
    printQueue(queue);

    // Dequeue some elements
    dequeue(queue);
    dequeue(queue);

    // Print the queue
    printf("Queue: ");
    printQueue(queue);

    // Destroy the queue
    destroyQueue(queue);

    return 0;
}