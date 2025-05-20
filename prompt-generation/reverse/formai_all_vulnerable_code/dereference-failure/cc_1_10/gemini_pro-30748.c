//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
typedef struct Queue {
    int front, rear;
    int capacity;
    int *array;
} Queue;

// Create a new queue
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = queue->rear = -1;
    queue->capacity = capacity;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

// Check if the queue is full
int isFull(Queue* queue) {
    return (queue->rear == queue->capacity - 1);
}

// Check if the queue is empty
int isEmpty(Queue* queue) {
    return (queue->front == -1);
}

// Add an element to the queue
void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("The queue is full, cannot add %d\n", item);
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->array[queue->rear] = item;
}

// Remove an element from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("The queue is empty, cannot remove\n");
        return -1;
    }
    int item = queue->array[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    return item;
}

// Print the queue
void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("The queue is empty\n");
        return;
    }
    int i;
    printf("The queue is: ");
    for (i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

// Driver code to test the queue
int main() {
    Queue* queue = createQueue(5);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    printQueue(queue);
    dequeue(queue);
    dequeue(queue);
    printQueue(queue);
    return 0;
}