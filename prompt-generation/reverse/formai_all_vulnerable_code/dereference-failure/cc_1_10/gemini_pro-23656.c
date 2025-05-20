//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
typedef struct Queue {
    int front, rear;
    int capacity;
    int *array;
} Queue;

// Create a new queue
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = -1;
    queue->capacity = capacity;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Check if the queue is full
int isFull(Queue* queue) {
    return (queue->rear == queue->capacity - 1);
}

// Check if the queue is empty
int isEmpty(Queue* queue) {
    return (queue->front == -1);
}

// Add an element to the queue
void enqueue(Queue* queue, int element) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear++;
    }
    queue->array[queue->rear] = element;
    printf("%d inserted to the queue\n", element);
}

// Remove an element from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int element = queue->array[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    printf("%d removed from the queue\n", element);
    return element;
}

// Print the queue
void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d  ", queue->array[i]);
    }
    printf("\n");
}

// Test the queue
int main() {
    // Create a queue of capacity 5
    Queue* queue = createQueue(5);

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

    // Print the queue
    printQueue(queue);

    // Enqueue some more elements
    enqueue(queue, 6);
    enqueue(queue, 7);

    // Print the queue
    printQueue(queue);

    return 0;
}