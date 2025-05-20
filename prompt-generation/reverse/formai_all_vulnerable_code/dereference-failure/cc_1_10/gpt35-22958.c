//FormAI DATASET v1.0 Category: Queue ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    int front;
    int rear;
    int data[MAX_QUEUE_SIZE];
} Queue;

Queue* createQueue() {
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->front = -1;
    newQueue->rear = -1;
    return newQueue;
}

int isQueueEmpty(Queue* q) {
    return q->front == -1;
}

int isQueueFull(Queue* q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE) == q->front;
}

void enqueue(Queue* q, int data) {
    if(isQueueFull(q)) {
        printf("Queue is full!\n");
        return;
    }

    if(q->front == -1) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = data;
}

int dequeue(Queue* q) {
    if(isQueueEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }

    int data = q->data[q->front];
    if(q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    }

    return data;
}

void printQueue(Queue* q) {
    if(isQueueEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: ");
    int i;
    for(i = q->front; i != q->rear; i = (i + 1) % MAX_QUEUE_SIZE) {
        printf("%d ", q->data[i]);
    }
    printf("%d\n", q->data[q->rear]);
}

int main() {
    printf("Creating a new queue!\n");
    Queue* q = createQueue();

    printf("\nEnqueuing 5, 8, 3, 2, 10 to the queue!\n");
    enqueue(q, 5);
    enqueue(q, 8);
    enqueue(q, 3);
    enqueue(q, 2);
    enqueue(q, 10);

    printf("\nThe current state of the queue is:\n");
    printQueue(q);

    printf("\nDequeuing 2 elements from the queue!\n");
    int dequeued1 = dequeue(q);
    int dequeued2 = dequeue(q);

    printf("\nSuccessfully dequeued %d and %d!\n", dequeued1, dequeued2);

    printf("\nThe current state of the queue is:\n");
    printQueue(q);

    printf("\nEnqueuing 6, 7 to the queue!\n");
    enqueue(q, 6);
    enqueue(q, 7);

    printf("\nThe current state of the queue is:\n");
    printQueue(q);

    printf("\nDequeuing all elements from the queue!\n");
    int dequeued3 = dequeue(q);
    int dequeued4 = dequeue(q);
    int dequeued5 = dequeue(q);
    int dequeued6 = dequeue(q);
    int dequeued7 = dequeue(q);
    int dequeued8 = dequeue(q);

    printf("\nSuccessfully dequeued %d, %d, %d, %d, %d, %d!\n", dequeued1, dequeued2, dequeued3, dequeued4, dequeued5, dequeued6);

    printf("\nThe current state of the queue is:\n");
    printQueue(q);

    printf("\nTrying to dequeue another element from the queue!\n");
    int dequeued9 = dequeue(q);

    printf("\n");

    return 0;
}