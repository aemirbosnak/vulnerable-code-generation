//FormAI DATASET v1.0 Category: Queue Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

Queue* createQueue() {
    Queue* Q = (Queue*) malloc(sizeof(Queue));
    Q->front = -1;
    Q->rear = -1;
    return Q;
}

int isFull(Queue* Q) {
    if (Q->rear == MAX_SIZE - 1) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty(Queue* Q) {
    if (Q->front == -1) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue(Queue* Q, int data) {
    if (isFull(Q)) {
        printf("Queue is full!\n");
        return;
    }
    if (Q->front == -1 && Q->rear == -1) {
        Q->front = Q->rear = 0;
        Q->data[0] = data;
    } else {
        Q->rear++;
        Q->data[Q->rear] = data;
    }
}

int dequeue(Queue* Q) {
    if (isEmpty(Q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = Q->data[Q->front];
    if (Q->front == Q->rear) {
        Q->front = Q->rear = -1;
    } else {
        Q->front++;
    }
    return data;
}

void printQueue(Queue* Q) {
    if (isEmpty(Q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for (int i = Q->front; i <= Q->rear; i++) {
        printf("%d ", Q->data[i]);
    }
    printf("\n");
}

int main() {
    Queue* Q = createQueue();

    enqueue(Q, 10);
    printQueue(Q);
    enqueue(Q, 20);
    printQueue(Q);
    enqueue(Q, 30);
    printQueue(Q);
    enqueue(Q, 40);
    printQueue(Q);
    enqueue(Q, 50);
    printQueue(Q);

    printf("Dequeue: %d\n", dequeue(Q));
    printf("Dequeue: %d\n", dequeue(Q));
    printQueue(Q);

    enqueue(Q, 60);
    printQueue(Q);
    enqueue(Q, 70);
    printQueue(Q);
    enqueue(Q, 80);
    printQueue(Q);
    enqueue(Q, 90);
    printQueue(Q);
    enqueue(Q, 100);
    printQueue(Q);
    enqueue(Q, 110);
    printQueue(Q);

    printf("Dequeue: %d\n", dequeue(Q));
    printf("Dequeue: %d\n", dequeue(Q));
    printf("Dequeue: %d\n", dequeue(Q));
    printf("Dequeue: %d\n", dequeue(Q));
    printf("Dequeue: %d\n", dequeue(Q));
    printf("Dequeue: %d\n", dequeue(Q));
    printf("Dequeue: %d\n", dequeue(Q));

    return 0;
}