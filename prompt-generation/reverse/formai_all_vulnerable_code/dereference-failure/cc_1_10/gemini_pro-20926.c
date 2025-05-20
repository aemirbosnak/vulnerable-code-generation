//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
struct Queue {
    int front, rear, size;
    int *array;
};

// Create a new queue
struct Queue* createQueue(int size) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = -1;
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
void enqueue(struct Queue* queue, int element) {
    if (isFull(queue)) {
        return;
    }
    else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->array[queue->rear] = element;
    }
}

// Remove an element from the queue
int dequeue(struct Queue* queue) {
    int element;
    if (isEmpty(queue)) {
        return (-1);
    }
    else {
        element = queue->array[queue->front];
        if (queue->front == queue->rear) {
            queue->front = queue->rear = -1;
        }
        else {
            queue->front++;
        }
        return (element);
    }
}

// Print the queue
void printQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    }
    else {
        printf("Queue: ");
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->array[i]);
        }
        printf("\n");
    }
}

// Driver code
int main() {
    // Create a queue of size 5
    struct Queue* queue = createQueue(5);

    // Enqueue elements into the queue
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Print the queue
    printQueue(queue);

    // Dequeue an element from the queue
    int element = dequeue(queue);
    printf("Dequeued element: %d\n", element);

    // Print the queue
    printQueue(queue);

    return 0;
}