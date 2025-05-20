//FormAI DATASET v1.0 Category: Queue Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10

typedef struct Queue
{
    int front, rear;
    int elements[MAX_QUEUE_SIZE];
} Queue;

void initQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isQueueEmpty(Queue *q)
{
    if (q->front == -1 && q->rear == -1)
        return 1;
    else
        return 0;
}

int isQueueFull(Queue *q)
{
    if ((q->rear + 1) % MAX_QUEUE_SIZE == q->front)
        return 1;
    else
        return 0;
}

void enqueue(Queue *q, int val)
{
    if (isQueueFull(q))
    {
        printf("Queue is full!\n");
    }
    else if (isQueueEmpty(q))
    {
        q->front = 0;
        q->rear = 0;
        q->elements[q->rear] = val;
    }
    else
    {
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
        q->elements[q->rear] = val;
    }
}

int dequeue(Queue *q)
{
    int val = -1;

    if (isQueueEmpty(q))
    {
        printf("Queue is empty!\n");
    }
    else if (q->front == q->rear)
    {
        val = q->elements[q->front];
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        val = q->elements[q->front];
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    }

    return val;
}

void printQueue(Queue *q)
{
    if (isQueueEmpty(q))
    {
        printf("Queue is empty!\n");
        return;
    }

    int i;
    printf("Queue: ");

    for (i = q->front; i != q->rear; i = (i + 1) % MAX_QUEUE_SIZE)
    {
        printf("%d ", q->elements[i]);
    }

    printf("%d\n", q->elements[i]);
}

int main()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));

    initQueue(q);

    char userInput[256];
    int userInputInt;

    printf("Welcome to Retro Queue Implementation!\n");
    printf("Type help to see all available commands\n");

    while (1)
    {
        printf("> ");
        scanf("%s", userInput);

        if (strcmp(userInput, "exit") == 0)
        {
            printf("Goodbye!\n");
            break;
        }
        else if (strcmp(userInput, "help") == 0)
        {
            printf("Available commands:\n");
            printf("enqueue [int]: adds an integer to the queue\n");
            printf("dequeue: removes the first integer from the queue and prints it\n");
            printf("print: prints the contents of the queue\n");
            printf("help: prints the available commands\n");
            printf("exit: exits the program\n");
        }
        else if (strcmp(userInput, "enqueue") == 0)
        {
            scanf("%d", &userInputInt);
            enqueue(q, userInputInt);
        }
        else if (strcmp(userInput, "dequeue") == 0)
        {
            int result = dequeue(q);
            if (result != -1)
            {
                printf("Dequeued value: %d\n", result);
            }
        }
        else if (strcmp(userInput, "print") == 0)
        {
            printQueue(q);
        }
        else
        {
            printf("Invalid command. Type help for a list of available commands.\n");
        }
    }

    return 0;
}