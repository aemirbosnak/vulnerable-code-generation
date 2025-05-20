//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int front;
    int rear;
    int *arr;
} queue;

queue create_queue(int size) {
    queue q;
    q.size = size;
    q.front = 0;
    q.rear = -1;
    q.arr = (int *)malloc(size * sizeof(int));
    return q;
}

void enqueue(queue *q, int val) {
    if (q->rear == q->size - 1) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->arr[q->rear] = val;
}

int dequeue(queue *q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int val = q->arr[q->front];
    q->front++;
    if (q->front == q->size) {
        q->front = 0;
    }
    return val;
}

int main() {
    queue q = create_queue(10);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    printf("Front: %d, Rear: %d\n", q.front, q.rear);
    int val = dequeue(&q);
    printf("Dequeued: %d\n", val);
    val = dequeue(&q);
    printf("Dequeued: %d\n", val);
    val = dequeue(&q);
    printf("Dequeued: %d\n", val);
    val = dequeue(&q);
    printf("Dequeued: %d\n", val);
    val = dequeue(&q);
    printf("Dequeued: %d\n", val);
    val = dequeue(&q);
    printf("Dequeued: %d\n", val);
    val = dequeue(&q);
    printf("Dequeued: %d\n", val);
    val = dequeue(&q);
    printf("Dequeued: %d\n", val);
    val = dequeue(&q);
    printf("Dequeued: %d\n", val);
    return 0;
}