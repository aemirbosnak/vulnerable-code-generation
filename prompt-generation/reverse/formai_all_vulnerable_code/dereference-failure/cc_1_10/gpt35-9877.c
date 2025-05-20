//FormAI DATASET v1.0 Category: Queue Implementation ; Style: decentralized
/*
 * Decentralized implementation of Queue using C language
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Queue
{
    int items[MAX];
    int front;
    int rear;
};

typedef struct Queue queue;

// Function to create an empty queue
queue* createQueue()
{
    queue* q = (queue*)malloc(sizeof(queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Function to check if the queue is full
int isFull(queue* q)
{
    if(q->rear == MAX-1)
        return 1;
    return 0;
}

// Function to check if the queue is empty
int isEmpty(queue* q)
{
    if(q->front == -1)
        return 1;
    return 0;
}

// Function to add an element to the queue
void enqueue(queue* q, int value)
{
    if(isFull(q))
    {
        printf("Queue is full \n");
    }
    else
    {
        if(q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
        printf("Inserted -> %d\n", value);
    }
}

// Function to remove an element from the queue
int dequeue(queue* q)
{
    int item;
    if(isEmpty(q))
    {
        printf("Queue is empty \n");
        item = -1;
    }
    else
    {
        item = q->items[q->front];
        q->front++;
        if(q->front > q->rear)
        {
            printf("Queue is empty\n");
            q->front = q->rear = -1;
        }
    }
    return item;
}

// Function to print the queue
void printQueue(queue *q) {
    int i = q->front;
    if(isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue contains:\n");
        for(i = q->front; i < q->rear + 1; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

int main() {
    // Create a queue
    queue* q = createQueue();

    // Add elements to the queue
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);

    // Print the queue
    printQueue(q);

    // Remove elements from the queue
    printf("Removed from queue -> %d\n", dequeue(q));
    printf("Removed from queue -> %d\n", dequeue(q));

    // Print the queue
    printQueue(q);

    return 0;
}