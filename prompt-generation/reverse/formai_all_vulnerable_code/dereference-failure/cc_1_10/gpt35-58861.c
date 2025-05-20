//FormAI DATASET v1.0 Category: Queue Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

// Struct to hold the queue
typedef struct
{
    int front;
    int rear;
    int items[QUEUE_SIZE];
} Queue;


// Function to check if the queue is full
int isFull(Queue *q)
{
    return q->rear == QUEUE_SIZE - 1;
}

// Function to check if the queue is empty
int isEmpty(Queue *q)
{
    return q->rear == q->front;
}

// Function to add items to the queue
void enqueue(Queue *q, int item)
{
    if (isFull(q))
    {
        printf("Queue is full\n");
    }
    else
    {
        q->rear++;
        q->items[q->rear] = item;
        printf("Enqueued %d\n", item);
    }
}

// Function to remove items from the queue
int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        q->front++;
        int item = q->items[q->front];
        printf("Dequeued %d\n", item);
        return item;
    }
}

int main()
{
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;

    // Enqueue some items
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);

    // Dequeue an item
    dequeue(q);

    // Enqueue some more items
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 7);
    enqueue(q, 8);
    enqueue(q, 9);
    enqueue(q, 10);

    // Try to enqueue when the queue is full
    enqueue(q, 11);

    // Dequeue all items
    while (!isEmpty(q))
    {
        dequeue(q);
    }

    // Try to dequeue when the queue is empty
    dequeue(q);

    free(q);

    return 0;
}