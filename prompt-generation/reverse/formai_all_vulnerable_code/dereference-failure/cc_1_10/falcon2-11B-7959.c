//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for the Queue
typedef struct Queue {
    int size;
    int front;
    int rear;
    int* arr;
} Queue;

// Function to create a new Queue
Queue* createQueue(int size) {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->size = size;
    queue->front = -1;
    queue->rear = -1;
    queue->arr = (int*) malloc(size * sizeof(int));
    return queue;
}

// Function to check if the Queue is empty
int isEmpty(Queue* queue) {
    if (queue->front == -1 && queue->rear == -1) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if the Queue is full
int isFull(Queue* queue) {
    if (queue->front == queue->rear && queue->rear == queue->size - 1) {
        return 1;
    } else {
        return 0;
    }
}

// Function to enqueue an element in the Queue
void enqueue(Queue* queue, int element) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % queue->size;
    }

    queue->arr[queue->rear] = element;
}

// Function to dequeue an element from the Queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }

    int element = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->size;
    }
    return element;
}

// Function to print the elements in the Queue
void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }

    int i;
    printf("Queue elements: ");
    for (i = queue->front; i!= -1; i = (i + 1) % queue->size) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

// Function to check if an element is in the Queue
int isInQueue(Queue* queue, int element) {
    if (isEmpty(queue)) {
        return 0;
    }

    int i;
    for (i = queue->front; i!= -1; i = (i + 1) % queue->size) {
        if (queue->arr[i] == element) {
            return 1;
        }
    }
    return 0;
}

int main() {
    // Create a Queue of size 5
    Queue* queue = createQueue(5);

    // Enqueue elements
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Print the Queue
    printf("Queue elements: ");
    printQueue(queue);

    // Dequeue an element
    int dequeuedElement = dequeue(queue);
    printf("Dequeued element: %d\n", dequeuedElement);

    // Check if an element is in the Queue
    int elementToCheck = 2;
    if (isInQueue(queue, elementToCheck)) {
        printf("%d is in the Queue\n", elementToCheck);
    } else {
        printf("%d is not in the Queue\n", elementToCheck);
    }

    // Free the Queue
    free(queue->arr);
    free(queue);

    return 0;
}