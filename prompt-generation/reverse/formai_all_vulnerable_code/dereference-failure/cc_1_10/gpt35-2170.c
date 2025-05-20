//FormAI DATASET v1.0 Category: Queue Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>

typedef struct queue_node
{
    int data;
    struct queue_node *next;
} QueueNode;

typedef struct queue
{
    QueueNode *front;
    QueueNode *rear;
} Queue;

Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int isEmpty(Queue *queue)
{
    return queue->front == NULL || queue->rear == NULL;
}

void enqueue(Queue *queue, int data)
{
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    if(isEmpty(queue))
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

int dequeue(Queue *queue)
{
    if(isEmpty(queue))
    {
        printf("Queue is empty!\n");
        return -1;
    }

    QueueNode *temp = queue->front;
    int data = temp->data;

    if(queue->front == queue->rear)
    {
        queue->front = NULL;
        queue->rear = NULL;
    }
    else
    {
        queue->front = queue->front->next;
    }

    free(temp);
    return data;
}

void printQueue(Queue *queue)
{
    if(isEmpty(queue))
    {
        printf("Queue is empty!\n");
        return;
    }

    QueueNode *current = queue->front;
    printf("Queue: ");

    while(current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main()
{
    Queue *queue = createQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    printQueue(queue);

    dequeue(queue);
    printQueue(queue);

    enqueue(queue, 4);
    printQueue(queue);

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    printQueue(queue);

    return 0;
}