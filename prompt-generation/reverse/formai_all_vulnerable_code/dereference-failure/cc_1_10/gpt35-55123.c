//FormAI DATASET v1.0 Category: Queue ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Defining the Queue struct
typedef struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
} Queue;

// Function to create a Queue
Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;  // important to assign rear as last position
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Function to check if queue is full
int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

// Function to check if queue is empty
int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

// Function to add element to Queue
void enqueue(Queue* queue, int item) {
    if(isFull(queue)) {
        printf("Overflow error. Cannot add element.\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
    printf("Added %d to the Queue.\n", item);
}

// Function to remove element from Queue
int dequeue(Queue* queue) {
    if(isEmpty(queue)) {
        printf("Underflow error. Cannot remove element.\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    printf("Removed %d from the Queue.\n", item);
    return item;
}

// Main function to test Queue implementation
int main() {
    Queue* queue = createQueue(5); // Creating Queue of capacity 5

    // Enqueueing elements into Queue
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Trying to add element when Queue is full
    enqueue(queue, 6);

    // Removing elements from Queue
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    // Trying to remove element when Queue is empty
    dequeue(queue);

    return 0;
}