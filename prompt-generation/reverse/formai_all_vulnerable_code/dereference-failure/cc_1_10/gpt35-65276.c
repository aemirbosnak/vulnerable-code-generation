//FormAI DATASET v1.0 Category: Queue Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>

// Defining the maximum size of the queue
#define MAX_SIZE 5

// Defining the queue structure
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function to create a new queue
Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is full
int isFull(Queue* queue) {
    if (queue->rear == MAX_SIZE - 1) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    if (queue->front == -1 && queue->rear == -1) {
        return 1;
    } else {
        return 0;
    }
}

// Function to add an element to the queue
void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full\n");
    } else if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
        queue->items[queue->rear] = item;
        printf("Element enqueued successfully\n");
    } else {
        queue->rear++;
        queue->items[queue->rear] = item;
        printf("Element enqueued successfully\n");
    }
}

// Function to remove an element from the queue
void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    } else if (queue->front == queue->rear) {
        printf("Element dequeued: %d\n", queue->items[queue->front]);
        queue->front = -1;
        queue->rear = -1;
    } else {
        printf("Element dequeued: %d\n", queue->items[queue->front]);
        queue->front++;
    }
}

// Function to display the elements in the queue
void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements:\n");
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->items[i]);
        }
    }
}

// Main function to test the queue implementation
int main() {
    Queue* queue = createQueue();

    // Adding elements to the queue
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Trying to add another element to a full queue
    enqueue(queue, 6);

    // Removing elements from the queue
    dequeue(queue);
    dequeue(queue);

    // Displaying the elements in the queue
    display(queue);

    // Removing all elements from the queue
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    // Trying to remove an element from an empty queue
    dequeue(queue);

    return 0;
}