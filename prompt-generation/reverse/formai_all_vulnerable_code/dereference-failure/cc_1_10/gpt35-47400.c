//FormAI DATASET v1.0 Category: Queue ; Style: lively
/* 
Welcome to the C Queue example program! Get ready to learn about Queue data structures 
and how they work in C!

In this program, we'll create a queue of strings using dynamic memory allocation.
We'll also demonstrate how to enqueue elements, dequeue elements, check if the queue
is empty, and print out all the elements in the queue.

Let's get coding!
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // for boolean data type

#define MAX_QUEUE_SIZE 5

typedef struct Queue
{
    char **arr; // dynamic array of strings
    int front, rear;
    int size;
} Queue;

// function prototypes
Queue *createQueue(int size);
bool isFull(Queue *q);
bool isEmpty(Queue *q);
void enqueue(Queue *q, char *element);
char *dequeue(Queue *q);
void printQueue(Queue *q);

int main()
{
    Queue *q = createQueue(MAX_QUEUE_SIZE); // create a queue of max size 5

    // let's enqueue a few elements
    enqueue(q, "apple");
    enqueue(q, "banana");
    enqueue(q, "cherry");
    enqueue(q, "date");
    enqueue(q, "elderberry");

    // let's print out the queue
    printf("Our queue is:\n");
    printQueue(q);

    // let's dequeue an element
    printf("\nDequeueing an element...\n");
    char *dequeuedElement = dequeue(q);
    printf("The dequeued element is: %s\n", dequeuedElement);

    // let's print out the updated queue
    printf("\nOur updated queue is:\n");
    printQueue(q);

    return 0;
}

// function to create a queue of specified size
Queue *createQueue(int size)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->arr = (char **)malloc(size * sizeof(char *));
    q->front = -1;
    q->rear = -1;
    q->size = size;
    return q;
}

// function to check if the queue is full
bool isFull(Queue *q)
{
    return q->rear == q->size - 1;
}

// function to check if the queue is empty
bool isEmpty(Queue *q)
{
    return q->front == -1;
}

// function to add an element to the queue
void enqueue(Queue *q, char *element)
{
    if (isFull(q))
    {
        printf("Sorry, the queue is already full!\n");
        return;
    }

    // allocate memory for the new element and insert it
    char *newElement = (char *)malloc((strlen(element) + 1) * sizeof(char));
    strcpy(newElement, element);

    q->rear++;
    q->arr[q->rear] = newElement;

    // set the front index if this is the first element
    if (q->front == -1)
    {
        q->front++;
    }
}

// function to remove an element from the queue
char *dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Sorry, the queue is already empty!\n");
        return NULL;
    }

    char *dequeuedElement = q->arr[q->front];

    // shift the remaining elements one position to the left
    for (int i = q->front; i < q->rear; i++)
    {
        q->arr[i] = q->arr[i + 1];
    }

    q->rear--;

    // set the front index to -1 if this was the last element
    if (q->rear == -1)
    {
        q->front = -1;
    }

    return dequeuedElement;
}

// function to print out all the elements in the queue
void printQueue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("The queue is empty!\n");
        return;
    }

    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%s\n", q->arr[i]);
    }
}