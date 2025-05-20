//FormAI DATASET v1.0 Category: Queue Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef struct {
    int front;
    int rear;
    int items[MAX_QUEUE_SIZE];
} Queue;

Queue *createQueue() {
    Queue *newQueue = (Queue*) malloc(sizeof(Queue));
    newQueue->front = -1;
    newQueue->rear = -1;
    return newQueue;
}

int isQueueFull(Queue *queue) {
    if ((queue->front == 0 && queue->rear == MAX_QUEUE_SIZE - 1) || queue->rear == queue->front - 1)
        return 1;
    else
        return 0;
}

int isQueueEmpty(Queue *queue) {
    if (queue->front == -1)
        return 1;
    else
        return 0;
}

void enqueue(Queue *queue, int value) {
    if (isQueueFull(queue)) 
        printf("Queue Overflow\n");
    else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
        queue->items[queue->rear] = value;
        printf("Inserted %d into queue\n", value);
    }
}

int dequeue(Queue *queue) {
    int value;
    if (isQueueEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1;
    }
    else {
        value = queue->items[queue->front];
        if (queue->front == queue->rear)
            queue->front = queue->rear = -1;
        else
            queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
        return value;
    }
}

void printQueue(Queue *queue) {
    int i;
    if (isQueueEmpty(queue))
        printf("Queue is empty\n");
    else {
        printf("Queue contains: ");
        for (i = queue->front; i <= queue->rear; i++)
            printf("%d ", queue->items[i]);
        printf("\n");
    }
}

int main() {
    Queue *queue = createQueue();
    enqueue(queue, 5);
    enqueue(queue, 10);
    enqueue(queue, 15);
    printf("dequeued %d from queue\n", dequeue(queue));
    printf("dequeued %d from queue\n", dequeue(queue));
    printQueue(queue);
    enqueue(queue, 20);
    enqueue(queue, 25);
    enqueue(queue, 30);
    enqueue(queue, 35);
    printQueue(queue);
    return 0;
}