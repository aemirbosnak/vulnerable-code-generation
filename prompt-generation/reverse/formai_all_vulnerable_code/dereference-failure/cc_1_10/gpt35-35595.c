//FormAI DATASET v1.0 Category: Queue ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_MAX_SIZE 100

typedef struct queue
{
    int items[QUEUE_MAX_SIZE];
    int front;
    int rear;
} Queue;

Queue* createQueue()
{
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isQueueEmpty(Queue* queue)
{
    return queue->rear == -1;
}

int isQueueFull(Queue* queue)
{
    return queue->rear == QUEUE_MAX_SIZE - 1;
}

void enqueue(Queue* queue, int item)
{
    if (isQueueFull(queue))
    {
        printf("Queue is full!\n");
        return;
    }
    if (queue->front == -1)
    {
        queue->front = 0;
    }
    queue->rear++;
    queue->items[queue->rear] = item;
    printf("%d enqueued successfully!\n", item);
}

int dequeue(Queue* queue)
{
    if (isQueueEmpty(queue))
    {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = queue->items[queue->front];
    queue->front++;
    if (queue->front > queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    printf("%d dequeued successfully!\n", item);
    return item;
}

void printQueue(Queue* queue)
{
    if (isQueueEmpty(queue))
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("%d ", queue->items[i]);
    }
    printf("\n");
}

int main()
{
    Queue* queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    printQueue(queue);
    dequeue(queue);
    printQueue(queue);
    enqueue(queue, 40);
    printQueue(queue);
    return 0;
}