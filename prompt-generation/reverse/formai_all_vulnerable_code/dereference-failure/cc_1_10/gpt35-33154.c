//FormAI DATASET v1.0 Category: Queue Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct Queue {
    int data[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

Queue* createQueue() {
    Queue* queue = malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isFull(Queue* queue) {
    return (queue->rear == MAX_QUEUE_SIZE - 1);
}

int isEmpty(Queue* queue) {
    return (queue->front == -1 || queue->front > queue->rear);
}

void enqueue(Queue* queue, int data) {
    if (isFull(queue)) {
        printf("Queue overflow! Cannot add element %d\n", data);
    }
    else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->data[queue->rear] = data;
        printf("Element %d has been added to the queue successfully.\n", data);
    }
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Cannot remove any elements.\n");
        return -1;
    }
    else {
        int data = queue->data[queue->front];
        queue->front++;
        printf("Element %d has been removed from the queue successfully.\n", data);
        return data;
    }
}

void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Current queue: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->data[i]);
    }
    printf("\n");
}

int main() {
    Queue* queue = createQueue();
    enqueue(queue, 5);
    enqueue(queue, 7);
    enqueue(queue, 3);
    printQueue(queue);
    dequeue(queue);
    dequeue(queue);
    printQueue(queue);
    enqueue(queue, 9);
    enqueue(queue, 2);
    enqueue(queue, 8);
    enqueue(queue, 1);
    enqueue(queue, 6);
    enqueue(queue, 4);
    enqueue(queue, 10);
    // Comment the line below to test queue overflow
    enqueue(queue, 11);
    printQueue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    // Comment the line below to test queue underflow
    dequeue(queue);
    return 0;
}