//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

typedef struct Queue
{
    Node** arr;
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue()
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->arr = (Node**)malloc(MAX * sizeof(Node));
    queue->front = 0;
    queue->rear = -1;
    queue->size = MAX;
    return queue;
}

void enqueue(Queue* queue, int data)
{
    if (queue->rear == queue->size - 1)
    {
        printf("Queue Overflow\n");
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->front == -1)
    {
        queue->front = 0;
    }

    queue->arr[++queue->rear] = newNode;
}

int dequeue(Queue* queue)
{
    if (queue->front == -1)
    {
        printf("Queue Underflow\n");
        return -1;
    }

    int data = queue->arr[queue->front]->data;
    free(queue->arr[queue->front]);
    queue->arr[queue->front] = NULL;
    queue->front++;

    return data;
}

int main()
{
    Queue* queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    printf("Data at the front of the queue: %d\n", dequeue(queue));
    printf("Data at the rear of the queue: %d\n", dequeue(queue));
    printf("Data at the front of the queue: %d\n", dequeue(queue));

    return 0;
}