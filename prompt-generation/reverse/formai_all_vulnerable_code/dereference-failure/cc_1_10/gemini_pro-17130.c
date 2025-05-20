//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// A type to represent a queue
typedef struct queue
{
    int *arr;                // Pointer to an array to store the data
    int head;                // Index of the front of the queue
    int tail;                // Index of the rear of the queue
    int size;                // Size of the queue
} queue_t;

// Function to create a new queue
queue_t *queue_create(int size)
{
    queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
    queue->arr = (int *)malloc(size * sizeof(int));
    queue->head = 0;
    queue->tail = 0;
    queue->size = size;
    return queue;
}

// Function to free the memory allocated for the queue
void queue_free(queue_t *queue)
{
    free(queue->arr);
    free(queue);
}

// Function to check if the queue is empty
int queue_is_empty(queue_t *queue)
{
    return queue->head == queue->tail;
}

// Function to check if the queue is full
int queue_is_full(queue_t *queue)
{
    return (queue->tail + 1) % queue->size == queue->head;
}

// Function to enqueue an element
void queue_enqueue(queue_t *queue, int data)
{
    if (queue_is_full(queue))
    {
        printf("Queue is full!\n");
        return;
    }
    queue->arr[queue->tail] = data;
    queue->tail = (queue->tail + 1) % queue->size;
}

// Function to dequeue an element
int queue_dequeue(queue_t *queue)
{
    if (queue_is_empty(queue))
    {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = queue->arr[queue->head];
    queue->head = (queue->head + 1) % queue->size;
    return data;
}

// Function to print the queue
void queue_print(queue_t *queue)
{
    if (queue_is_empty(queue))
    {
        printf("Queue is empty!\n");
        return;
    }
    int i = queue->head;
    do
    {
        printf("%d ", queue->arr[i]);
        i = (i + 1) % queue->size;
    } while (i != queue->tail);
    printf("\n");
}

int main()
{
    // Create a queue of size 5
    queue_t *queue = queue_create(5);

    // Enqueue some elements
    queue_enqueue(queue, 1);
    queue_enqueue(queue, 2);
    queue_enqueue(queue, 3);
    queue_enqueue(queue, 4);
    queue_enqueue(queue, 5);

    // Print the queue
    queue_print(queue);

    // Dequeue some elements
    printf("Dequeued element: %d\n", queue_dequeue(queue));
    printf("Dequeued element: %d\n", queue_dequeue(queue));
    printf("Dequeued element: %d\n", queue_dequeue(queue));

    // Print the queue
    queue_print(queue);

    // Free the memory allocated for the queue
    queue_free(queue);

    return 0;
}