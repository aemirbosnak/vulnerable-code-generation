//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

typedef struct Queue Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isFull(Queue* q) {
    return q->rear == MAX_SIZE - 1;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
    } else {
        if (q->front == -1) q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
        printf("Inserted -> %d\n", value);
    }
}

int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            printf("Resetting queue\n");
            q->front = q->rear = -1;
        }
    }
    return item;
}

void display(Queue* q) {
    int i;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue contains:\n");
        for (i = q->front; i < q->rear + 1; i++) {
            printf("%d\n", q->items[i]);
        }
    }
}

int main() {
    Queue* q = createQueue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);

    display(q);

    dequeue(q);
    dequeue(q);

    display(q);

    enqueue(q, 4);

    display(q);

    return 0;
}