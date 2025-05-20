//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: modular
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
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = capacity;
    queue->array = (int*)malloc(sizeof(int) * capacity);
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
void enqueue(Queue* queue, int element) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->array[queue->rear] = element;
    }
}

// Remove an element from the queue
int dequeue(Queue* queue) {
    int element;
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return (-1);
    } else {
        element = queue->array[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
        return element;
    }
}

// Print the queue
void display(Queue* queue) {
    int i;
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue: ");
        for (i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->array[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    Queue* queue = createQueue(5);

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    display(queue);

    dequeue(queue);
    dequeue(queue);

    display(queue);

    enqueue(queue, 6);
    enqueue(queue, 7);

    display(queue);

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    display(queue);

    return 0;
}