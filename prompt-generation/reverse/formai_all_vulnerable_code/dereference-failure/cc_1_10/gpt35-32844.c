//FormAI DATASET v1.0 Category: Queue ; Style: grateful
// Grateful Example of a C Queue program

#include<stdio.h>
#include<stdlib.h>

// Define Queue structure
struct Queue {
    int front, rear, size;
    int* arr;
};

// Create an empty queue of given size
struct Queue* createQueue(int size) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    queue->arr = (int*)malloc(size * sizeof(int));
    return queue;
}

// Check if queue is full
int isFull(struct Queue* queue) {
    return queue->rear == queue->size - 1;
}

// Check if queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == -1 || queue->front > queue->rear;
}

// Add item to queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full, cannot add more elements.");
        return;
    }
    queue->rear++;
    queue->arr[queue->rear] = item;
    if (queue->front == -1) {
        queue->front++;
    }
    printf("Element %d added to the queue successfully!\n", item);
}

// Remove item from queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty, cannot remove elements.");
        return -1;
    }
    int item = queue->arr[queue->front];
    queue->front++;
    printf("Element %d has been removed from the queue successfully!\n", item);
    return item;
}

// Get the front item of the queue
int front(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.");
        return -1;
    }
    return queue->arr[queue->front];
}

// Get the rear item of the queue
int rear(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.");
        return -1;
    }
    return queue->arr[queue->rear];
}

// Main function
int main() {
    printf("Welcome to the Grateful C Queue Program!\n\n");

    // Create queue
    struct Queue* queue = createQueue(5);

    // Enqueue items
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Try to add more items (queue is full)
    enqueue(queue, 6);

    // Dequeue items
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    // Get front and rear items
    printf("\nThe front item is: %d\n", front(queue));
    printf("The rear item is: %d\n", rear(queue));

    // Dequeue more items
    dequeue(queue);
    dequeue(queue);

    // Try to remove more items (queue is empty)
    dequeue(queue);

    printf("\nThank you for using the C Queue Program! Have a nice day!");

    return 0;
}