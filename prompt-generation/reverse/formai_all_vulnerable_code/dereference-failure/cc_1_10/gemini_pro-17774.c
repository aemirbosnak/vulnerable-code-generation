//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: scalable
#include <stdlib.h>
#include <stdio.h>

// Define the queue
struct Queue {
    int front;
    int rear;
    int size;
    int* array;
};

// Initialize the queue
struct Queue* createQueue(int size) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    queue->array = (int*)malloc(queue->size * sizeof(int));
    return queue;
}

// Check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->rear == queue->size - 1);
}

// Check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

// Add an element to the queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear++;
    }

    queue->array[queue->rear] = item;
}

// Remove an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return (-1);
    }

    int item = queue->array[queue->front];
    queue->front++;

    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }

    return item;
}

// Print the queue
void printQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

// Destroy the queue
void destroyQueue(struct Queue* queue) {
    free(queue->array);
    free(queue);
}

// Main function
int main() {
    // Create a queue of size 5
    struct Queue* queue = createQueue(5);

    // Add elements to the queue
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Print the queue
    printQueue(queue);

    // Remove an element from the queue
    int item = dequeue(queue);
    printf("Removed element: %d\n", item);

    // Print the queue
    printQueue(queue);

    // Destroy the queue
    destroyQueue(queue);

    return 0;
}