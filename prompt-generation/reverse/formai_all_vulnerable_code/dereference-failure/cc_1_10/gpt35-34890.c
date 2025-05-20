//FormAI DATASET v1.0 Category: Queue ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_CAPACITY 10

typedef struct queue {
    int front;
    int rear;
    int size;
    int* arr;
} Queue;

void enqueue(Queue* q, int item) {
    if (q->size == QUEUE_CAPACITY) {
        printf("Queue is full! Cannot enqueue %d\n", item);
        return;
    }

    q->rear = (q->rear + 1) % QUEUE_CAPACITY;
    q->arr[q->rear] = item;
    q->size++;
    printf("Enqueued %d\n", item);
}

int dequeue(Queue* q) {
    if (q->size == 0) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }

    int item = q->arr[q->front];
    q->front = (q->front + 1) % QUEUE_CAPACITY;
    q->size--;
    printf("Dequeued %d\n", item);
    return item;
}

void print_queue(Queue* q) {
    if (q->size == 0) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Items in queue: ");
    int i = q->front;
    while (i != q->rear) {
        printf("%d, ", q->arr[i]);
        i = (i + 1) % QUEUE_CAPACITY;
    }
    printf("%d\n", q->arr[i]);
}

int main() {
    Queue q;
    q.front = 0;
    q.rear = -1;
    q.size = 0;
    q.arr = (int*)malloc(QUEUE_CAPACITY * sizeof(int));

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);
    enqueue(&q, 70);
    enqueue(&q, 80);
    enqueue(&q, 90);
    enqueue(&q, 100);
    enqueue(&q, 110); // Queue is full! Cannot enqueue 110
    print_queue(&q);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    print_queue(&q);

    enqueue(&q, 120);
    print_queue(&q);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q); // Queue is empty! Cannot dequeue.
    print_queue(&q);

    free(q.arr);
    return 0;
}