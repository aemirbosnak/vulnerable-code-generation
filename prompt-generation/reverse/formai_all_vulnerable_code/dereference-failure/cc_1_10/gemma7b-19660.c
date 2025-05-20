//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

struct Queue
{
    Node* head;
    Node* tail;
    int size;
};

void initializeQueue(struct Queue* queue)
{
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
}

void enqueue(struct Queue* queue, int data)
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
}

int dequeue(struct Queue* queue)
{
    if (queue->head == NULL)
    {
        return -1;
    }

    int data = queue->head->data;
    queue->head = queue->head->next;
    queue->size--;

    return data;
}

int main()
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    initializeQueue(queue);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    printf("Elements in the queue:");
    for (int i = 0; i < queue->size; i++)
    {
        printf(" %d", dequeue(queue));
    }

    printf("\n");

    return 0;
}