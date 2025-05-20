//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct queue {
    Node* front;
    Node* rear;
    int count;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Error: Memory not allocated\n");
        exit(1);
    }
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;
    return q;
}

void enqueue(Queue* q, int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Error: Memory not allocated\n");
        exit(1);
    }
    temp->data = data;
    temp->next = NULL;
    if (q->front == NULL) {
        q->front = temp;
        q->rear = temp;
    }
    else {
        q->rear->next = temp;
        q->rear = temp;
    }
    q->count++;
}

int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Error: Queue is empty\n");
        exit(1);
    }
    int data = q->front->data;
    Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    q->count--;
    return data;
}

int peek(Queue* q) {
    if (q->front == NULL) {
        printf("Error: Queue is empty\n");
        exit(1);
    }
    return q->front->data;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

int size(Queue* q) {
    return q->count;
}

void destroyQueue(Queue* q) {
    Node* temp;
    while (q->front!= NULL) {
        temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    free(q);
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printf("Size of the queue is %d\n", size(q));
    printf("Peek element is %d\n", peek(q));
    printf("Dequeued element is %d\n", dequeue(q));
    printf("Size of the queue is %d\n", size(q));
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    }
    else {
        printf("Queue is not empty\n");
    }
    destroyQueue(q);
    return 0;
}