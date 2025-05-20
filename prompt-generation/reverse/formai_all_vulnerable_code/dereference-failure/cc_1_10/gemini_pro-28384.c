//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Define the Queue structure
typedef struct Queue {
    int front, rear, size;
    int *array;
} Queue;

// Create a new queue
Queue* createQueue(int size) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = -1;
    queue->size = size;
    queue->array = (int *)malloc(queue->size * sizeof(int));
    return queue;
}

// Check if the queue is full
int isFull(Queue *queue) {
    return (queue->rear == queue->size - 1);
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
    return (queue->front == -1);
}

// Add an element to the queue
void enqueue(Queue *queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->array[queue->rear] = item;
        printf("%d inserted\n", item);
    }
}

// Remove an element from the queue
int dequeue(Queue *queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return(-1);
    }
    else {
        item = queue->array[queue->front];
        queue->front++;
        if (queue->front > queue->rear)
            queue->front = queue->rear = -1;
        printf("%d deleted\n", item);
        return(item);
    }
}

// Print the queue
void printQueue(Queue *queue) {
    int i;
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    else {
        printf("Queue: ");
        for (i = queue->front; i <= queue->rear; i++)
            printf("%d ", queue->array[i]);
        printf("\n");
    }
}

int main() {
    // Create a queue of size 5
    Queue *queue = createQueue(5);

    // Enqueue elements into the queue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    // Print the queue
    printQueue(queue);

    // Dequeue elements from the queue
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    // Print the queue
    printQueue(queue);

    // Enqueue elements into the queue again
    enqueue(queue, 60);
    enqueue(queue, 70);

    // Print the queue
    printQueue(queue);

    return 0;
}