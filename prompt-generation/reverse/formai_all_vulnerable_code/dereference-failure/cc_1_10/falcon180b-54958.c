//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int *data;
    int front;
    int rear;
    int size;
} Queue;

void initQueue(Queue *q) {
    q->data = (int *)malloc(MAX_QUEUE_SIZE * sizeof(int));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isEmpty(Queue *q) {
    return (q->size == 0);
}

int isFull(Queue *q) {
    return (q->size == MAX_QUEUE_SIZE);
}

void enqueue(Queue *q, int item) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue item.\n");
        return;
    }
    q->rear++;
    q->data[q->rear] = item;
    q->size++;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue item.\n");
        return -1;
    }
    int item = q->data[q->front];
    q->front++;
    q->size--;
    return item;
}

void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    displayQueue(&q);
    int item = dequeue(&q);
    printf("Dequeued item is: %d\n", item);
    displayQueue(&q);
    return 0;
}