//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node *next;
} node;

typedef struct {
    node *front;
    node *rear;
} queue;

queue *createQueue() {
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(queue *q, int data) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    if (q->rear == NULL) {
        q->front = newnode;
        q->rear = newnode;
    } else {
        q->rear->next = newnode;
        q->rear = newnode;
    }
}

int dequeue(queue *q) {
    node *temp = q->front;
    int data = temp->data;
    q->front = temp->next;
    free(temp);
    if (q->front == NULL) {
        q->rear = NULL;
    }
    return data;
}

bool isEmpty(queue *q) {
    if (q->front == NULL) {
        return true;
    } else {
        return false;
    }
}

void display(queue *q) {
    node *temp = q->front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    queue *q = createQueue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    display(q);
    printf("Dequeued element is %d\n", dequeue(q));
    display(q);
    printf("Dequeued element is %d\n", dequeue(q));
    display(q);
    printf("Dequeued element is %d\n", dequeue(q));
    display(q);
    printf("Dequeued element is %d\n", dequeue(q));
    display(q);
    printf("Dequeued element is %d\n", dequeue(q));
    display(q);
    printf("Dequeued element is %d\n", dequeue(q));
    display(q);
    printf("Dequeued element is %d\n", dequeue(q));
    display(q);
    return 0;
}