//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

typedef struct {
    int front, rear, size;
    int *arr;
} Queue;

Queue* createQueue()
{
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = -1;
    q->size = 0;
    q->arr = (int*)malloc(QUEUE_SIZE * sizeof(int));
    return q;
}

void enqueue(Queue *q, int data)
{
    if (q->rear == QUEUE_SIZE - 1)
        printf("Queue is full\n");
    else {
        q->rear++;
        q->arr[q->rear] = data;
        if (q->front == -1)
            q->front++;
        q->size++;
    }
}

int dequeue(Queue *q)
{
    if (q->front == -1) {
        printf("Queue is empty\n");
        return -1;
    } else {
        int data = q->arr[q->front];
        q->front++;
        if (q->front > q->rear)
            q->front = q->rear = -1;
        q->size--;
        return data;
    }
}

void displayQueue(Queue *q)
{
    if (q->front == -1)
        printf("Queue is empty\n");
    else {
        int i;
        printf("Queue: ");
        for (i = q->front; i <= q->rear; i++)
            printf("%d ", q->arr[i]);
        printf("\n");
    }
}

int main()
{
    Queue *q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    displayQueue(q);

    dequeue(q);
    dequeue(q);

    displayQueue(q);

    enqueue(q, 50);
    enqueue(q, 60);

    displayQueue(q);

    return 0;
}