//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int *array;
    int front;
    int rear;
    int size;
} Queue;

void initQueue(Queue *q) {
    q->array = (int *)malloc(MAX_SIZE * sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->size = 0;
}

int isEmpty(Queue *q) {
    return (q->front == -1 && q->rear == -1);
}

int isFull(Queue *q) {
    return ((q->rear + 1) % MAX_SIZE == q->front);
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }
    q->array[q->rear] = value;
    q->size++;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->array[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    q->size--;
    return value;
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are:\n");
    int i = q->front;
    while (i!= q->rear) {
        printf("%d ", q->array[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", q->array[q->rear]);
}

int main() {
    Queue q;
    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);
    int value = dequeue(&q);
    printf("Dequeued value is: %d\n", value);
    display(&q);
    return 0;
}