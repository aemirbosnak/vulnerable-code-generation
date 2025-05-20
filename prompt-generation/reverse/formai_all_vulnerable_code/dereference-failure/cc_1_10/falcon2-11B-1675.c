//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

int isQueueEmpty(Queue* q) {
    return (q->front == NULL && q->rear == NULL);
}

void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (isQueueEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q) {
    int value;
    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }

    value = q->front->value;
    Node* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);

    return value;
}

void displayQueue(Queue* q) {
    Node* current = q->front;
    while (current!= NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Queue myQueue;
    initQueue(&myQueue);

    enqueue(&myQueue, 5);
    enqueue(&myQueue, 10);
    enqueue(&myQueue, 15);

    displayQueue(&myQueue);
    printf("Dequeue: %d\n", dequeue(&myQueue));
    displayQueue(&myQueue);

    return 0;
}