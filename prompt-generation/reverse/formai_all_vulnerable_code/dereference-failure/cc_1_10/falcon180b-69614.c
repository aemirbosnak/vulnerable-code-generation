//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
    int count;
} Queue;

Queue *createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;
    return q;
}

bool isEmpty(Queue *q) {
    return (q->front == NULL && q->rear == NULL);
}

bool isFull(Queue *q) {
    return (q->count == MAX_SIZE);
}

void enqueue(Queue *q, int data) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;

    if (isEmpty(q)) {
        q->front = temp;
        q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }

    q->count++;
}

int dequeue(Queue *q) {
    int data = 0;

    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return data;
    }

    Node *temp = q->front;
    data = temp->data;
    q->front = q->front->next;
    free(temp);

    q->count--;

    if (isEmpty(q)) {
        q->front = NULL;
        q->rear = NULL;
    }

    return data;
}

void display(Queue *q) {
    Node *temp = q->front;

    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    Queue *q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    display(q);

    int data = dequeue(q);
    printf("Dequeued data: %d\n", data);

    display(q);

    data = dequeue(q);
    printf("Dequeued data: %d\n", data);

    display(q);

    data = dequeue(q);
    printf("Dequeued data: %d\n", data);

    display(q);

    data = dequeue(q);
    printf("Dequeued data: %d\n", data);

    display(q);

    data = dequeue(q);
    printf("Dequeued data: %d\n", data);

    display(q);

    return 0;
}