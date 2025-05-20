//FormAI DATASET v1.0 Category: Queue Implementation ; Style: random
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10
#define TRUE 1
#define FALSE 0

// Queue Structure
typedef struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Queue functions
Queue *createQueue() {
    Queue *q = malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(Queue *q) {
    if(q->rear == -1) 
        return TRUE;
    else 
        return FALSE;
}

void enQueue(Queue *q, int value) {
    if(q->rear == MAX_SIZE-1)
        printf("Queue is full\n");
    else {
        if(q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
        printf("Inserted %d into queue\n", value);
    }
}

int deQueue(Queue *q) {
    int item;
    if(isEmpty(q)) {
        printf("Queue is empty\n");
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

void printQueue(Queue *q) {
    int i;
    if (isEmpty(q))
        printf("Queue is empty\n");
    else {
        printf("Queue contains: ");
        for (i = q->front; i < q->rear+1; i++)
            printf("%d ", q->items[i]);
        printf("\n");
    }
}

// Main function
int main() {
    Queue*q = createQueue();
    
    printf("Welcome to C Queue Implementation Program!\n");
    
    enQueue(q, 10);
    enQueue(q, 20);
    enQueue(q, 30);
    
    printQueue(q);
    
    deQueue(q);
    
    printQueue(q);
    
    enQueue(q, 40);
    
    printQueue(q);
    
    return 0;
}