//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue {
    int* items;
    int front;
    int rear;
    int size;
} queue_t;

void init_queue(queue_t* q) {
    q->items = NULL;
    q->front = -1;
    q->rear = -1;
    q->size = 0;
}

void push(queue_t* q, int item) {
    q->items = realloc(q->items, (q->size + 1) * sizeof(int));
    if (q->front == -1) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % q->size;
    }
    q->items[q->rear] = item;
}

int pop(queue_t* q) {
    if (q->front == -1) {
        return -1;
    }
    int item = q->items[q->front];
    q->front = (q->front + 1) % q->size;
    return item;
}

void enqueue(queue_t* q, int item) {
    push(q, item);
}

int dequeue(queue_t* q) {
    return pop(q);
}

int main() {
    queue_t q;
    init_queue(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printf("Front: %d\n", dequeue(&q));
    printf("Rear: %d\n", dequeue(&q));
    printf("Rear: %d\n", dequeue(&q));
    printf("Front: %d\n", dequeue(&q));
    return 0;
}