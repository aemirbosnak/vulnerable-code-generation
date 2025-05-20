//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Node
{
    int data;
    struct Node* next;
};

struct Queue
{
    struct Node* front;
    struct Node* rear;
};

void enqueue(struct Queue* queue, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
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

int dequeue(struct Queue* queue)
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
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    int data = dequeue(queue);
    printf("Dequed data: %d\n", data);

    data = dequeue(queue);
    printf("Dequed data: %d\n", data);

    data = dequeue(queue);
    printf("Dequed data: %d\n", data);

    data = dequeue(queue);
    printf("Dequed data: %d\n", data);

    return 0;
}