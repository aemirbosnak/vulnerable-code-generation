//FormAI DATASET v1.0 Category: Queue Implementation ; Style: modular
/* A Program to Implement a Queue using C */

#include <stdio.h>
#include <stdlib.h>

/* Defining the Queue Structure */
struct queue
{
    int front, rear;
    int capacity;
    int *array;     
};

/* Function to Create a Queue of given Capacity */
struct queue *createQueue(int capacity)
{
    struct queue *q = malloc(sizeof(struct queue));
    if (!q) 
        return NULL;
    q->capacity = capacity;
    q->front = q->rear = -1;
    q->array = malloc(q->capacity * sizeof(int));
    if (!q->array)
        return NULL;
    return q;
}

/* Function to Check if Queue is Full */
int isFull(struct queue *q)
{
    return (q->rear + 1) % q->capacity == q->front;
}

/* Function to Check if Queue is Empty */
int isEmpty(struct queue *q)
{
    return q->front == -1;
}

/* Function to Add an Element to the Queue */
void enqueue(struct queue *q, int data)
{
    if (isFull(q))
        printf("Queue is Full!");
    else
    {
        q->rear = (q->rear + 1) % q->capacity;
        q->array[q->rear] = data;
        if (q->front == -1)
            q->front = q->rear;
    }
}

/* Function to Remove an Element from the Queue */
int dequeue(struct queue *q)
{
    int data = 0;
    if (isEmpty(q))
        printf("Queue is Empty!");
    else
    {
        data = q->array[q->front];
        if (q->front == q->rear)
            q->front = q->rear = -1;
        else
            q->front = (q->front + 1) % q->capacity;
    }
    return data;
}

/* Function to Display the Queue */
void displayQueue(struct queue *q)
{
    int i;
    if (isEmpty(q))
        printf("Queue is Empty!");
    else
    {
        printf("Queue Elements:\n");
        for (i = q->front; i != q->rear; i = (i + 1) % q->capacity)
            printf("%d ", q->array[i]);
        printf("%d", q->array[i]);
    }
}

/* Main Function */
int main()
{
    /* Creating a Queue of Capacity 5 */
    struct queue *q = createQueue(5);

    /* Adding Elements to the Queue */
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    /* Displaying the Queue */
    displayQueue(q);

    /* Removing Elements from the Queue */
    printf("\nDequeuing Element: %d", dequeue(q));
    printf("\nDequeuing Element: %d", dequeue(q));

    /* Displaying the Updated Queue */
    displayQueue(q);

    /* Freeing the Memory */
    free(q->array);
    free(q);

    return 0;
}