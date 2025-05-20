//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Define the queue structure
struct Queue {
    int *arr;
    int front;
    int rear;
    int capacity;
};

// Create a new queue
struct Queue *createQueue(int capacity) {
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->arr = (int *)malloc(sizeof(int) * capacity);
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = capacity;
    return queue;
}

// Check if the queue is empty
int isEmpty(struct Queue *queue) {
    return queue->front == -1;
}

// Check if the queue is full
int isFull(struct Queue *queue) {
    return queue->rear == queue->capacity - 1;
}

// Add an element to the queue
void enqueue(struct Queue *queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear++;
    }
    queue->arr[queue->rear] = data;
}

// Remove an element from the queue
int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }
    return data;
}

// Print the queue
void printQueue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    int i;
    printf("Queue: ");
    for (i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

// Free the queue
void freeQueue(struct Queue *queue) {
    free(queue->arr);
    free(queue);
}

// Driver code to test the queue
int main() {
    struct Queue *queue = createQueue(5);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    printQueue(queue);
    dequeue(queue);
    enqueue(queue, 4);
    enqueue(queue, 5);
    printQueue(queue);
    dequeue(queue);
    dequeue(queue);
    enqueue(queue, 6);
    printQueue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    freeQueue(queue);
    return 0;
}