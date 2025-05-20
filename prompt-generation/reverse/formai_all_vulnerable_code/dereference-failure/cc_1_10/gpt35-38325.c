//FormAI DATASET v1.0 Category: Queue Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 1000    // Maximum size of queue

// Define Queue structure
typedef struct
{
    int front, rear, size;
    int items[MAX_QUEUE_SIZE];
}Queue;

// Creates a new queue
Queue* createQueue()
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear  = -1;
    queue->size  = 0;
    return queue;
}

// Checks if the queue is full
int isFull(Queue* queue)
{
    if (queue->rear == MAX_QUEUE_SIZE - 1)  // rear reaches maximum size
        return 1;
    else 
        return 0;
}

// Checks if the queue is empty
int isEmpty(Queue* queue)
{
    if (queue->front == -1) // front hasn't moved from initial position
        return 1;
    else
        return 0;
}

// Adds an element to the queue
void enqueue(Queue* queue, int item)
{
    if (isFull(queue))
    {
        printf("Queue is full\n");
        return;
    }

    if (queue->front == -1)  // Empty Queue
        queue->front = 0;

    queue->rear++;
    queue->items[queue->rear] = item;
    queue->size++;
}

// Removes an element from the queue and returns it
int dequeue(Queue* queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return -1;
    }

    int item = queue->items[queue->front];
    queue->front++;
    queue->size--;
    return item;
}

// Returns the front element without removing it
int front(Queue* queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return -1;
    }

    return queue->items[queue->front];
}

// Returns the queue size
int size(Queue* queue)
{
    return queue->size;
}

// Main function to test the Queue implementation
int main()
{
    Queue* queue = createQueue();

    // Add elements to the queue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    // Display the elements of the queue
    printf("Queue Elements: ");
    while (!isEmpty(queue))
    {
        printf("%d ", front(queue));
        dequeue(queue);
    }

    printf("\nQueue size after dequeue operation: %d\n", size(queue));

   // Free the queue memory allocation
    free(queue);
    return 0;
}