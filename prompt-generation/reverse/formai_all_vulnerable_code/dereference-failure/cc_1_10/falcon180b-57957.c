//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

// Cryptic style implementation of a C Queue

typedef struct {
    void **data;
    int front;
    int rear;
    int size;
} Queue;

void init(Queue *q, int s) {
    q->data = (void **)malloc(s * sizeof(void *));
    q->front = -1;
    q->rear = -1;
    q->size = s;
}

int isEmpty(Queue *q) {
    return q->front == -1 && q->rear == -1;
}

int isFull(Queue *q) {
    return q->rear == q->size - 1;
}

void enqueue(Queue *q, void *data) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->data[q->rear] = data;
}

void *dequeue(Queue *q) {
    void *data = NULL;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return data;
    }
    data = q->data[q->front];
    q->front++;
    if (isEmpty(q)) {
        q->rear = -1;
    }
    return data;
}

void display(Queue *q) {
    int i;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    for (i = q->front; i <= q->rear; i++) {
        printf("%d ", *(int *)q->data[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    init(&q, 5);
    enqueue(&q, (void *)1);
    enqueue(&q, (void *)2);
    enqueue(&q, (void *)3);
    enqueue(&q, (void *)4);
    enqueue(&q, (void *)5);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    if (isEmpty(&q)) {
        printf("Queue is empty\n");
    }
    return 0;
}