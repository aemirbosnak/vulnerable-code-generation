//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
struct Queue {
    int front, rear;
    int capacity;
    int *array;
};

// Create a new queue
struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->front = queue->rear = -1;
    queue->capacity = capacity;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

// Check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->rear == queue->capacity - 1);
}

// Check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

// Add an item to the queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->array[queue->rear] = item;
}

// Remove an item from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
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
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

// Free the queue
void freeQueue(struct Queue* queue) {
    free(queue->array);
    free(queue);
}

// Main function
int main() {
    // Create a queue of size 5
    struct Queue* queue = createQueue(5);

    // Add items to the queue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    // Print the queue
    printf("Queue: ");
    printQueue(queue);

    // Remove items from the queue
    int item = dequeue(queue);
    printf("Dequeued item: %d\n", item);
    item = dequeue(queue);
    printf("Dequeued item: %d\n", item);

    // Print the queue
    printf("Queue: ");
    printQueue(queue);

    // Free the queue
    freeQueue(queue);

    return 0;
}