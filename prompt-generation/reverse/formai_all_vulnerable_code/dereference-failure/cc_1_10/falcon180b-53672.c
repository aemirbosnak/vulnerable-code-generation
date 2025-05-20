//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int data;
    int index;
} QueueNode;

typedef struct {
    QueueNode queueArray[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isEmpty(Queue* queue) {
    if (queue->front == -1 && queue->rear == -1)
        return 1;
    else
        return 0;
}

int isFull(Queue* queue) {
    if ((queue->rear + 1) % MAX_QUEUE_SIZE == queue->front)
        return 1;
    else
        return 0;
}

void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    }
    QueueNode node = {value, queue->rear};
    queue->queueArray[queue->rear] = node;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = queue->queueArray[queue->front].data;
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    }
    return value;
}

void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    int i = queue->front;
    do {
        printf("%d ", queue->queueArray[i].data);
        i = (i + 1) % MAX_QUEUE_SIZE;
    } while (i!= queue->rear);
    printf("\n");
}

int main() {
    Queue* queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    display(queue);
    int value = dequeue(queue);
    printf("Dequeued value: %d\n", value);
    display(queue);
    enqueue(queue, 40);
    display(queue);
    return 0;
}