//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
typedef struct Queue {
    int *arr;
    int front;
    int rear;
    int size;
} Queue;

// Create a new queue
Queue *createQueue(int size) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->arr = (int *)malloc(sizeof(int) * size);
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    return queue;
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
    return queue->front == -1;
}

// Check if the queue is full
int isFull(Queue *queue) {
    return queue->rear == queue->size - 1;
}

// Enqueue an element
void enQueue(Queue *queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }

    // If the queue is empty, set the front and rear to 0
    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        // Increment the rear
        queue->rear++;
    }
    // Add the data to the rear of the queue
    queue->arr[queue->rear] = data;
}

// Dequeue an element
int deQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }

    // If there is only one element in the queue, set the front and rear to -1
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        // Increment the front
        queue->front++;
    }
    // Return the data from the front of the queue
    return queue->arr[queue->front];
}

// Print the queue
void printQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }

    // Print the elements of the queue
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

// Free the queue
void freeQueue(Queue *queue) {
    free(queue->arr);
    free(queue);
}

// Main function
int main() {
    // Create a new queue
    Queue *queue = createQueue(5);

    // Enqueue some elements
    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    enQueue(queue, 4);
    enQueue(queue, 5);

    // Print the queue
    printQueue(queue);

    // Dequeue some elements
    printf("Dequeued %d\n", deQueue(queue));
    printf("Dequeued %d\n", deQueue(queue));
    printf("Dequeued %d\n", deQueue(queue));

    // Print the queue
    printQueue(queue);

    // Free the queue
    freeQueue(queue);

    return 0;
}