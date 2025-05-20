//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Define the Queue structure
typedef struct Queue {
    int *array;
    int front;
    int rear;
    int size;
} Queue;

// Create a new queue
Queue *createQueue(int size) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->array = (int *)malloc(size * sizeof(int));
    queue->front = queue->rear = -1;
    queue->size = size;
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
void enQueue(Queue *queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->array[queue->rear] = item;
        printf("%d inserted\n", item);
    }
}

// Remove an element from the queue
int deQueue(Queue *queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return (-1);
    } else {
        item = queue->array[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
        printf("%d deleted\n", item);
        return (item);
    }
}

// Print the queue
void printQueue(Queue *queue) {
    int i;
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue: ");
        for (i = queue->front; i <= queue->rear; i++) {
            printf("%d  ", queue->array[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Create a queue of size 5
    Queue *queue = createQueue(5);

    // Enqueue some elements
    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    enQueue(queue, 4);
    enQueue(queue, 5);
    enQueue(queue, 6);

    // Print the queue
    printQueue(queue);

    // Dequeue some elements
    deQueue(queue);
    deQueue(queue);
    deQueue(queue);

    // Print the queue
    printQueue(queue);

    return 0;
}