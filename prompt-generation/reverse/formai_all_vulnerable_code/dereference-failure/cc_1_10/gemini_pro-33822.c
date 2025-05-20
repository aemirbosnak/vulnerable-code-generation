//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

typedef struct _queue {
    int *data;
    int front, rear, size;
} Queue;

Queue* createQueue(int size)
{
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (int*)malloc(sizeof(int) * size);
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    return queue;
}

void enqueue(Queue *queue, int data)
{
    if (queue->rear == queue->size - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (queue->front == -1 && queue->rear == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->data[queue->rear] = data;
}

int dequeue(Queue *queue)
{
    if (queue->front == -1 && queue->rear == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
        return data;
    }
    queue->front++;
    return data;
}

void displayQueue(Queue *queue)
{
    if (queue->front == -1 && queue->rear == -1) {
        printf("Queue is empty!\n");
        return;
    }
    int i;
    printf("Queue: ");
    for (i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->data[i]);
    }
    printf("\n");
}

int main()
{
    Queue *queue = createQueue(5);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    displayQueue(queue);
    dequeue(queue);
    dequeue(queue);
    displayQueue(queue);
    enqueue(queue, 6);
    displayQueue(queue);
    return 0;
}