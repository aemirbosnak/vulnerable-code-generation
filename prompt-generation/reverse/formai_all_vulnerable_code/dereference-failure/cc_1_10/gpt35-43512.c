//FormAI DATASET v1.0 Category: Queue Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

typedef struct queue Q;

Q* createQueue() {
    Q* q = malloc(sizeof(Q));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isFull(Q* q) {
    return q->rear == MAX_SIZE - 1;
}

int isEmpty(Q* q) {
    return q->front == -1 && q->rear == -1;
}

void enQueue(Q* q, int value) {
    if (isFull(q)) {
        printf("Queue is full.\n");
    } else {
        if (isEmpty(q)) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("Inserted %d into the queue.\n", value);
    }
}

void deQueue(Q* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else if (q->front == q->rear) {
        printf("Deleted %d from the queue.\n", q->items[q->front]);
        q->front = -1;
        q->rear = -1;
    } else {
        printf("Deleted %d from the queue.\n", q->items[q->front]);
        q->front++;
    }
}

void display(Q* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Current elements in the queue: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

int main() {
    Q* q = createQueue();

    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);
    display(q);

    deQueue(q);
    display(q);

    enQueue(q, 4);
    display(q);

    return 0;
}