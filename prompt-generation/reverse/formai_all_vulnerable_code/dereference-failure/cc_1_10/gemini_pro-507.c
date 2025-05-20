//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
typedef struct Queue
{
    int *arr;
    int front;
    int rear;
    int capacity;
} Queue;

// Create a new queue
Queue *createQueue(int capacity)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->arr = (int *)malloc(capacity * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = capacity;
    return queue;
}

// Check if the queue is empty
int isEmpty(Queue *queue)
{
    return queue->front == -1;
}

// Check if the queue is full
int isFull(Queue *queue)
{
    return queue->rear == queue->capacity - 1;
}

// Insert an element into the queue
void enqueue(Queue *queue, int data)
{
    if (isFull(queue))
    {
        printf("Queue is full!\n");
        return;
    }
    else if (isEmpty(queue))
    {
        queue->front = queue->rear = 0;
    }
    else
    {
        queue->rear++;
    }
    queue->arr[queue->rear] = data;
}

// Remove an element from the queue
int dequeue(Queue *queue)
{
    int data;
    if (isEmpty(queue))
    {
        printf("Queue is empty!\n");
        return -1;
    }
    else if (queue->front == queue->rear)
    {
        data = queue->arr[queue->front];
        queue->front = queue->rear = -1;
    }
    else
    {
        data = queue->arr[queue->front];
        queue->front++;
    }
    return data;
}

// Get the front element of the queue
int front(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty!\n");
        return -1;
    }
    else
    {
        return queue->arr[queue->front];
    }
}

// Get the rear element of the queue
int rear(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty!\n");
        return -1;
    }
    else
    {
        return queue->arr[queue->rear];
    }
}

// Print the queue
void printQueue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

// Main function
int main()
{
    // Create a queue of capacity 5
    Queue *queue = createQueue(5);

    // Insert elements into the queue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    // Print the queue
    printQueue(queue);

    // Remove an element from the queue
    printf("Dequeued element: %d\n", dequeue(queue));

    // Print the queue
    printQueue(queue);

    // Get the front and rear elements of the queue
    printf("Front element: %d\n", front(queue));
    printf("Rear element: %d\n", rear(queue));

    // Check if the queue is empty
    if (isEmpty(queue))
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Queue is not empty!\n");
    }

    return 0;
}