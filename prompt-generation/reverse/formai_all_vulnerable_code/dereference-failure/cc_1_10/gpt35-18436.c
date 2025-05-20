//FormAI DATASET v1.0 Category: Queue Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

// Function to create a queue
struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1; // important, rear starts from -1
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Function to check if a queue is full
int isFull(struct Queue* queue)
{
    return (queue->size == queue->capacity);
}

// Function to check if a queue is empty
int isEmpty(struct Queue* queue)
{
    return (queue->size == 0);
}

// Function to enqueue an element
void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

// Function to dequeue an element
int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return -1;

    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Function to print the queue
void printQueue(struct Queue* queue)
{
    int i;
    printf("[ ");
    for (i = 0; i < queue->size; i++) {
        printf("%d ", queue->array[(queue->front + i) % queue->capacity]);
    }
    printf("]\n");
}

// Main function
int main()
{
    struct Queue* queue = createQueue(5);

    printf("Enqueuing elements into queue...\n");
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    printQueue(queue);

    printf("Dequeuing elements from queue...\n");
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));
    printQueue(queue);

    printf("Enqueuing more elements into queue...\n");
    enqueue(queue, 60);
    enqueue(queue, 70);
    printQueue(queue);

    printf("Dequeuing all elements from queue...\n");
    while (!isEmpty(queue)) {
        printf("%d dequeued from queue\n", dequeue(queue));
    }
    printQueue(queue);

    return 0;
}