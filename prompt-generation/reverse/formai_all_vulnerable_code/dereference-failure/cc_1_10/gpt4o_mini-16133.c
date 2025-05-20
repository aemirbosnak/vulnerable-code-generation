//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // Define the maximum size of the queue

typedef struct {
    int *array;      // Dynamic array to hold queue elements
    int front;      // Index of the front element
    int rear;       // Index of the rear element
    int size;       // Current size of the queue
    int capacity;   // Maximum capacity of the queue
} CircularQueue;

// Function to create a circular queue
CircularQueue* createQueue(int capacity) {
    CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    queue->capacity = capacity;
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Function to check if the queue is full
int isFull(CircularQueue* queue) {
    return (queue->size == queue->capacity);
}

// Function to check if the queue is empty
int isEmpty(CircularQueue* queue) {
    return (queue->size == 0);
}

// Function to add an item to the queue
void enqueue(CircularQueue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full! Cannot enqueue %d\n", item);
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity; // Circular increment
    queue->array[queue->rear] = item;
    if (queue->front == -1) {
        queue->front = 0; // Set front index if this is the first element
    }
    queue->size++;
    printf("Enqueued: %d\n", item);
}

// Function to remove an item from the queue
int dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Cannot dequeue!\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity; // Circular increment
    queue->size--;
    if (isEmpty(queue)) {
        queue->front = -1; // Reset front and rear if the queue is empty
        queue->rear = -1;
    }
    printf("Dequeued: %d\n", item);
    return item;
}

// Function to display the contents of the queue
void displayQueue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Current Queue:\n");
    for (int i = 0, index = queue->front; i < queue->size; i++) {
        printf("%d ", queue->array[index]);
        index = (index + 1) % queue->capacity; // Circular access
    }
    printf("\n");
}

// Function to free the allocated memory
void freeQueue(CircularQueue* queue) {
    free(queue->array);
    free(queue);
}

// Main function to demonstrate queue operations
int main() {
    CircularQueue* queue = createQueue(MAX_SIZE);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    displayQueue(queue);

    dequeue(queue);
    dequeue(queue);

    displayQueue(queue);

    enqueue(queue, 60);
    enqueue(queue, 70);

    displayQueue(queue);

    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    
    displayQueue(queue);

    freeQueue(queue);
    return 0;
}