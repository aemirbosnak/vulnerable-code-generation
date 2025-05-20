//FormAI DATASET v1.0 Category: Queue Implementation ; Style: peaceful
/* 
A peaceful implementation of Queue in C language.
This program demonstrates the basic functionality of Queue data structure
with dynamic memory allocation & dequeuing elements.
*/

#include <stdio.h>
#include <stdlib.h>

// The structure of a queue
typedef struct queue
{
    int front, rear, size;
    unsigned capacity;
    int* array;
} Queue;

// Create a new queue
Queue* createQueue(unsigned capacity)
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Check if the queue is full
int isFull(Queue* queue)
{
    return (queue->size == queue->capacity);
}

// Check if the queue is empty
int isEmpty(Queue* queue)
{
    return (queue->size == 0);
}

// Enqueue an item to the queue
void enqueue(Queue* queue, int item)
{
    if (isFull(queue))
    {
        printf("Queue is full, cannot enqueue.\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
    printf("%d enqueued to the queue.\n", item);
}

// Dequeue an item from the queue
int dequeue(Queue* queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty, cannot dequeue.\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    printf("%d dequeued from the queue.\n", item);
    return item;
}

// Get the front item of the queue without dequeueing
int front(Queue* queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty, cannot get front item.\n");
        return -1;
    }
    return queue->array[queue->front];
}

// Get the rear item of the queue without dequeueing
int rear(Queue* queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty, cannot get rear item.\n");
        return -1;
    }
    return queue->array[queue->rear];
}

// Test the queue implementation
int main()
{
    Queue* queue = createQueue(5);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    enqueue(queue, 60); // Queue is full
    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));
    enqueue(queue, 60);
    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));
    return 0;
}