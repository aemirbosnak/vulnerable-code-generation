//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

typedef struct {
    node* front;
    node* rear;
    int count;
} queue;

void init(queue* q) {
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;
}

bool isEmpty(queue* q) {
    return q->front == NULL;
}

bool isFull(queue* q) {
    return q->count == MAX_SIZE;
}

void enqueue(queue* q, int data) {
    node* newNode = (node*) malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Queue Overflow\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->count++;
}

int dequeue(queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        exit(0);
    }
    int data = q->front->data;
    node* temp = q->front;
    q->front = q->front->next;
    free(temp);
    q->count--;
    if (isEmpty(q)) {
        q->rear = NULL;
    }
    return data;
}

int peek(queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        exit(0);
    }
    return q->front->data;
}

void display(queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return;
    }
    node* temp = q->front;
    printf("Queue Elements: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    queue q;
    init(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    display(&q);
    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Dequeued element: %d\n", dequeue(&q));
    display(&q);
    printf("Peek element: %d\n", peek(&q));
    return 0;
}