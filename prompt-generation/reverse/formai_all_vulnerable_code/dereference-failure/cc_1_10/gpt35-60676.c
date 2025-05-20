//FormAI DATASET v1.0 Category: Queue Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct queue {
    int front, rear;
    int size;
    int arr[MAX_QUEUE_SIZE];
} queue;

queue* new_queue() {
    queue* q = (queue*) malloc(sizeof(queue));
    q->front = q->rear = -1;
    q->size = 0;
    return q;
}

int is_empty(queue* q) {
    return q->front == -1 && q->rear == -1;
}

int is_full(queue* q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void enqueue(queue* q, int val) {
    if(is_full(q)) {
        printf("Queue is full!\n");
        return;
    }
    if(is_empty(q)) q->front = q->rear = 0;
    else q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->arr[q->rear] = val;
    q->size++;
}

int dequeue(queue* q) {
    if(is_empty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int val = q->arr[q->front];
    if(q->front == q->rear) q->front = q->rear = -1;
    else q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    q->size--;
    return val;
}

int peek(queue* q) {
    if(is_empty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->arr[q->front];
}

int main() {
    queue* q = new_queue();
    enqueue(q, 10);
    enqueue(q, 20);
    printf("Front element: %d\n", peek(q));
    printf("Dequeued: %d\n", dequeue(q));
    printf("Front element: %d\n", peek(q));
    enqueue(q, 30);
    printf("Front element: %d\n", peek(q));
    printf("Dequeued: %d\n", dequeue(q));
    printf("Front element: %d\n", peek(q));
    printf("Size: %d\n", q->size);
    return 0;
}