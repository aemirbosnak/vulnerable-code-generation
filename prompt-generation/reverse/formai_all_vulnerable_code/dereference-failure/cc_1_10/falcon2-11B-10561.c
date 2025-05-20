//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

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
        printf("Queue is empty!\n");
        return -1;
    }

    int data = q->front->data;
    Node* temp = q->front;
    q->front = q->front->next;
    q->size--;

    free(temp);
    return data;
}

int main() {
    Queue q;
    q.front = NULL;
    q.rear = NULL;
    q.size = 0;

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    printf("Front: %d\n", dequeue(&q));
    printf("Rear: %d\n", dequeue(&q));
    printf("Front: %d\n", dequeue(&q));
    printf("Rear: %d\n", dequeue(&q));
    printf("Front: %d\n", dequeue(&q));
    printf("Rear: %d\n", dequeue(&q));

    return 0;
}