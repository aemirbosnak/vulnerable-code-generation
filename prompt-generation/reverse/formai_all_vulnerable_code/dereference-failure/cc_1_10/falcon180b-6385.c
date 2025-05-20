//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue(int size) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->arr = (int*)malloc(sizeof(int) * size);
    q->front = -1;
    q->rear = -1;
    q->size = size;
    return q;
}

void enqueue(Queue* q, int value) {
    if (q->rear == q->size - 1) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->arr[q->rear] = value;
}

int dequeue(Queue* q) {
    if (q->front == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int value = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

void display(Queue* q) {
    if (q->front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    Queue* q = createQueue(MAX_SIZE);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    int value = dequeue(q);
    printf("Dequeued value is: %d\n", value);
    display(q);
    return 0;
}