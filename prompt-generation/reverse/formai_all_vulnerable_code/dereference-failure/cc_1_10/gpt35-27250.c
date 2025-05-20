//FormAI DATASET v1.0 Category: Queue Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
typedef struct
{
    int front, rear;
    int capacity;
    int* array;
} Queue;

Queue* createQueue(int size)
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = size;
    queue->front = -1;
    queue->rear = -1;
    queue->array = (int*)malloc(sizeof(int) * size);
    return queue;
}

int isFull(Queue* queue)
{
    return queue->rear == queue->capacity - 1;
}

int isEmpty(Queue* queue)
{
    return queue->front == -1 && queue->rear == -1;
}

void enqueue(Queue* queue, int item)
{
    if (isFull(queue))
    {
        printf("Queue is Full!\n");
        return;
    }
    else if (isEmpty(queue))
    {
        queue->front = 0;
        queue->rear = 0;
    }
    else
    {
        queue->rear += 1;
    }
    queue->array[queue->rear] = item;
}

int dequeue(Queue* queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is Empty!\n");
        return -1;
    }
    else if (queue->front == queue->rear)
    {
        int element = queue->array[queue->front];
        queue->front = -1;
        queue->rear = -1;
        return element;
    }
    else
    {
        int element = queue->array[queue->front];
        queue->front += 1;
        return element;
    }
}

void printQueue(Queue* queue)
{
    int i;
    printf("[");
    for (i = queue->front; i <= queue->rear; i++)
    {
        printf("%d ", queue->array[i]);
    }
    printf("]\n");
}

int main()
{
    Queue* queue = createQueue(MAXSIZE);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    printf("Queue: ");
    printQueue(queue);
    dequeue(queue);
    printf("Queue after dequeue: ");
    printQueue(queue);
    enqueue(queue, 6);
    printf("Queue after enqueue: ");
    printQueue(queue);
    return 0;
}