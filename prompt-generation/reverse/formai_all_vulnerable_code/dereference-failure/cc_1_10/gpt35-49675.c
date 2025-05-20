//FormAI DATASET v1.0 Category: Queue Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct queue {
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

Queue* createQueue() {
    Queue* q = malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isFull(Queue* q) {
    if(q->rear == MAX_QUEUE_SIZE-1) return 1;
    return 0;
}

int isEmpty(Queue* q) {
    if(q->front == -1) return 1;
    return 0;
}

void enqueue(Queue* q, int item) {
    if(isFull(q)) {
        printf("Queue is full!");
        return;
    }
    if(q->front == -1) q->front = 0;
    q->rear++;
    q->items[q->rear] = item;
}

int dequeue(Queue* q) {
    int item;
    if(isEmpty(q)) {
        printf("Queue is empty!");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if(q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

void printQueue(Queue* q) {
    int i = q->front;
    if(isEmpty(q)) {
        printf("Queue is empty!");
    } else {
        printf("Queue contains: ");
        for(i = q->front; i < q->rear + 1; i++) {
            printf("%d ", q->items[i]);
        }
    }
    printf("\n");
}

int main() {
    Queue* myQueue = createQueue();

    // Add items to the queue
    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);
    enqueue(myQueue, 40);
    enqueue(myQueue, 50);

    // Print the queue
    printQueue(myQueue);

    // Remove items from the queue
    printf("Removed item: %d\n", dequeue(myQueue));
    printf("Removed item: %d\n", dequeue(myQueue));

    // Print the queue after removing items
    printQueue(myQueue);

    return 0;
}