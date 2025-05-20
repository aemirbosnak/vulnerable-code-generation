//FormAI DATASET v1.0 Category: Queue Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 50

struct Queue {
    int front, rear;
    int items[MAX_SIZE];
};

struct Queue* createQueue() {
    struct Queue* q = malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

bool isFull(struct Queue* q) {
    return (q->front == 0 && q->rear == MAX_SIZE - 1) || (q->front == q->rear + 1);
}

bool isEmpty(struct Queue* q) {
    return q->front == -1;
}

int size(struct Queue* q) {
    if (isEmpty(q)) {
        return 0;
    }
    return (MAX_SIZE - q->front + q->rear + 1) % MAX_SIZE;
}

void enqueue(struct Queue* q, int x) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
        q->rear = 0;
    } else if (q->rear == MAX_SIZE - 1) {
        q->rear = 0;
    } else {
        q->rear++;
    }
    q->items[q->rear] = x;
    printf("Enqueued %d to the queue\n", x);
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int removed = q->items[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else if (q->front == MAX_SIZE - 1) {
        q->front = 0;
    } else {
        q->front++;
    }
    printf("Removed %d from the queue\n", removed);
    return removed;
}

int peek(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->items[q->front];
}

void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    int i;
    printf("Queue: ");
    if (q->front <= q->rear) {
        for (i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
    } else {
        for (i = q->front; i <= MAX_SIZE - 1; i++) {
            printf("%d ", q->items[i]);
        }
        for (i = 0; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
    }
    printf("\n");
}

int main() {
    struct Queue* q = createQueue();
    enqueue(q, 10);
    display(q);
    enqueue(q, 20);
    display(q);
    enqueue(q, 30);
    display(q);
    dequeue(q);
    display(q);
    enqueue(q, 40);
    display(q);
    printf("Size: %d\n", size(q));
    printf("Front item: %d\n", peek(q));
    return 0;
}