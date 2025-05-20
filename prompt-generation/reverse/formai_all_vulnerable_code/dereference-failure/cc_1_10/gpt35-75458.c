//FormAI DATASET v1.0 Category: Queue Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int front, rear;
    int size;
    unsigned capacity;
    int* array;
} Queue;

// function to create a queue of given capacity
Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// function to check if the queue is full
int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

// function to check if the queue is empty
int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

// function to add an item to the queue
void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Error: Queue is full.\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
    printf("%d enqueued to queue.\n", item);
}

// function to remove an item from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Error: Queue is empty.\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

// function to get the front element of the queue
int front(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Error: Queue is empty.\n");
        return -1;
    }
    return queue->array[queue->front];
}

// function to get the rear element of the queue
int rear(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Error: Queue is empty.\n");
        return -1;
    }
    return queue->array[queue->rear];
}

// testing the queue implementation
int main() {
    Queue* queue = createQueue(5);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    printf("Front element is %d.\n", front(queue));
    printf("Rear element is %d.\n", rear(queue));

    printf("%d dequeued from queue.\n", dequeue(queue));

    printf("Front element is %d.\n", front(queue));
    printf("Rear element is %d.\n", rear(queue));

    enqueue(queue, 40);
    enqueue(queue, 50);
    enqueue(queue, 60);
    printf("Front element is %d.\n", front(queue));
    printf("Rear element is %d.\n", rear(queue));
    return 0;
}