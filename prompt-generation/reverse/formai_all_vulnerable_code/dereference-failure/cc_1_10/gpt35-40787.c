//FormAI DATASET v1.0 Category: Queue ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef struct queue {
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
}Queue;

void enqueue(Queue *q, int value) {
    if (q->rear == MAX_QUEUE_SIZE) {
        printf("Queue is full");
    } else {
        q->items[q->rear] = value;
        q->rear++;
        printf("Enqueued %d\n", value);
    }
}

int dequeue(Queue *q) {
    if (q->front == q->rear) {
        printf("Queue is empty");
        return -1;
    } else {
        int item = q->items[q->front];
        q->front++;
        printf("Dequeued %d\n", item);
        return item;
    }
}

void display(Queue *q) {
    if (q->front == q->rear) {
        printf("Queue is empty");
    } else {
        printf("Queue contains: ");
        for (int i = q->front; i < q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue *q = (Queue*) malloc(sizeof(Queue));
    q->front = 0;
    q->rear = 0;

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 60);
    display(q);

    dequeue(q);
    dequeue(q);
    dequeue(q);
    display(q);

    return 0;
}