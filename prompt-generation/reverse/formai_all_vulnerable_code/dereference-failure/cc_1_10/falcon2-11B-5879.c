//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a queue
struct queue
{
    int *elements;
    int front, rear;
};

// Function to initialize a queue
void initQueue(struct queue *q, int size)
{
    q->elements = (int *)malloc(size * sizeof(int));
    q->front = -1;
    q->rear = -1;
}

// Function to insert an element at the rear of the queue
void enQueue(struct queue *q, int value)
{
    if (q->rear == q->front)
    {
        fprintf(stderr, "Queue is full\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        q->rear++;
        q->elements[q->rear] = value;
    }
}

// Function to delete an element at the front of the queue
int deQueue(struct queue *q)
{
    if (q->front == q->rear)
    {
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        int value = q->elements[q->front];
        q->front++;
        return value;
    }
}

// Function to check if the queue is empty
int isQueueEmpty(struct queue *q)
{
    return (q->front == -1 && q->rear == -1);
}

int main()
{
    struct queue q;
    initQueue(&q, 10);

    enQueue(&q, 5);
    enQueue(&q, 7);
    enQueue(&q, 2);

    printf("Front element: %d\n", deQueue(&q));
    printf("Rear element: %d\n", deQueue(&q));
    printf("Front element: %d\n", deQueue(&q));

    printf("Queue is empty: %s\n", isQueueEmpty(&q)? "Yes" : "No");

    return 0;
}