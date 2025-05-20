//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

int dequeue(Queue* q) {
    if (q->front == NULL) {
        return -1;
    }

    int data = q->front->data;
    Node* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    q->size--;

    return data;
}

int peek(Queue* q) {
    if (q->front == NULL) {
        return -1;
    }

    return q->front->data;
}

void display(Queue* q) {
    Node* temp = q->front;

    printf("Queue: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    initQueue(q);

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);

    display(q);
    printf("Dequeued: %d\n", dequeue(q));
    display(q);
    printf("Peek: %d\n", peek(q));
    display(q);

    return 0;
}