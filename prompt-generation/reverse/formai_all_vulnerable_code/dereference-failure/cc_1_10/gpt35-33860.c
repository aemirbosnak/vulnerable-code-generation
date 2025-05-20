//FormAI DATASET v1.0 Category: Queue Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct queue{
    int* data;
    int front, rear;
} Queue;

void init(Queue *Q) {
    Q->data = (int*)malloc(sizeof(int)*MAX_QUEUE_SIZE);
    Q->front = Q->rear = -1;
}

int isFull(Queue* Q) {
    return ((Q->rear+1)%MAX_QUEUE_SIZE == Q->front);
}

int isEmpty(Queue *Q) {
    return (Q->front == -1 && Q->rear == -1);
}

void clear(Queue *Q) {
    Q->front = Q->rear = -1;
}

void enqueue(Queue *Q, int value) {
    if(isFull(Q)) {
        printf("Error: Queue is full. Cannot enqueue any more elements.\n");
        return;
    }
    if(isEmpty(Q)) {
        Q->front = Q->rear = 0;
        Q->data[0] = value;
        return;
    }
    Q->rear = (Q->rear+1)%MAX_QUEUE_SIZE;
    Q->data[Q->rear] = value;
}

void dequeue(Queue *Q) {
    if(isEmpty(Q)) {
        printf("Error: Queue is empty. Cannot dequeue any more elements.\n");
        return;
    }
    if(Q->front == Q->rear) {
        clear(Q);
        return;
    }
    Q->front = (Q->front+1)%MAX_QUEUE_SIZE;
}

int peek(Queue *Q) {
    if(isEmpty(Q)) {
        printf("Error: Queue is empty. Cannot peek at any elements.\n");
        return -1;
    }
    return Q->data[Q->front];
}

int main() {
    Queue Q;
    init(&Q);
    printf("Queue is Initialized.\n");
    printf("Queue is Empty: %d\n", isEmpty(&Q));
    printf("Queue is Full: %d\n", isFull(&Q));
    enqueue(&Q, 10);
    enqueue(&Q, 20);
    enqueue(&Q, 30);
    enqueue(&Q, 40);
    printf("Queue is Empty: %d\n", isEmpty(&Q));
    printf("Queue is Full: %d\n", isFull(&Q));
    printf("Peek at first element: %d\n", peek(&Q));
    dequeue(&Q);
    printf("Peek at first element: %d\n", peek(&Q));
    enqueue(&Q, 50);
    enqueue(&Q, 60);
    printf("Queue is Full: %d\n", isFull(&Q));
    while(!isEmpty(&Q)) {
        printf("Dequeued: %d\n", peek(&Q));
        dequeue(&Q);
    }
    printf("Queue is Empty: %d\n", isEmpty(&Q));
    return 0;
}