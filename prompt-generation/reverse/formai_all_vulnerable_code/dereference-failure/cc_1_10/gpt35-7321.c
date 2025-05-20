//FormAI DATASET v1.0 Category: Queue Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100 // Maximum size of the queue

typedef struct Queue {
    int front;
    int rear;
    int size;
    int items[MAX_QUEUE_SIZE];
} Queue;

// Function to initialize the queue
Queue* initializeQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

// Function to check if the queue is empty
int isQueueEmpty(Queue* queue) {
    return queue->size == 0;
}

// Function to check if the queue is full
int isQueueFull(Queue* queue) {
    return queue->size == MAX_QUEUE_SIZE;
}

// Function to add an item to the queue
void enqueue(Queue* queue, int item) {
    if (isQueueFull(queue)) {
        printf("Queue Overflow!\n");
        return;
    }

    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->items[queue->rear] = item;
    queue->size++;
}

// Function to remove an item from the queue
int dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue Underflow!\n");
        return -1;
    }

    int item = queue->items[queue->front];
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    queue->size--;
    return item;
}

// Function to get the front element of the queue
int getFront(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }

    return queue->items[queue->front];
}

// Function to get the rear element of the queue
int getRear(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }

    return queue->items[queue->rear];
}

// Function to display the queue
void display(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }

    int i = queue->front;
    int count = 0;
    while (count < queue->size) {
        printf("%d ", queue->items[i]);
        i = (i + 1) % MAX_QUEUE_SIZE;
        count++;
    }
    printf("\n");
}

int main() {
    Queue* queue = initializeQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    display(queue);
    printf("Front element: %d\n", getFront(queue));
    printf("Rear element: %d\n", getRear(queue));
    dequeue(queue);
    dequeue(queue);
    display(queue);
    printf("Front element: %d\n", getFront(queue));
    printf("Rear element: %d\n", getRear(queue));
    enqueue(queue, 50);
    enqueue(queue, 60);
    enqueue(queue, 70);
    display(queue);
    printf("Front element: %d\n", getFront(queue));
    printf("Rear element: %d\n", getRear(queue));
    enqueue(queue, 80);
    display(queue);
    printf("Front element: %d\n", getFront(queue));
    printf("Rear element: %d\n", getRear(queue));
    return 0;
}