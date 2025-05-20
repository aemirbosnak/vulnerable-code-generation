//FormAI DATASET v1.0 Category: Queue ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Defining the Queue structure
typedef struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function prototypes
void enqueue(Queue* q, int);
int dequeue(Queue* q);
void display(Queue* q);

int main() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);

    int dequeued = dequeue(q);
    printf("Dequeued: %d\n", dequeued);
    display(q);

    free(q);
    return 0;
}

// Function to add an item to the queue
void enqueue(Queue* q, int value) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Queue overflow\n");
        return;
    }

    if (q->front == -1 && q->rear == -1) {
        q->front = q->rear = 0;
        q->items[q->rear] = value;
    } else {
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Function to remove an item from the queue
int dequeue(Queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue underflow\n");
        return -1;
    }

    int dequeued = q->items[q->front];
    q->front++;

    return dequeued;
}

// Function to display the items in the queue
void display(Queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}