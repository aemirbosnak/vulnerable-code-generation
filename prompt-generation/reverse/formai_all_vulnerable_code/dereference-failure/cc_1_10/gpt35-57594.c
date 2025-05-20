//FormAI DATASET v1.0 Category: Queue Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef struct {
    int front, rear;
    int queue[MAX_QUEUE_SIZE];
} Queue;

void initialize(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q) {
    if (q->front == 0 && q->rear == MAX_QUEUE_SIZE - 1) {
        return 1;
    }
    if (q->front == q->rear + 1) {
        return 1;
    }
    return 0;
}

int isEmpty(Queue *q) {
    if (q->front == -1) {
        return 1;
    }
    return 0;
}

void enqueue(Queue *q, int item) {
    if (isFull(q)) {
        printf("Queue is full\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
        q->queue[q->rear] = item;
        printf("%d added to the queue\n", item);
    }
}

void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("%d removed from the queue\n", q->queue[q->front]);
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX_QUEUE_SIZE;
        }
    }
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        int i;
        printf("Queue: ");
        for (i = q->front; i != q->rear; i = (i + 1) % MAX_QUEUE_SIZE) {
            printf("%d ", q->queue[i]);
        }
        printf("%d\n", q->queue[i]);
    }
}

int main() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    initialize(q);
    
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    dequeue(q);
    dequeue(q);
    display(q);
    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 60);
    display(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    display(q);
    
    free(q);
    return 0;
}