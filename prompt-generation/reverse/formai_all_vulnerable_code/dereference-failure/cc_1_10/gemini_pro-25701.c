//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the queue
#define MAX_SIZE 100

// Declare the queue structure
typedef struct Queue {
    int front, rear;
    int size;
    int *arr;
} Queue;

// Create a new queue
Queue *createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = -1;
    queue->size = 0;
    queue->arr = (int *)malloc(MAX_SIZE * sizeof(int));
    return queue;
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
    return (queue->front == -1);
}

// Check if the queue is full
int isFull(Queue *queue) {
    return (queue->rear == MAX_SIZE - 1);
}

// Enqueue an element into the queue
void enqueue(Queue *queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full! Cannot enqueue %d.\n", data);
    } else {
        if (queue->front == -1) {  // If the queue is empty
            queue->front = 0;
        }
        queue->rear++;
        queue->arr[queue->rear] = data;
        queue->size++;
        printf("Enqueued %d successfully.\n", data);
    }
}

// Dequeue an element from the queue
int dequeue(Queue *queue) {
    int data;
    if (isEmpty(queue)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    } else {
        data = queue->arr[queue->front];
        if (queue->front == queue->rear) {  // If there is only one element in the queue
            queue->front = queue->rear = -1;
        } else {
            queue->front++;
        }
        queue->size--;
        printf("Dequeued %d successfully.\n", data);
        return data;
    }
}

// Get the front element of the queue
int peek(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Cannot peek.\n");
        return -1;
    } else {
        return queue->arr[queue->front];
    }
}

// Print the queue
void printQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue: ");
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->arr[i]);
        }
        printf("\n");
    }
}

// Destroy the queue
void destroyQueue(Queue *queue) {
    free(queue->arr);
    free(queue);
}

// Main function
int main() {
    // Create a queue
    Queue *queue = createQueue();

    // Enqueue some elements
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    // Print the queue
    printQueue(queue);

    // Dequeue some elements
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    // Print the queue
    printQueue(queue);

    // Get the front element
    int front = peek(queue);
    printf("Front element: %d\n", front);

    // Destroy the queue
    destroyQueue(queue);

    return 0;
}