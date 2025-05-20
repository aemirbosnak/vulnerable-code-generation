//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int data;
    struct node *next;
} node;

typedef struct {
    node *front;
    node *rear;
} Queue;

void enqueue(Queue *q, int data) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue *q) {
    if (q->front == NULL) {
        return -1; // Queue is empty
    }

    int data = q->front->data;
    node *temp = q->front;
    q->front = q->front->next;

    free(temp);

    return data;
}

int peek(Queue *q) {
    if (q->front == NULL) {
        return -1; // Queue is empty
    }

    return q->front->data;
}

int isEmpty(Queue *q) {
    return q->front == NULL;
}

int main() {
    Queue q;
    q.front = NULL;
    q.rear = NULL;

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    printf("Front element: %d\n", peek(&q));
    printf("Rear element: %d\n", peek(&q));
    printf("Dequeueing...\n");
    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Front element: %d\n", peek(&q));

    if (isEmpty(&q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is not empty\n");
    }

    return 0;
}