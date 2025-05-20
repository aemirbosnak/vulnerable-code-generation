//FormAI DATASET v1.0 Category: Queue Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

// The structure of the queue
typedef struct Queue
{
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
Queue* initQueue()
{
    Queue* newQueue = (Queue*) malloc(sizeof(Queue));
    newQueue->front = -1;
    newQueue->rear = -1;
    return newQueue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue)
{
    if (queue->rear == -1)
        return 1;
    else
        return 0;
}

// Function to check if the queue is full
int isFull(Queue* queue)
{
    if (queue->rear == MAX_QUEUE_SIZE - 1)
        return 1;
    else
        return 0;
}

// Function to add an element to the queue
void enqueue(Queue* queue, int item)
{
    if (isFull(queue))
        printf("Queue is full!");
    else
    {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->items[queue->rear] = item;
        printf("Element added to queue!");
    }
}

// Function to remove an element from the queue
void dequeue(Queue* queue)
{
    if (isEmpty(queue))
        printf("Queue is empty!");
    else
    {
        printf("Dequeued element: %d", queue->items[queue->front]);
        queue->front++;
        if (queue->front > queue->rear)
            queue->front = queue->rear = -1;
    }
}

// Function to display the queue
void display(Queue* queue)
{
    if (isEmpty(queue))
        printf("Queue is empty!");
    else
    {
        printf("Elements in queue are: ");
        for (int i = queue->front; i <= queue->rear; i++)
            printf("%d ", queue->items[i]);
    }
}

int main()
{
    Queue* q = initQueue();

    printf("\n*********************************************");
    printf("\n*                                           *");
    printf("\n*           Welcome to my Queue!             *");
    printf("\n*                                           *");
    printf("\n*********************************************\n\n");

    printf("Add elements to the queue:\n");
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);
    display(q);

    printf("\n\nRemove an element from the queue:\n");
    dequeue(q);
    display(q);

    printf("\n\nAdd an element to the queue:\n");
    enqueue(q, 7);
    display(q);

    printf("\n\nAll operations on the queue are completed!");

    return 0;
}