//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// A visionary Queue implementation that utilizes a circular buffer for efficient memory management.

// Define the Queue structure
typedef struct Queue {
    int front, rear, size;
    int capacity;
    int *array;
} Queue;

// Create a new Queue with a specified capacity
Queue* createQueue(int capacity) {
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->capacity = capacity;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

// Check if the Queue is empty
int isEmpty(Queue *queue) {
    return (queue->size == 0);
}

// Check if the Queue is full
int isFull(Queue *queue) {
    return (queue->size == queue->capacity);
}

// Add an element to the rear of the Queue
void enQueue(Queue *queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
    printf("%d inserted\n", item);
}

// Remove an element from the front of the Queue
int deQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

// Get the front element of the Queue
int front(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->array[queue->front];
}

// Get the rear element of the Queue
int rear(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->array[queue->rear];
}

// Print the Queue
void printQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for (int i = queue->front; i != queue->rear; i = (i + 1) % queue->capacity) {
        printf("%d ", queue->array[i]);
    }
    printf("%d\n", queue->array[queue->rear]);
}

// Free the memory allocated for the Queue
void deleteQueue(Queue *queue) {
    if (queue) {
        free(queue->array);
        free(queue);
    }
}

// Driver program to test the Queue implementation
int main() {
    // Create a Queue with a capacity of 5
    Queue *queue = createQueue(5);

    // Enqueue some elements into the Queue
    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);

    // Print the Queue
    printQueue(queue);

    // Dequeue an element from the Queue
    printf("Dequeued: %d\n", deQueue(queue));

    // Print the Queue
    printQueue(queue);

    // Get the front element of the Queue
    printf("Front element: %d\n", front(queue));

    // Get the rear element of the Queue
    printf("Rear element: %d\n", rear(queue));

    // Free the memory allocated for the Queue
    deleteQueue(queue);

    return 0;
}