//FormAI DATASET v1.0 Category: Queue Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue *) malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

void enQueue(Queue* q, int data) {
    Node* newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->front == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    q->size++;
}

int deQueue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }

    Node* delNode = q->front;
    int data = delNode->data;

    q->front = q->front->next;
    free(delNode);

    q->size--;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    return data;
}

int main() {
    Queue* myQueue = createQueue();

    enQueue(myQueue, 3);
    enQueue(myQueue, 5);
    enQueue(myQueue, 7);
    enQueue(myQueue, 9);

    printf("Dequeued item: %d\n", deQueue(myQueue));
    printf("Dequeued item: %d\n", deQueue(myQueue));
    printf("Dequeued item: %d\n", deQueue(myQueue));
    printf("Dequeued item: %d\n", deQueue(myQueue));

    enQueue(myQueue, 1);
    enQueue(myQueue, 2);

    printf("Dequeued item: %d\n", deQueue(myQueue));
    printf("Dequeued item: %d\n", deQueue(myQueue));

    return 0;
}