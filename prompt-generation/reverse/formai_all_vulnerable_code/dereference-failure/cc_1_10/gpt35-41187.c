//FormAI DATASET v1.0 Category: Queue Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    int front;
    int rear;
    int data[MAX_QUEUE_SIZE];
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isFull(Queue* q) {
    if(q->rear == MAX_QUEUE_SIZE - 1)
        return 1;
    return 0;
}

int isEmpty(Queue* q) {
    if(q->front == -1 || q->front > q->rear)
        return 1;
    return 0;
}

int enqueue(Queue* q, int item) {
    if(isFull(q)) {
        printf("The queue is full!\n");
        return 0;
    }
    else {
        if(q->front == -1)
            q->front = 0;
        q->rear++;
        q->data[q->rear] = item;
        printf("%d enqueued to the queue.\n", item);
        return 1;
    }
}

int dequeue(Queue* q) {
    int item;
    if(isEmpty(q)) {
        printf("The queue is empty!\n");
        return -1;
    }
    else {
        item = q->data[q->front];
        q->front++;
        printf("%d dequeued from the queue.\n", item);
        return item;
    }
}

int main() {
    Queue* q = createQueue();

    enqueue(q, 5);
    enqueue(q, 10);
    enqueue(q, 15);
    enqueue(q, 20);
    enqueue(q, 25);
    enqueue(q, 30);
    enqueue(q, 35);
    enqueue(q, 40);
    enqueue(q, 45);
    enqueue(q, 50);

    int item = dequeue(q);
    printf("Dequeued item: %d\n", item);

    enqueue(q, 55);

    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    enqueue(q, 60);

    while(!isEmpty(q))
        dequeue(q);

    printf("Queue is empty now!\n");
    free(q);

    return 0;
}