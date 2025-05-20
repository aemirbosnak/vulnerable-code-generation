//FormAI DATASET v1.0 Category: Queue Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

/*
    Queue is a data structure that follows the First In First Out (FIFO) principle.
    In simple words, the element that gets added first will be the first one to be
    removed from the queue.

    Queue can be implemented using an array or linked list. Here I have implemented
    queue using an array.
*/

typedef struct
{
    int front; // index of the front element
    int rear;  // index of the rear element
    int capacity; // maximum capacity of queue
    int size;   // current size of queue
    int *arr;   // the queue as an array
} Queue;

Queue *createQueue()
{
    /*
        Function to create an empty queue. Initializes front and rear to -1.
        Returns a pointer to Queue.
    */

    Queue *queue = malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = MAX_QUEUE_SIZE;
    queue->size = 0;
    queue->arr = (int *)malloc(MAX_QUEUE_SIZE * sizeof(int));
    return queue;
}

int isQueueEmpty(Queue *queue)
{
    /*
        Function to check if the queue is empty.
        Returns 1 if queue is empty, 0 otherwise.
    */

    return queue->size == 0;
}

int isQueueFull(Queue *queue)
{
    /*
        Function to check if the queue is full.
        Returns 1 if queue is full, 0 otherwise.
    */

    return queue->size == queue->capacity;
}

void enqueue(Queue *queue, int value)
{
    /*
        Function to add a value to the queue.
        Returns nothing.
    */

    if (isQueueFull(queue))
    {
        printf("Queue Overflow: Cannot add element '%d'\n", value);
        return;
    }

    if (isQueueEmpty(queue))
    {
        queue->front = 0;
        queue->rear = 0;
    }
    else
    {
        queue->rear = (queue->rear + 1) % queue->capacity;
    }

    queue->arr[queue->rear] = value;
    queue->size++;
    printf("Added element '%d' to the queue.\n", value);
}

int dequeue(Queue *queue)
{
    /*
        Function to remove and return the front element from the queue.
        Returns the front element value.
    */

    if (isQueueEmpty(queue))
    {
        printf("Queue Underflow: Cannot remove element from empty queue\n");
        return -1;
    }

    int value = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    printf("Removed element '%d' from the queue.\n", value);
    return value;
}

void display(Queue *queue)
{
    /*
        Function to display the entire queue.
        Returns nothing.
    */

    if (isQueueEmpty(queue))
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Elements in the queue: ");
    int i;
    for (i = 0; i < queue->size; i++)
    {
        int index = (queue->front + i) % queue->capacity;
        printf("%d ", queue->arr[index]);
    }
    printf("\n");
}

int main()
{
    Queue *queue = createQueue();

    // sample usage
    enqueue(queue, 5);    // Added element '5' to the queue
    enqueue(queue, 10);   // Added element '10' to the queue
    enqueue(queue, 15);   // Added element '15' to the queue
    dequeue(queue);       // Removed element '5' from the queue
    display(queue);       // Elements in the queue: 10 15

    return 0;
}