//FormAI DATASET v1.0 Category: Queue Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int arr[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    return q;
}

int isFull(Queue* q) {
    return q->rear == MAX_SIZE-1;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enQueue(Queue* q, int val) {
    if(isFull(q)) {
        printf("\nError: Queue is Full\n");
        return;
    }
    
    if(q->front == -1) {
        q->front = 0;
    }
    
    q->rear++;
    q->arr[q->rear] = val;
    q->size++;
}

int deQueue(Queue* q) {
    if(isEmpty(q)) {
        printf("\nError: Queue is Empty\n");
        return -1;
    }
    
    int val = q->arr[q->front];
    
    if(q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    
    q->size--;
    
    return val;
}

int main() {
    Queue* q = createQueue();
    
    enQueue(q, 10);
    enQueue(q, 20);
    enQueue(q, 30);
    
    printf("Queue Front: %d\n", q->arr[q->front]);
    printf("Queue Rear: %d\n", q->arr[q->rear]);
    
    printf("Dequeued element: %d\n", deQueue(q));
    printf("Dequeued element: %d\n", deQueue(q));
    
    printf("Queue Front: %d\n", q->arr[q->front]);
    printf("Queue Rear: %d\n", q->arr[q->rear]);
    
    enQueue(q, 40);
    
    printf("Queue Front: %d\n", q->arr[q->front]);
    printf("Queue Rear: %d\n", q->arr[q->rear]);
    
    return 0;
}