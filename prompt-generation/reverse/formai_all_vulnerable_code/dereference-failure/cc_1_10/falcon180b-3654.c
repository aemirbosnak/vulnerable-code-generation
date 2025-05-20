//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct queue {
    int front;
    int rear;
    int *array;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    q->array = (int*) malloc(MAX_SIZE * sizeof(int));
    return q;
}

void enqueue(Queue* q, int data) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->array[q->rear] = data;
}

int dequeue(Queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = q->array[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return data;
}

void display(Queue* q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->array[i]);
    }
    printf("\n");
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    display(q);
    int data = dequeue(q);
    printf("Dequeued element is: %d\n", data);
    display(q);
    return 0;
}