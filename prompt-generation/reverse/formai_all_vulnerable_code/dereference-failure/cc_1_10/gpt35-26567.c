//FormAI DATASET v1.0 Category: Queue Implementation ; Style: enthusiastic
// Welcome to my exciting C Queue Implementation program!
// Hold on tight because we're about to dive into the world of queues!

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Let's define our max queue size

// Declare our Queue struct
struct Queue {
    int front, rear;
    int arr[MAX_SIZE];
};

// Create a function to create and return a new Queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = 0;
    queue->rear = -1;
    return queue; // Return the new Queue
}

// Create a function to check if the queue is full
int isFull(struct Queue* queue) {
    return queue->rear == MAX_SIZE - 1; // Check if the rear index equals the maximum queue size minus 1
}

// Create a function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->rear < queue->front; // Check if the rear index is less than the front index
}

// Create a function to add an element to the back of the queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) { // Check if the queue is already full
        printf("Queue is full, cannot add %d\n", item);
        return;
    }
    queue->arr[++queue->rear] = item; // Add the element to the back of the queue
    printf("%d added to the queue\n", item);
}

// Create a function to remove the element at the front of the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) { // Check if the queue is already empty
        printf("Queue is empty, cannot remove\n");
        return -1;
    }
    int item = queue->arr[queue->front++]; // Store the element at the front index and increase the front index
    printf("%d removed from the queue\n", item);
    return item; // Return the removed item
}

// Let's test our Queue implementation!
int main() {
    struct Queue* queue = createQueue(); // Create a new Queue

    // Add some elements
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    // Remove some elements
    dequeue(queue);
    dequeue(queue);

    // Add some more elements
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Remove the remaining elements
    dequeue(queue);
    dequeue(queue);

    return 0; // All done!
}