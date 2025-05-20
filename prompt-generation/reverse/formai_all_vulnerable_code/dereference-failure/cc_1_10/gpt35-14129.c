//FormAI DATASET v1.0 Category: Queue ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

struct queue* createQueue() {
    struct queue* q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isFull(struct queue* q) {
    if(q->rear == MAX_SIZE - 1) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty(struct queue* q) {
    if(q->front == -1 && q->rear == -1) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue(struct queue* q, int value) {
    if(isFull(q)) {
        printf("Queue is full! Cannot add another item.\n");
    } else {
        if(q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("%d added to the queue.\n", value);
    }
}

int dequeue(struct queue* q) {
    int item = 0;
    if(isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue anything.\n");
        return -1;
    } else {
        item = q->items[q->front];
        q->front++;
    }
    return item;
}

void printQueue(struct queue* q) {
    if(isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Current queue:\n");
        for(int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

int main() {
    struct queue* q = createQueue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    printf("\n");
    printQueue(q);

    dequeue(q);
    dequeue(q);
    printf("\n");
    printQueue(q);

    enqueue(q, 6);
    printf("\n");
    printQueue(q);

    return 0;
}