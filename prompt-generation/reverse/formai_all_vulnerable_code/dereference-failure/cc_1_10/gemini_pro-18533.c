//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: genius
#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int front, rear;
    int capacity;
    int *array;
};

// create a queue of given capacity
struct Queue *createQueue(int capacity)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = queue->rear = -1;
    queue->capacity = capacity;
    queue->array = (int *)malloc(queue->capacity * sizeof(int));
    return queue;
}

// check if the queue is full
int isFull(struct Queue *queue)
{
    return (queue->rear == queue->capacity - 1);
}

// check if the queue is empty
int isEmpty(struct Queue *queue)
{
    return (queue->front == -1);
}

// add an element to the queue
void enQueue(struct Queue *queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear++;
    queue->array[queue->rear] = item;
    if (queue->front == -1)
        queue->front = queue->rear;
}

// remove an element from the queue
int deQueue(struct Queue *queue)
{
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front++;
    if (queue->front > queue->rear)
        queue->front = queue->rear = -1;
    return item;
}

// print the queue
void printQueue(struct Queue *queue)
{
    if (isEmpty(queue)) {
        printf("Queue is empty.");
        return;
    }
    for (int i = queue->front; i <= queue->rear; i++)
        printf("%d ", queue->array[i]);
}

// driver program to test the queue
int main()
{
    struct Queue *queue = createQueue(10);

    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    enQueue(queue, 4);
    enQueue(queue, 5);

    printQueue(queue);

    deQueue(queue);
    deQueue(queue);

    printQueue(queue);

    return 0;
}