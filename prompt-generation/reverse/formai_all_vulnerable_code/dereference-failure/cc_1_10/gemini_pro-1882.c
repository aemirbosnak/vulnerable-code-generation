//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
typedef struct Queue {
    int* data;
    int head;
    int tail;
    int size;
} Queue;

// Create a new queue
Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (int*)malloc(sizeof(int) * size);
    queue->head = 0;
    queue->tail = 0;
    queue->size = size;
    return queue;
}

// Delete the queue
void deleteQueue(Queue* queue) {
    free(queue->data);
    free(queue);
}

// Enqueue an element to the queue
void enqueue(Queue* queue, int element) {
    if ((queue->tail + 1) % queue->size == queue->head) {
        printf("Queue is full!\n");
    } else {
        queue->data[queue->tail] = element;
        queue->tail = (queue->tail + 1) % queue->size;
    }
}

// Dequeue an element from the queue
int dequeue(Queue* queue) {
    if (queue->head == queue->tail) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        int element = queue->data[queue->head];
        queue->head = (queue->head + 1) % queue->size;
        return element;
    }
}

// Check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->head == queue->tail;
}

// Check if the queue is full
int isFull(Queue* queue) {
    return (queue->tail + 1) % queue->size == queue->head;
}

// Print the queue
void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
    } else {
        int i = queue->head;
        while (i != queue->tail) {
            printf("%d ", queue->data[i]);
            i = (i + 1) % queue->size;
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Create a queue
    Queue* queue = createQueue(5);

    // Enqueue some elements
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    // Print the queue
    printQueue(queue);

    // Dequeue some elements
    dequeue(queue);
    dequeue(queue);

    // Print the queue
    printQueue(queue);

    // Delete the queue
    deleteQueue(queue);

    return 0;
}