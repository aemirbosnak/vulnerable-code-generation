//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: secure
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
    Node* head;
    Node* tail;
    int size;
} Queue;

Queue* createQueue(int size)
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = size;
    return queue;
}

int enqueue(Queue* queue, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->head == NULL)
    {
        queue->head = newNode;
        queue->tail = newNode;
    }
    else
    {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }

    queue->size++;

    return 0;
}

int dequeue(Queue* queue)
{
    if (queue->head == NULL)
    {
        return -1;
    }

    Node* tempNode = queue->head;
    queue->head = queue->head->next;

    free(tempNode);
    queue->size--;

    return 0;
}

int main()
{
    Queue* queue = createQueue(MAX_SIZE);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    dequeue(queue);
    dequeue(queue);

    printf("The elements of the queue are:");
    for (Node* node = queue->head; node; node = node->next)
    {
        printf(" %d", node->data);
    }

    return 0;
}