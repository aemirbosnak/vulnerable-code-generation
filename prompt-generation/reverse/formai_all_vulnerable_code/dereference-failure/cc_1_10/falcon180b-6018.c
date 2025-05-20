//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(Queue* q, int data) {
    Node* node = (Node*)malloc(sizeof(Node));

    if (node == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    node->data = data;
    node->next = NULL;

    if (q->front == NULL) {
        q->front = node;
        q->rear = node;
    }
    else {
        q->rear->next = node;
        q->rear = node;
    }
}

void dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    Node* node = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(node);
}

void display(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    Node* temp = q->front;

    printf("Queue elements are: ");

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    Queue q;

    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    display(&q);

    dequeue(&q);
    dequeue(&q);

    display(&q);

    return 0;
}