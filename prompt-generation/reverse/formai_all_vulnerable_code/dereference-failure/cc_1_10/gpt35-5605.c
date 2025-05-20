//FormAI DATASET v1.0 Category: Queue ; Style: creative
#include<stdio.h>
#include<stdlib.h>
 
#define MAX_QUEUE_SIZE 100
 
typedef struct Queue Queue;
struct Queue
{
    int data[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int size;
};
 
Queue* createQueue()
{
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    return q;
}
 
int isFull(Queue* q)
{
    if ((q->front == 0 && q->rear == MAX_QUEUE_SIZE-1) || (q->front == q->rear+1))
        return 1;
    return 0;
}
 
int isEmpty(Queue* q)
{
    if (q->front == -1)
        return 1;
    return 0;
}
 
void enqueue(Queue* q, int value)
{
    if (isFull(q))
    {
        printf("Queue is full. Cannot add %d\n", value);
        return;
    }
    if (q->front == -1)
    {
        q->front = 0;
        q->rear = 0;
    }
    else
    {
        if (q->rear == MAX_QUEUE_SIZE-1)
            q->rear = 0;
        else
            q->rear++;
    }
    q->data[q->rear] = value;
    q->size++;
}
 
int dequeue(Queue* q)
{
    int value;
    if (isEmpty(q))
    {
        printf("Queue is empty. Cannot remove.\n");
        return -1;
    }
    value = q->data[q->front];
    q->size--;
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        if (q->front == MAX_QUEUE_SIZE-1)
            q->front = 0;
        else
            q->front++;
    }
    return value;
}
 
int main()
{
    Queue* q = createQueue();
    int choice;
    int value;
    do
    {
        printf("Queue Operations:\n1. Enqueue\n2. Dequeue\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter value to be inserted: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:
                value = dequeue(q);
                if (value != -1)
                    printf("Removed %d from queue.\n", value);
                break;
            case 3:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    while(choice != 3);
    return 0;
}