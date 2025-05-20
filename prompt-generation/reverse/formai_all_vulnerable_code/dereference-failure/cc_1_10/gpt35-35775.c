//FormAI DATASET v1.0 Category: Queue Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5

struct Queue
{
    int items[QUEUE_SIZE];
    int front;
    int rear;
};

struct Queue* createQueue()
{
    struct Queue* q = malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(struct Queue* q)
{
    if(q->rear == -1) return 1;
    else return 0;
}

void enqueue(struct Queue* q, int item)
{
    if(q->rear == QUEUE_SIZE-1) printf("Queue is full!");
    else
    {
        if(q->front == -1) q->front = 0;
        q->rear++;
        q->items[q->rear] = item;
        printf("Inserted %d to the queue\n", item);
    }
}

int dequeue(struct Queue* q)
{
    int item;
    if(isEmpty(q))
    {
        printf("Queue is empty!");
        item = -1;
    }
    else
    {
        item = q->items[q->front];
        q->front++;
        if(q->front > q->rear)
        {
            printf("Resetting queue\n");
            q->front = q->rear = -1;
        }
    }
    return item;
}

void printQueue(struct Queue *q) {
    int i = q->front;

    if(isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue contains the following elements: ");
        for(i = q->front; i < q->rear + 1; i++) {
                printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Queue* q = createQueue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    printQueue(q);

    dequeue(q);
    dequeue(q);

    printQueue(q);

    enqueue(q, 6);
    enqueue(q, 7);

    printQueue(q);

    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    printQueue(q);

    return 0;
}