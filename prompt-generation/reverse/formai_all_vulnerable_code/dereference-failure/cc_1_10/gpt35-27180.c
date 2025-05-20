//FormAI DATASET v1.0 Category: Queue Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Create a structure for queue
struct Queue {
    int *items;
    int front, rear;
    int size;
};

// Create an asynchronous method to create queue
struct Queue *createQueue(int size)
{
    struct Queue *queue = malloc(sizeof(struct Queue));

    queue->items = malloc(size * sizeof(int));
    queue->size = size;
    queue->front = -1;
    queue->rear = -1;

    return queue;
}

// Check if queue is empty or not
bool isQueueEmpty(struct Queue *queue)
{
    return queue->front == -1;
}

// Check if queue is full or not
bool isQueueFull(struct Queue *queue)
{
    return queue->rear == queue->size - 1;
}

// Add an item to the queue
void enqueue(struct Queue *queue, int item)
{
    if (isQueueFull(queue)) {
        printf("Queue is full\n");
    }
    else {
        if (queue->front == -1) {
            queue->front = 0;
        }

        queue->rear++;
        queue->items[queue->rear] = item;

        printf("Inserted %d\n", item);
    }
}

// Remove an item from the queue
int dequeue(struct Queue *queue)
{
    int item;

    if (isQueueEmpty(queue)) {
        printf("Queue is empty\n");
        item = -1;
    }
    else {
        item = queue->items[queue->front];

        if (queue->front >= queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        }
        else {
            queue->front++;
        }

        printf("Deleted %d\n", item);
    }

    return item;
}

// Display the queue
void display(struct Queue *queue)
{
    int i;

    if (isQueueEmpty(queue)) {
        printf("Queue is empty\n");
    }
    else {
        printf("Queue contains: ");
        
        for (i = queue->front; i < queue->rear + 1; i++) {
            printf("%d ", queue->items[i]);
        }
        printf("\n");
    }
}

// Main method
int main()
{
    struct Queue *queue = createQueue(10);

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    display(queue);

    dequeue(queue);
    dequeue(queue);

    display(queue);

    enqueue(queue, 6);
    enqueue(queue, 7);

    display(queue);

    dequeue(queue);

    display(queue);

    return 0;
}