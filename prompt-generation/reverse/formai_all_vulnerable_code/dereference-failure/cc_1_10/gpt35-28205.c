//FormAI DATASET v1.0 Category: Queue Implementation ; Style: beginner-friendly
// C Queue Implementation

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(Queue* q) {
    if (q->rear == -1) {
        return 1;
    } else {
        return 0;
    }
}

int isFull(Queue* q) {
    if (q->rear == MAX_SIZE-1) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("Inserted %d into the queue!\n", value);
    }
}

int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue contains: ");
        for (int i=q->front; i<=q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue* q = createQueue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);

    display(q);

    printf("Dequeued %d from the queue\n", dequeue(q));
    printf("Dequeued %d from the queue\n", dequeue(q));

    display(q);

    enqueue(q, 5);
    enqueue(q, 6);

    display(q);

    printf("Dequeued %d from the queue\n", dequeue(q));

    display(q);

    return 0;
}