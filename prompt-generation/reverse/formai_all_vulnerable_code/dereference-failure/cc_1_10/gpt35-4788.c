//FormAI DATASET v1.0 Category: Queue Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct Queue {
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

// Function prototypes
Queue* create_queue();
void enqueue(Queue *q, int item);
int dequeue(Queue *q);
void display(Queue *q);

int main() {
    Queue *q = create_queue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 7);
    enqueue(q, 8);
    enqueue(q, 9);
    enqueue(q, 10);

    printf("Queue full: [%d]\n", q->rear == MAX_QUEUE_SIZE - 1);

    // Try to insert 11th element
    enqueue(q, 11);

    display(q);

    printf("Queue empty: [%d]\n", q->front == -1);

    // Remove an item
    dequeue(q);

    display(q);

    // Add an item
    enqueue(q, 11);

    display(q);

    printf("Queue full: [%d]\n", q->rear == MAX_QUEUE_SIZE - 1);

    return 0;
}

Queue* create_queue() {
    Queue *q = malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

void enqueue(Queue *q, int item) {
    if (q->rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = item;
    printf("Enqueued element: %d\n", item);
}

int dequeue(Queue *q) {
    int item;
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue Underflow\n");
        exit(1);
    } else {
        item = q->items[q->front];
        q->front++;
        printf("Dequeued element: %d\n", item);
        return item;
    }
}

void display(Queue *q) {
    int i;
    if (q->rear == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}