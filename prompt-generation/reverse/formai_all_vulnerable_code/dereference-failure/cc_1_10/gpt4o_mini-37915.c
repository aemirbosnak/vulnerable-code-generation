//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5  // You can adjust the size of the queue

typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function to create a queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is full
bool isFull(Queue* queue) {
    return (queue->rear + 1) % MAX == queue->front;
}

// Function to check if the queue is empty
bool isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Function to enqueue an item to the queue
void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->items[queue->rear] = value;
    printf("Enqueued %d\n", value);
}

// Function to dequeue an item from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Cannot dequeue\n");
        return -1;
    }
    int item = queue->items[queue->front];
    // If only one element was in the queue, reset front and rear
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX;
    }
    printf("Dequeued %d\n", item);
    return item;
}

// Function to peek the front item of the queue
int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Nothing to peek\n");
        return -1;
    }
    return queue->items[queue->front];
}

// Function to display the queue
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = queue->front;
    while (true) {
        printf("%d ", queue->items[i]);
        if (i == queue->rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Main function demonstrating queue operations
int main() {
    Queue* queue = createQueue();

    // Enqueue elements
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    
    // Attempt to enqueue to a full queue
    enqueue(queue, 60); // Should indicate the queue is full

    // Display current queue
    displayQueue(queue);

    // Peek at the front item
    printf("Front item is: %d\n", peek(queue));
    
    // Dequeue elements
    dequeue(queue); // Removes 10
    dequeue(queue); // Removes 20

    // Display after dequeuing
    displayQueue(queue);

    // Enqueue more elements after some dequeue operations
    enqueue(queue, 60);
    enqueue(queue, 70);

    // Display final state of the queue
    displayQueue(queue);

    // Cleanup
    free(queue);

    return 0;
}