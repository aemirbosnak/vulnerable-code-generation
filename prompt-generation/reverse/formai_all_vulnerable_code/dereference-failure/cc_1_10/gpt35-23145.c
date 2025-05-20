//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

typedef struct Queue queue;

queue* newQueue() {
    queue* q = malloc(sizeof(queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(queue* q) {
    return q->rear == -1;
}

void enqueue(queue* q, int value) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Queue Overflow!\n");
    } else {
        if (q->front == -1) q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
        printf("%d enqueued.\n", value);
    }
}

void dequeue(queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow!\n");
    } else {
        printf("%d dequeued.\n", q->items[q->front]);
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
}

void printQueue(queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        int i;
        printf("Queue:\n");
        for (i = q->front; i < q->rear + 1; i++) {
            printf("| %d ", q->items[i]);
        }
        printf("|\n");
    }
}

int main() {
    queue* q = newQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printQueue(q);

    dequeue(q);
    dequeue(q);
    printQueue(q);

    enqueue(q, 40);
    printQueue(q);

    dequeue(q);
    printQueue(q);

    return 0;
}