//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the Queue struct
typedef struct queue {
    int* data;
    int front;
    int rear;
    int size;
} Queue;

// Function to create a new queue with a given size
Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (int*)malloc(size * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    return queue;
}

// Function to check if the queue is empty
bool isEmpty(Queue* queue) {
    return (queue->front == -1);
}

// Function to check if the queue is full
bool isFull(Queue* queue) {
    return (queue->rear == queue->size - 1);
}

// Function to add an element to the queue
void enqueue(Queue* queue, int element) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot add element.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % queue->size;
    }
    queue->data[queue->rear] = element;
}

// Function to remove an element from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot remove element.\n");
        return -1;
    }
    if (queue->front == queue->rear) {
        int element = queue->data[queue->front];
        queue->front = -1;
        queue->rear = -1;
        return element;
    } else {
        int element = queue->data[queue->front];
        queue->front = (queue->front + 1) % queue->size;
        return element;
    }
}

// Function to display the elements in the queue
void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Elements in the queue:\n");
    for (int i = queue->front; i!= -1; i = (i + 1) % queue->size) {
        printf("%d ", queue->data[i]);
    }
    printf("\n");
}

// Function to destroy a queue
void destroyQueue(Queue* queue) {
    free(queue->data);
    free(queue);
}

int main() {
    Queue* queue = createQueue(10);
    enqueue(queue, 5);
    enqueue(queue, 2);
    enqueue(queue, 9);
    enqueue(queue, 1);
    enqueue(queue, 8);
    enqueue(queue, 4);
    enqueue(queue, 3);
    enqueue(queue, 7);
    enqueue(queue, 6);
    enqueue(queue, 0);
    display(queue);
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));
    display(queue);
    destroyQueue(queue);
    return 0;
}