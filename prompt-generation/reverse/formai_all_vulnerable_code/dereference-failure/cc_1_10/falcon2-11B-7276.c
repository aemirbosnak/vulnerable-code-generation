//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int *arr;
    int front;
    int rear;
    int size;
};

void enqueue(struct Queue *q, int item) {
    if (q->rear == q->size) {
        printf("Queue is full. Cannot enqueue\n");
        return;
    }

    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = item;
}

int dequeue(struct Queue *q) {
    if (q->front == q->rear) {
        printf("Queue is empty. Cannot dequeue\n");
        return -1;
    }

    int item = q->arr[q->front];
    q->front = (q->front + 1) % q->size;
    return item;
}

void printQueue(struct Queue *q) {
    if (q->front > q->rear) {
        printf("Queue is empty. Cannot print\n");
        return;
    }

    int i;
    for (i = q->front; i!= q->rear; i = (i + 1) % q->size) {
        printf("%d ", q->arr[i]);
    }
}

int main() {
    struct Queue q;
    q.size = 5;
    q.arr = (int *)malloc(q.size * sizeof(int));
    q.front = 0;
    q.rear = 0;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    printf("Queue after enqueueing\n");
    printQueue(&q);

    printf("Dequeueing from the queue\n");
    dequeue(&q);
    printQueue(&q);

    printf("Dequeueing from the queue\n");
    dequeue(&q);
    printQueue(&q);

    printf("Dequeueing from the queue\n");
    dequeue(&q);
    printQueue(&q);

    printf("Dequeueing from the queue\n");
    dequeue(&q);
    printQueue(&q);

    printf("Dequeueing from the queue\n");
    dequeue(&q);
    printQueue(&q);

    printf("Dequeueing from the queue\n");
    dequeue(&q);
    printQueue(&q);

    printf("Dequeueing from the queue\n");
    dequeue(&q);
    printQueue(&q);

    free(q.arr);
    return 0;
}