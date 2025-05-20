//FormAI DATASET v1.0 Category: Queue Implementation ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 1000

struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue* queue)
{
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue* queue)
{
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue))
    {
        printf("Error: Queue is Full\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
    {
        printf("Error: Queue is Empty\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int front(struct Queue* queue)
{
    if (isEmpty(queue))
    {
        printf("Error: Queue is Empty\n");
        return -1;
    }
    return queue->array[queue->front];
}

int rear(struct Queue* queue)
{
    if (isEmpty(queue))
    {
        printf("Error: Queue is Empty\n");
        return -1;
    }
    return queue->array[queue->rear];
}

int main()
{
    struct Queue* q = createQueue(MAX_SIZE);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    printf("Front element is %d\n", front(q));
    printf("Rear element is %d\n", rear(q));

    printf("Dequeued item is %d\n", dequeue(q));
    printf("Dequeued item is %d\n", dequeue(q));
    printf("Dequeued item is %d\n", dequeue(q));

    printf("Front element is %d\n", front(q));
    printf("Rear element is %d\n", rear(q));

    return 0;
}