//FormAI DATASET v1.0 Category: Queue Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

//Struct for Queue
typedef struct Queue Queue;
struct Queue{
    int *arr;
    int front, rear, size;
    unsigned capacity;
};

//Function to check if Queue is Full
int isFull(Queue* queue) {
    return queue->size == queue->capacity;
}

//Function to check if Queue is Empty
int isEmpty(Queue* queue) {
    return queue->size == 0;
}

//Function to initialize Queue
Queue* initialize(unsigned capacity) {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->arr = (int*) malloc(queue->capacity * sizeof(int));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

//Function to enqueue elements into Queue
void enqueue(Queue* queue, int ele) {
    if (isFull(queue)) {
        printf("Queue is Full! Cannot enqueue %d\n", ele);
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = ele;
    queue->size += 1;
    printf("%d enqueued to queue\n", ele);
}

//Function to dequeue elements from Queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is Empty! Cannot dequeue\n");
        return -1;
    }
    int ele = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size -= 1;
    printf("%d dequeued from queue\n", ele);
    return ele;
}

//Function to peek front element of Queue
int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is Empty! Cannot peek\n");
        return -1;
    }
    return queue->arr[queue->front];
}

int main() {
    Queue* queue = initialize(5);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50); //Queue is Full! Cannot enqueue 50

    printf("Front Element of Queue: %d\n", peek(queue));

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue); //Queue is Empty! Cannot dequeue

    printf("Front Element of Queue: %d\n", peek(queue)); //Queue is Empty! Cannot peek

    return 0;
}