//FormAI DATASET v1.0 Category: Queue ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    int queue[MAX_QUEUE_SIZE];
    int rear;
    int front;
} Queue;

// Function to create a new queue
Queue* createQueue() {
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->rear = -1;
    newQueue->front = -1;
    return newQueue;
}

// Function to check if queue is full
int isFull(Queue* queue) {
    if (queue->rear == MAX_QUEUE_SIZE - 1) {
        return 1;
    }
    return 0;
}

// Function to check if queue is empty
int isEmpty(Queue* queue) {
    if (queue->front == -1) {
        return 1;
    }
    return 0;
}

// Function to add an element to the queue
void enqueue(Queue* queue, int element) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->rear = 0;
        queue->front = 0;
    } else {
        queue->rear++;
    }
    queue->queue[queue->rear] = element;
}

// Function to remove an element from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int element = queue->queue[queue->front];
    if (queue->rear == queue->front) {
        queue->rear = -1;
        queue->front = -1;
    } else {
        queue->front++;
    }
    return element;
}

// Function to display the elements of the queue
void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Elements of the queue are: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->queue[i]);
    }
    printf("\n");
}

int main() {
    Queue* myQueue = createQueue();
    enqueue(myQueue, 5);
    enqueue(myQueue, 10);
    enqueue(myQueue, 15);
    display(myQueue);

    int dequeuedElement1 = dequeue(myQueue);
    printf("Element dequeued: %d\n", dequeuedElement1);
    display(myQueue);

    int dequeuedElement2 = dequeue(myQueue);
    printf("Element dequeued: %d\n", dequeuedElement2);
    display(myQueue);

    enqueue(myQueue, 20);
    display(myQueue);

    return 0;
}