//FormAI DATASET v1.0 Category: Queue Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10  // maximum size of the queue

struct Queue {
    int front, rear, size;
    int *arr;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));   // allocating memory for the queue
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->arr = (int*)malloc(sizeof(int) * MAX_QUEUE_SIZE);   // allocating memory for the array inside queue
    return queue;
}

int isFull(struct Queue* queue) {
    return queue->size == MAX_QUEUE_SIZE;
}

int isEmpty(struct Queue* queue) {
    return queue->size == 0;
}

void enqueue(struct Queue* queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue new element.\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->arr[queue->rear] = data;
    queue->size++;
    printf("%d has been enqueued successfully.\n",data);
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue any element.\n");
        return -1;
    }
    int data = queue->arr[queue->front];
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    queue->size--;
    printf("%d has been dequeued successfully.\n",data);
    return data;
}

int peek(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot peek any element.\n");
        return -1;
    }
    return queue->arr[queue->front];
}

int main() {
    struct Queue* queue = createQueue();   // create a queue
    enqueue(queue, 7);
    enqueue(queue, 9);
    enqueue(queue, 5);
    enqueue(queue, 3);
    enqueue(queue, 8);

    dequeue(queue);
    dequeue(queue);

    printf("Element at the front of the queue: %d\n", peek(queue));
    
    return 0;
}