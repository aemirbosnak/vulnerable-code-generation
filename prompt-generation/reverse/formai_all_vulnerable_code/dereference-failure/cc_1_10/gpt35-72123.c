//FormAI DATASET v1.0 Category: Queue Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
// Define a structure to represent a queue
typedef struct queue {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function declarations
void initQueue(Queue *q);
void enQueue(Queue *q, int value);
int deQueue(Queue *q);
void display(Queue *q);

int main() {
    Queue *q = (Queue*) malloc(sizeof(Queue));
    initQueue(q);
    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);
    enQueue(q, 4);
    enQueue(q, 5);
    printf("Queue elements:\n");
    display(q);
    printf("Item dequeued: %d\n", deQueue(q));
    printf("Item dequeued: %d\n", deQueue(q));
    printf("Queue elements after dequeue operation:\n");
    display(q);
    return 0;
}

// Function to initialize the queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to add an element to the queue
void enQueue(Queue *q, int value) {
    if (q->rear == MAX_SIZE - 1)
        printf("Queue overflow!\n");
    else {
        if (q->front == -1) 
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
        printf("Element added to the queue: %d\n", value);
    }
}

// Function to remove an element from the queue
int deQueue(Queue *q) {
    int item;
    if (q->front == -1)
        printf("Queue underflow!\n");
    else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) 
            q->front = q->rear = -1;
        return item;
    }
}

// Function to display the elements in the queue
void display(Queue *q) {
    if (q->rear == -1)
        printf("Queue is empty!\n");
    else {
        for (int i = q->front; i <= q->rear; i++) 
            printf("%d ", q->items[i]);
        printf("\n");
    }
}