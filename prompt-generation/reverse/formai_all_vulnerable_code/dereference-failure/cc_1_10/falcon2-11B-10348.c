//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10

typedef struct _QueueNode
{
    int data;
    struct _QueueNode *next;
} QueueNode;

typedef struct _Queue
{
    QueueNode *front;
    QueueNode *rear;
    int size;
} Queue;

void create_queue(Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

int is_empty(const Queue *q)
{
    return q->size == 0;
}

void enqueue(Queue *q, int data)
{
    QueueNode *new_node = (QueueNode *)malloc(sizeof(QueueNode));
    new_node->data = data;
    new_node->next = NULL;

    if (is_empty(q))
    {
        q->front = new_node;
        q->rear = new_node;
    }
    else
    {
        q->rear->next = new_node;
        q->rear = new_node;
    }

    q->size++;
}

int dequeue(Queue *q)
{
    int data = q->front->data;

    if (q->size == 1)
    {
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
        q->size = 0;
    }
    else
    {
        q->front = q->front->next;
        free(q->rear);
        q->rear = q->front;
        q->size--;
    }

    return data;
}

int peek(const Queue *q)
{
    return q->front->data;
}

int get_size(const Queue *q)
{
    return q->size;
}

int main()
{
    Queue q;
    create_queue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Front: %d\n", peek(&q));
    printf("Rear: %d\n", dequeue(&q));
    printf("Front: %d\n", peek(&q));
    printf("Rear: %d\n", dequeue(&q));
    printf("Front: %d\n", peek(&q));
    printf("Rear: %d\n", dequeue(&q));
    printf("Front: %d\n", peek(&q));
    printf("Rear: %d\n", dequeue(&q));

    printf("Size: %d\n", get_size(&q));

    return 0;
}