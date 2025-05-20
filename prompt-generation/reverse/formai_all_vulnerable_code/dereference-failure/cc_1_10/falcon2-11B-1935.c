//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct queue_node
{
    int data;
    struct queue_node *next;
} queue_node;

typedef struct queue
{
    queue_node *front;
    queue_node *rear;
} queue;

queue *createQueue()
{
    queue *newQueue = (queue *)malloc(sizeof(queue));
    if(newQueue == NULL)
    {
        printf("Error in creating the queue");
        return NULL;
    }
    newQueue->front = NULL;
    newQueue->rear = NULL;
    return newQueue;
}

int isQueueEmpty(queue *q)
{
    if(q->front == NULL && q->rear == NULL)
    {
        return 1;
    }
    return 0;
}

int enQueue(queue *q, int data)
{
    queue_node *newNode = (queue_node *)malloc(sizeof(queue_node));
    if(newNode == NULL)
    {
        printf("Error in allocating memory for new node");
        return -1;
    }
    newNode->data = data;
    newNode->next = NULL;
    if(isQueueEmpty(q))
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    return 0;
}

int deQueue(queue *q)
{
    if(isQueueEmpty(q))
    {
        printf("Queue is empty");
        return -1;
    }
    queue_node *temp = q->front;
    q->front = q->front->next;
    free(temp);
    return 0;
}

int peek(queue *q)
{
    if(isQueueEmpty(q))
    {
        printf("Queue is empty");
        return -1;
    }
    return q->front->data;
}

int main()
{
    queue *q = createQueue();
    enQueue(q, 10);
    enQueue(q, 20);
    enQueue(q, 30);
    printf("%d\n", peek(q));
    deQueue(q);
    deQueue(q);
    deQueue(q);
    printf("%d\n", peek(q));
    return 0;
}