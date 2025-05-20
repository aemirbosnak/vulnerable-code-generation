//FormAI DATASET v1.0 Category: Queue Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // maximum size of the queue

typedef struct {
    int *arr;
    int front;
    int rear;
} Queue;

// function to initialize the queue
void initQueue(Queue *q) {
    q->arr = (int*) malloc(MAX_SIZE * sizeof(int));
    q->front = -1;
    q->rear = -1;
}

// function to check if the queue is empty
int isEmpty(Queue *q) {
    return (q->front == -1 && q->rear == -1);
}

// function to check if the queue is full
int isFull(Queue *q) {
    return ((q->rear+1)%MAX_SIZE == q->front);
}

// function to add an element to the queue
void enqueue(Queue *q, int x) {
    if (isFull(q)) {
        printf("Queue is full. Cannot add element.\n");
        return;
    } else if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear+1)%MAX_SIZE;
    }
    q->arr[q->rear] = x;
    printf("Element %d added to the queue.\n", x);
}

// function to remove an element from the queue
void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot remove element.\n");
        return;
    } else if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front+1)%MAX_SIZE;
    }
    printf("Element removed from the queue.\n");
}

// function to display the current elements in the queue
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Elements in queue: ");
    for (int i = q->front; i != q->rear; i = (i+1)%MAX_SIZE) {
        printf("%d ", q->arr[i]);
    }
    printf("%d\n", q->arr[q->rear]);
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);

    return 0;
}