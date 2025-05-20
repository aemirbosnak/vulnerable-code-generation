//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Define the Queue structure
typedef struct Queue {
    int front, rear, size;
    int *array;
} Queue;

// Create a new queue
Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = -1;
    queue->size = size;
    queue->array = (int*)malloc(queue->size * sizeof(int));
    return queue;
}

// Check if the queue is full
int isFull(Queue* queue) {
    return (queue->rear == queue->size - 1);
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
            queue->front = queue->rear = 0;
        } else {
            queue->rear++;
        }
        queue->array[queue->rear] = element;
        printf("%d inserted into the queue\n", element);
    }
}

// Remove an element from the queue
int dequeue(Queue* queue) {
    int element;
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return(-1);
    } else {
        element = queue->array[queue->front];
        if (queue->front >= queue->rear) {
            queue->front = queue->rear = -1;
        } else {
            queue->front++;
        }
        printf("%d deleted from the queue\n", element);
        return(element);
    }
}

// Display the queue
void display(Queue* queue) {
    int i;
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue: ");
        for (i = queue->front; i <= queue->rear; i++) {
            printf("%d  ", queue->array[i]);
        }
        printf("\n");
    }
}

// Free the queue
void freeQueue(Queue* queue) {
    if (queue) {
        free(queue->array);
        free(queue);
    }
}

// Driver code
int main() {
    // Create a queue of size 5
    Queue* queue = createQueue(5);

    // Enqueue elements into the queue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    // Display the queue
    display(queue);

    // Dequeue elements from the queue
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    // Display the queue
    display(queue);

    // Free the queue
    freeQueue(queue);

    return 0;
}