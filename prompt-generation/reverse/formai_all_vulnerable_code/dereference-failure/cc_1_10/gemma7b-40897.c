//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

typedef struct Queue
{
    Node* front;
    Node* rear;
} Queue;

void enqueue(Queue* queue, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->front == NULL)
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(Queue* queue)
{
    if (queue->front == NULL)
    {
        return -1;
    }

    int data = queue->front->data;
    queue->front = queue->front->next;

    return data;
}

int main()
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    printf("Enqueued data:");
    for (Node* node = queue->front; node; node = node->next)
    {
        printf(" %d", node->data);
    }

    printf("\n");

    printf("Dequeued data:");
    for (int i = 0; i < 3; i++)
    {
        int data = dequeue(queue);
        if (data != -1)
        {
            printf(" %d", data);
        }
    }

    printf("\n");

    printf("Enqueued data after dequeue:");
    for (Node* node = queue->front; node; node = node->next)
    {
        printf(" %d", node->data);
    }

    return 0;
}