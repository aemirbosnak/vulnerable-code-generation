//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
typedef struct Queue {
    int front, rear, size;
    int *arr;
} Queue;

// Create a new queue
Queue* createQueue(int size) {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = queue->rear = -1;
    queue->size = size;
    queue->arr = (int*) malloc(queue->size * sizeof(int));
    return queue;
}

// Check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Check if the queue is full
int isFull(Queue* queue) {
    return queue->rear == queue->size - 1;
}

// Enqueue an element
void enQueue(Queue* queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }

    // If the queue is empty, set both front and rear to 0
    if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        // Increment the rear index
        queue->rear++;
    }

    // Insert the data at the rear index
    queue->arr[queue->rear] = data;
}

// Dequeue an element
int deQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }

    // If there is only one element in the queue, reset front and rear to -1
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        // Increment the front index
        queue->front++;
    }

    // Return the dequeued element
    return queue->arr[queue->front];
}

// Get the front element
int getFront(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }

    // Return the front element
    return queue->arr[queue->front];
}

// Print the queue
void printQueue(Queue* queue) {
    printf("Queue: ");
    if (isEmpty(queue)) {
        printf("Empty\n");
    } else {
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->arr[i]);
        }
    }
}

// Driver code
int main() {
    // Create a queue of size 5
    Queue* queue = createQueue(5);

    // Enqueue elements
    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    enQueue(queue, 4);
    enQueue(queue, 5);

    // Print the queue
    printQueue(queue);

    // Dequeue elements
    deQueue(queue);
    deQueue(queue);

    // Print the queue
    printQueue(queue);

    // Enqueue an element
    enQueue(queue, 6);

    // Print the queue
    printQueue(queue);

    // Get the front element
    int front = getFront(queue);
    printf("Front element: %d\n", front);

    return 0;
}