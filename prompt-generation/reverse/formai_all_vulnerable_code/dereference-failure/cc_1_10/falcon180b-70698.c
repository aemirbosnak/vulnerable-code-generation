//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int front;
    int rear;
    int size;
} Queue;

Queue *createQueue(int size) {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->data = (int *) malloc(size * sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->size = size;
    return q;
}

void enqueue(Queue *q, int value) {
    if ((q->rear + 1) % q->size == q->front) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    if (q->rear == -1) {
        q->rear = 0;
    }
    q->rear = (q->rear + 1) % q->size;
    q->data[q->rear] = value;
}

int dequeue(Queue *q) {
    if (q->front == -1 || q->rear == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->data[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->size;
    }
    return value;
}

void display(Queue *q) {
    if (q->front == -1 || q->rear == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = q->front; i <= q->rear; i = (i + 1) % q->size) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    Queue *q = createQueue(5);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    display(q);
    int value = dequeue(q);
    printf("Dequeued value: %d\n", value);
    display(q);
    return 0;
}