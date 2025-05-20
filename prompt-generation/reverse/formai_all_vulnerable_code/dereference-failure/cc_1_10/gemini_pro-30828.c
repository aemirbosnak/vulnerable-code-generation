//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum size of the queue
#define MAX_SIZE 10

// Define the structure of a queue
struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Create a new queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Check if the queue is empty
int isEmpty(struct Queue* queue) {
    if (queue->rear == -1) {
        return 1;
    } else {
        return 0;
    }
}

// Check if the queue is full
int isFull(struct Queue* queue) {
    if (queue->rear == MAX_SIZE - 1) {
        return 1;
    } else {
        return 0;
    }
}

// Add an element to the queue
void enqueue(struct Queue* queue, int element) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = element;
        printf("%d inserted to the queue\n", element);
    }
}

// Remove an element from the queue
int dequeue(struct Queue* queue) {
    int element;
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return (-1);
    } else {
        element = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
        printf("%d deleted from the queue\n", element);
        return (element);
    }
}

// Print the queue
void printQueue(struct Queue* queue) {
    int i;
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue: ");
        for (i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->items[i]);
        }
        printf("\n");
    }
}

// Free the queue
void freeQueue(struct Queue* queue) {
    free(queue);
}

// Main function
int main() {
    // Create a queue
    struct Queue* queue = createQueue();
srand(time(0));
int n;
for (n = 0; n < 10; n++) {
enqueue(queue, rand() % 100);
}
    // Print the queue
    printQueue(queue);

    // Insert an element into the queue
    enqueue(queue, 10);

    // Print the queue
    printQueue(queue);

    // Remove an element from the queue
    dequeue(queue);

    // Print the queue
    printQueue(queue);

    // Free the queue
    freeQueue(queue);

    return 0;
}