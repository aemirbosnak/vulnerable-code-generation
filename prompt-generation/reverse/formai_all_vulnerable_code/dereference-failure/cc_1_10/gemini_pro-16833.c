//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Defining the structure of a queue
typedef struct queue {
    int *items;
    int front;
    int rear;
    int capacity;
} Queue;

// Utility function to create a new queue of a specified size
Queue *createQueue(int capacity) {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->items = (int *) malloc(capacity * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = capacity;
    return queue;
}

// Utility function to check if the queue is empty
int isEmpty(Queue *queue) {
    return queue->front == -1;
}

// Utility function to check if the queue is full
int isFull(Queue *queue) {
    return queue->rear == queue->capacity - 1;
}

// Function to enqueue (add) an item to the rear of the queue
void enqueue(Queue *queue, int item) {
    if (isFull(queue)) {
        printf("Sherlock: Looks like the queue is full, my dear Watson.\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = item;
        printf("Sherlock: I have added %d to the queue, Watson.\n", item);
    }
}

// Function to dequeue (remove) an item from the front of the queue
int dequeue(Queue *queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Sherlock: The queue is empty, Watson.\n");
        return -1;
    } else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
        printf("Sherlock: I have removed %d from the queue, Watson.\n", item);
    }
    return item;
}

// Function to peek (view) the front item of the queue
int peek(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Sherlock: The queue is empty, Watson.\n");
        return -1;
    } else {
        printf("Sherlock: The front item of the queue is %d, Watson.\n", queue->items[queue->front]);
    }
}

// Function to print the elements of the queue
void printQueue(Queue *queue) {
    int i;
    if (isEmpty(queue)) {
        printf("Sherlock: The queue is empty, Watson.\n");
        return;
    }
    printf("Sherlock: The elements of the queue are: ");
    for (i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->items[i]);
    }
    printf("\n");
}

// Main function to test the functions of the queue
int main() {
    int capacity = 5;
    Queue *queue = createQueue(capacity);

    // Enqueue some items
    enqueue(queue, 221);
    enqueue(queue, 13);
    enqueue(queue, 6);
    enqueue(queue, 3);
    enqueue(queue, 7);

    // Peek the front item of the queue
    peek(queue);

    // Dequeue some items
    dequeue(queue);
    dequeue(queue);

    // Print the elements of the queue
    printQueue(queue);

    // Dequeue the remaining items
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    // Check if the queue is empty
    if (isEmpty(queue)) {
        printf("Sherlock: The queue is empty, Watson.\n");
    } else {
        printf("Sherlock: The queue is not empty, Watson.\n");
    }

    // Free the memory allocated to the queue
    free(queue->items);
    free(queue);

    return 0;
}