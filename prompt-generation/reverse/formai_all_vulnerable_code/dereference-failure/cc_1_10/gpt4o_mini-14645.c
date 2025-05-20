//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Queue {
    int items[MAX];
    int front;
    int rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isFull(struct Queue* q) {
    return (q->rear == MAX - 1);
}

int isEmpty(struct Queue* q) {
    return (q->front == -1 || q->front > q->rear);
}

void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d\n", value);
        return;
    }
    if (q->front == -1) {
        q->front = 0; // First element
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("%d enqueued to queue\n", value);
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Indicating failure
    }
    int dequeuedValue = q->items[q->front];
    q->front++;
    if (q->front > q->rear) { // Reset if queue is empty after dequeue
        q->front = q->rear = -1;
    }
    printf("%d dequeued from queue\n", dequeuedValue);
    return dequeuedValue;
}

int peek(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Nothing to peek.\n");
        return -1;
    }
    return q->items[q->front];
}

void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Nothing to display.\n");
        return;
    }
    printf("Queue items: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

void freeQueue(struct Queue* q) {
    free(q);
}

int main() {
    struct Queue* q = createQueue();
    
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    
    display(q);

    printf("Front item is %d\n", peek(q));

    dequeue(q);
    display(q);

    enqueue(q, 40);
    dequeue(q);
    display(q);
    
    enqueue(q, 50);
    enqueue(q, 60);
    enqueue(q, 70);
    enqueue(q, 80);
    
    display(q);
    
    while(!isEmpty(q)) {
        dequeue(q);
    }
    
    display(q);
    
    freeQueue(q);
    
    return 0;
}