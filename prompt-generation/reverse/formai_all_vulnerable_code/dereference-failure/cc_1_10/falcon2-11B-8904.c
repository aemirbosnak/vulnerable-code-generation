//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct node {
    int data;
    struct node* next;
} node;

typedef struct queue {
    node* front;
    node* rear;
    int size;
} queue;

queue* createQueue() {
    queue* q = (queue*)malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

void enqueue(queue* q, int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->size == 0) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    q->size++;
}

int dequeue(queue* q) {
    if (q->size == 0) {
        printf("Queue is empty!\n");
        return -1;
    }

    node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    q->size--;
    free(temp);

    return temp->data;
}

int peek(queue* q) {
    if (q->size == 0) {
        printf("Queue is empty!\n");
        return -1;
    }

    return q->front->data;
}

void printQueue(queue* q) {
    if (q->size == 0) {
        printf("Queue is empty!\n");
        return;
    }

    node* temp = q->front;
    printf("Queue:\n");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    queue* q = createQueue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);

    printf("Front: %d\n", peek(q));
    printQueue(q);

    dequeue(q);
    dequeue(q);

    printf("Front: %d\n", peek(q));
    printQueue(q);

    return 0;
}