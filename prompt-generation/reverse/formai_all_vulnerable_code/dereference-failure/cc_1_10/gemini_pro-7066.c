//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Queue
{
    int front, rear;
    int size;
    int *arr;
} Queue;

Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->size = MAX_SIZE;
    queue->arr = (int *)malloc(queue->size * sizeof(int));
    return queue;
}

void enqueue(Queue *queue, int data)
{
    if (queue->rear == queue->size - 1)
    {
        printf("Queue is full\n");
        return;
    }
    else
    {
        if (queue->front == -1)
        {
            queue->front = 0;
        }
        queue->rear++;
        queue->arr[queue->rear] = data;
    }
}

int dequeue(Queue *queue)
{
    if (queue->front == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        int data = queue->arr[queue->front];
        queue->front++;
        if (queue->front > queue->rear)
        {
            queue->front = queue->rear = -1;
        }
        return data;
    }
}

void display(Queue *queue)
{
    if (queue->front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    else
    {
        for (int i = queue->front; i <= queue->rear; i++)
        {
            printf("%d ", queue->arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    Queue *queue = createQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    display(queue);

    dequeue(queue);
    dequeue(queue);

    display(queue);

    enqueue(queue, 6);
    enqueue(queue, 7);

    display(queue);

    return 0;
}