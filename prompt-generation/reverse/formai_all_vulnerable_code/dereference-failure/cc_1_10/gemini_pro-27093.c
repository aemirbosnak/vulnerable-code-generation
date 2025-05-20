//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define the Queue structure
typedef struct Queue {
    int front, rear, size;
    int *array;
} Queue;

// Create a new queue
Queue* createQueue(int size) {
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    queue->front = queue->rear = -1;
    queue->size = size;
    queue->array = (int*) malloc(queue->size * sizeof(int));
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
void enqueue(Queue *queue, int element) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    else if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->array[queue->rear] = element;
    printf("%d enqueued to queue\n", element);
}

// Remove an element from the queue
int dequeue(Queue *queue) {
    int element;
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return (-1);
    }
    else if (queue->front == queue->rear) {
        element = queue->array[queue->front];
        queue->front = queue->rear = -1;
    }
    else {
        element = queue->array[queue->front];
        queue->front++;
    }
    printf("%d dequeued from queue\n", element);
    return element;
}

// Display the elements of the queue
void display(Queue *queue) {
    int i;
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    }
    else {
        printf("Queue: ");
        for (i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->array[i]);
        }
        printf("\n");
    }
}

// Free the memory allocated for the queue
void deleteQueue(Queue *queue) {
    if (queue) {
        if (queue->array) {
            free(queue->array);
        }
        free(queue);
    }
}

// Driver program to test the Queue implementation
int main() {
    // Create a queue of size 5
    Queue *queue = createQueue(5);
    
    // Enqueue elements into the queue
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Display the elements of the queue
    display(queue);

    // Dequeue elements from the queue
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));

    // Display the elements of the queue
    display(queue);

    // Free the memory allocated for the queue
    deleteQueue(queue);
    
    return 0;
}