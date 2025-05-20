//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 100 //maximum size of the queue

struct queue
{
    int front, rear;
    int data[CAPACITY];
};

//function to create a new queue
struct queue* createqueue()
{
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

//function to check if the queue is empty
int isQueueEmpty(struct queue *q)
{
    if(q->front == -1 && q->rear == -1)
        return 1;
    else
        return 0;
}

//function to check if the queue is full
int isQueueFull(struct queue *q)
{
    if(q->rear == CAPACITY-1)
        return 1;
    else
        return 0;
}

//function to add items to the queue
void enqueue(struct queue *q, int data)
{
    if(isQueueFull(q))
        printf("Queue is full, cannot insert new element!\n");
    else if(isQueueEmpty(q))
    {
        q->front = 0;
        q->rear = 0;
        q->data[q->rear] = data;
    }
    else
    {
        q->rear++;
        q->data[q->rear] = data;
    }
}

//function to delete an item from the queue
void dequeue(struct queue *q)
{
    if(isQueueEmpty(q))
        printf("Queue is empty, cannot delete an element!\n");
    else if(q->front == q->rear) //only one element in the queue
    {
        printf("Deleted data is : %d\n", q->data[q->front]);
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        printf("Deleted data is : %d\n", q->data[q->front]);
        q->front++;
    }
}

//function to display all the elements in the queue
void display(struct queue *q)
{
    if(isQueueEmpty(q))
        printf("Queue is empty, nothing to display!\n");
    else
    {
        int i;
        printf("Elements in the queue are : ");
        for(i = q->front; i <= q->rear; i++)
            printf("%d ", q->data[i]);
        printf("\n");
    }
}

//driver function
int main()
{
    struct queue *q = createqueue();

    //adding elements to the queue
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    //displaying the elements in the queue
    display(q);

    //deleting an element from the queue
    dequeue(q);

    //displaying the updated elements in the queue
    display(q);

    return 0;
}