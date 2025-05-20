//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

struct Node {
    int data;
    struct Node *next;
};

struct Queue {
    struct Node *front;
    struct Node *rear;
};

void createQueue(struct Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(struct Queue *q, int data) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Queue is full\n");
        return;
    }
    newnode->data = data;
    newnode->next = NULL;
    if (q->rear == NULL) {
        q->front = newnode;
        q->rear = newnode;
        return;
    }
    q->rear->next = newnode;
    q->rear = newnode;
}

void dequeue(struct Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
}

void display(struct Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    struct Node *temp = q->front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Queue q;
    createQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);
    return 0;
}