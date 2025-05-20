//FormAI DATASET v1.0 Category: Queue Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct Queue {
    int arr[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

Queue *new_queue() {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;

    return q;
}

int is_empty(Queue *q) {
    if(q->front == -1)
        return 1;
    else
        return 0;
}

int is_full(Queue *q) {
    if(q->rear == MAX_QUEUE_SIZE - 1)
        return 1;
    else
        return 0;
}

void enqueue(Queue *q, int data) {
    if(is_full(q)) {
        printf("Queue is full!\n");
    } else {
        if(q->front == -1 && q->rear == -1)
            q->front++;

        q->rear++;
        q->arr[q->rear] = data;
    }
}

int dequeue(Queue *q) {
    int data = 0;
    if(is_empty(q)) {
        printf("Queue is empty!\n");
    } else {
        data = q->arr[q->front];
        q->front++;

        if(q->front > q->rear) {
            q->front = -1;
            q->rear = -1;
        }
    }

    return data;
}

int main() {
    Queue *q = new_queue();

    //Enqueue some data
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    //Dequeue some data
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));

    //Enqueue some more data
    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 60);

    //Dequeue some more data
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));

    //Test empty queue
    dequeue(q);
    return 0;
}