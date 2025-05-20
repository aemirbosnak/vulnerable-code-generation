//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

// Queue structure
typedef struct Queue
{
    int front, rear, size;
    int capacity;
    int *array;
} Queue;

// Function to create a queue of given capacity
Queue* createQueue(int capacity)
{
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;  // Initialize rear as last index
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

// Function to add an item to the queue.
// It changes rear and size
void enqueue(Queue* queue, int item)
{
    if (queue->size == queue->capacity) {
        printf("Queue is full\n");
    }
    else {
        queue->rear = (queue->rear + 1) % queue->capacity;
        queue->array[queue->rear] = item;
        queue->size++;
        printf("%d inserted to queue\n", item);
    }
}

// Function to remove an item from queue.
// It changes front and size
int dequeue(Queue* queue)
{
    if (queue->size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    else {
        int item = queue->array[queue->front];
        queue->front = (queue->front + 1) % queue->capacity;
        queue->size--;
        return item;
    }
}

// Function to get front of queue
int front(Queue* queue)
{
    if (queue->size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->array[queue->front];
}

// Function to get rear of queue
int rear(Queue* queue)
{
    if (queue->size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->array[queue->rear];
}

// Function to check if queue is empty
int isEmpty(Queue* queue)
{
    return (queue->size == 0);
}

// Function to check if queue is full
int isFull(Queue* queue)
{
    return (queue->size == queue->capacity);
}

// Driver program to test the queue
int main()
{
    Queue* queue = createQueue(100);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("Front of queue: %d\n", front(queue));
    printf("Rear of queue: %d\n", rear(queue));

    dequeue(queue);
    dequeue(queue);

    printf("Front of queue: %d\n", front(queue));
    printf("Rear of queue: %d\n", rear(queue));

    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    }
    else {
        printf("Queue is not empty\n");
    }

    if (isFull(queue)) {
        printf("Queue is full\n");
    }
    else {
        printf("Queue is not full\n");
    }

    return 0;
}