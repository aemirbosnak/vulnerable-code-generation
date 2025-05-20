//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int* data;
    int front;
    int rear;
    int size;
};

// Function to create a new queue
struct Queue* createQueue(int size) {
    struct Queue* newQueue = (struct Queue*)malloc(sizeof(struct Queue));
    newQueue->data = (int*)malloc(size * sizeof(int));
    newQueue->front = -1;
    newQueue->rear = -1;
    newQueue->size = size;
    return newQueue;
}

// Function to enqueue an element in the queue
void enqueue(struct Queue* queue, int value) {
    if (queue->rear == queue->size - 1) {
        printf("Queue is full, cannot enqueue\n");
        return;
    }
    queue->rear += 1;
    queue->data[queue->rear] = value;
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (queue->front == -1) {
        printf("Queue is empty, cannot dequeue\n");
        return -1;
    }
    int value = queue->data[queue->front];
    queue->front += 1;
    return value;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == -1) && (queue->rear == -1);
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->front == -1) && (queue->rear == queue->size - 1);
}

// Function to print the elements of the queue
void printQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->data[i]);
    }
    printf("\n");
}

int main() {
    int size = 5;
    struct Queue* queue = createQueue(size);

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    printQueue(queue);

    printf("Dequeued element: %d\n", dequeue(queue));

    printQueue(queue);

    printf("Dequeued element: %d\n", dequeue(queue));

    printQueue(queue);

    printf("Dequeued element: %d\n", dequeue(queue));

    printQueue(queue);

    printf("Dequeued element: %d\n", dequeue(queue));

    printQueue(queue);

    printf("Dequeued element: %d\n", dequeue(queue));

    printQueue(queue);

    printf("Dequeued element: %d\n", dequeue(queue));

    printQueue(queue);

    printf("Dequeued element: %d\n", dequeue(queue));

    printQueue(queue);

    printf("Dequeued element: %d\n", dequeue(queue));

    printQueue(queue);

    printf("Dequeued element: %d\n", dequeue(queue));

    printf("Queue is empty: %s\n", isEmpty(queue)? "Yes" : "No");

    printf("Queue is full: %s\n", isFull(queue)? "Yes" : "No");

    return 0;
}