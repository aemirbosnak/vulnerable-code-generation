//FormAI DATASET v1.0 Category: Queue Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef struct 
{
    int queueArr[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

Queue* createQueue()
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;

    return queue;
}

int isQueueEmpty(Queue* queue)
{
    return queue->front == -1;
}

int isQueueFull(Queue* queue)
{
    return queue->rear == MAX_QUEUE_SIZE - 1;
}

void enqueue(Queue* queue, int item)
{
    if (isQueueFull(queue))
    {
        printf("Oops! Queue is full!\n");
        return;
    }

    if (isQueueEmpty(queue))
    {
        queue->front = 0;
    }

    queue->queueArr[++queue->rear] = item;

    printf("%d was added to the queue!\n", item);
}

void dequeue(Queue* queue)
{
    if (isQueueEmpty(queue))
    {
        printf("Oops! Queue is empty!\n");
        return;
    }

    int item = queue->queueArr[queue->front];

    if (queue->front == queue->rear)
    {
        queue->front = -1;
        queue->rear = -1;
    }
    else
    {
        queue->front++;
    }

    printf("%d was removed out of the queue!\n", item);
}

void printQueue(Queue* queue)
{
    if (isQueueEmpty(queue))
    {
        printf("Oops! Queue is empty!\n");
        return;
    }

    printf("Current queue: ");
    
    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("%d ", queue->queueArr[i]);
    }

    printf("\n");
}

int main()
{
    printf("Welcome to the C Queue Implementation program!\n");

    Queue* queue = createQueue();

    printf("Created an empty queue, with the size of %d.\n", MAX_QUEUE_SIZE);

    printQueue(queue);

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    enqueue(queue, 6);

    printQueue(queue);

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    printQueue(queue);

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    printQueue(queue);

    printf("Thanks for using the C Queue Implementation program!\n");

    return 0;
}