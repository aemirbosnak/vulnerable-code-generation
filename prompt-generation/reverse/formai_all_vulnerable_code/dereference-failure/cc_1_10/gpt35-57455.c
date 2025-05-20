//FormAI DATASET v1.0 Category: Queue Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct Queue Queue;

struct Queue {
    int items[MAX_QUEUE_SIZE];
    int front, rear;
};

Queue* create_queue() {
    Queue* q = malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("Inserted %d in queue\n", value);
}

void dequeue(Queue* q) {
    if (q->front == -1) {
        printf("Queue underflow\n");
        return;
    }
    printf("Removed %d from queue\n", q->items[q->front]);
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
}

void print_queue(Queue* q) {
    int i = q->front;
    if (q->front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements:\n");
    for (i = q->front; i <= q->rear; i++) {
        printf("%d\n", q->items[i]);
    }
}

int main() {
    Queue* q = create_queue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    print_queue(q);

    dequeue(q);
    print_queue(q);

    dequeue(q);
    print_queue(q);

    enqueue(q, 40);
    print_queue(q);


    return 0;
}