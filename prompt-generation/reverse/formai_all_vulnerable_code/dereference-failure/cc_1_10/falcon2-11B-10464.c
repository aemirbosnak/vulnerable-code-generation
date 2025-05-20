//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent the queue
typedef struct {
    int front;
    int rear;
    int capacity;
    int* data;
} Queue;

// Function to initialize the queue
Queue* createQueue(int capacity) {
    Queue* queue = malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = capacity;
    queue->data = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

// Function to enqueue an element
void enqueue(Queue* queue, int value) {
    if (queue->rear == queue->capacity - 1) {
        printf("Queue is full!\n");
        return;
    }
    queue->data[++queue->rear] = value;
    queue->front = (queue->front + 1) % queue->capacity;
}

// Function to dequeue an element
int dequeue(Queue* queue) {
    if (queue->front == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    return value;
}

// Function to display the queue
void displayQueue(Queue* queue) {
    if (queue->front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = queue->front; i!= queue->rear; i = (i + 1) % queue->capacity) {
        printf("%d ", queue->data[i]);
    }
    printf("\n");
}

// Main function
int main() {
    Queue* queue = createQueue(5);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    enqueue(queue, 6);
    displayQueue(queue);
    dequeue(queue);
    dequeue(queue);
    displayQueue(queue);
    dequeue(queue);
    dequeue(queue);
    displayQueue(queue);
    dequeue(queue);
    dequeue(queue);
    displayQueue(queue);
    dequeue(queue);
    dequeue(queue);
    displayQueue(queue);
    dequeue(queue);
    displayQueue(queue);
    return 0;
}