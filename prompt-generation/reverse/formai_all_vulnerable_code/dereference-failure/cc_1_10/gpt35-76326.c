//FormAI DATASET v1.0 Category: Queue Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Defining the structure of a queue
typedef struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
Queue* init() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Function to check if the queue is full
int isFull(Queue* q) {
    return (q->rear == MAX_SIZE - 1);
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return (q->rear == -1 && q->front == -1);
}

// Function to add an item to the queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }

    if (isEmpty(q)) {
        q->front = q->rear = 0;
        q->items[0] = value;
    } else {
        q->rear++;
        q->items[q->rear] = value;
    }
    printf("%d enqueued to queue\n", value);
}

// Function to remove an item from the queue
void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("%d dequeued from queue\n", q->items[q->front]);
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
}

// Function to display the queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    Queue* q = init();

    // Inserting elements into the queue
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    // Display the queue
    display(q);

    // Removing elements from the queue
    dequeue(q);
    dequeue(q);

    // Display the queue
    display(q);

    return 0;
}