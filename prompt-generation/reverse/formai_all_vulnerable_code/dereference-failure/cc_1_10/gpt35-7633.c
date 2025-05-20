//FormAI DATASET v1.0 Category: Queue Implementation ; Style: shocked
#include<stdio.h>
#include<stdlib.h>

#define QUEUE_SIZE 10

typedef struct queue {
    int items[QUEUE_SIZE];
    int front;
    int rear;
} Queue;

Queue* createQueue() {
    Queue* q = malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(Queue* q) {
    return q->rear == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == QUEUE_SIZE - 1) {
        printf("The queue is full and unable to insert %d\n", value);
    }
    else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("The queue is empty\n");
        item = -1;
    }
    else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

void printQueue(Queue* q) {
    int i = q->front;
    if (isEmpty(q)) {
        printf("The queue is empty\n");
    }
    else {
        printf("Queue elements:\n");
        for (i = q->front; i < q->rear + 1; i++) {
            printf("%d\n", q->items[i]);
        }
    }
}

int main() {
    Queue* q = createQueue();

    printf("Queue Implementation in C:\n---------------------------------------------------\n");

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 7);
    enqueue(q, 8);
    enqueue(q, 9);
    enqueue(q, 10);

    printf("[Shockingly]Inserted 10 elements to the queue.\n");
    printQueue(q);

    printf("[Shockingly]");
    dequeue(q);

    printf("dequeued an element from the queue.\n");
    printQueue(q);

    return 0;
}