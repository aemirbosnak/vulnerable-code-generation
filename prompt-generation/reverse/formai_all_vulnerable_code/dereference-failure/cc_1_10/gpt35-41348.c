//FormAI DATASET v1.0 Category: Queue ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10 // Maximum size of the queue

// Definition of the Queue data structure
typedef struct queue {
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

void enqueue(Queue* q, int item) {
    if(q->rear == MAX_QUEUE_SIZE-1) {
        printf("Queue Overflow!\n");
        return;
    }
    if(q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = item;
    printf("Enqueued %d\n", item);
}

int dequeue(Queue* q) {
    if(q->front == -1) {
        printf("Queue Underflow!\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if(q->front > q->rear) {
        q->front = q->rear = -1;
    }
    printf("Dequeued %d\n", item);
    return item;
}

void displayQueue(Queue* q) {
    if(q->front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements are:\n");
    for(int i=q->front; i<=q->rear; i++) {
        printf("%d\n", q->items[i]);
    }
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    displayQueue(q);
    dequeue(q);
    displayQueue(q);
    return 0;
}