//FormAI DATASET v1.0 Category: Queue ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Just a heads up, this code contains some serious puns!

#define MAX_SIZE 10 // Maximum size of the queue

// The Queue structure
typedef struct
{
    int front;
    int rear;
    int arr[MAX_SIZE];
} Queue;

// Function to create a new Queue
Queue* create_queue()
{
    Queue* new_queue = (Queue*)malloc(sizeof(Queue));
    new_queue->front = -1;
    new_queue->rear = -1;

    printf("A new Queue has been born! Ready to take on the world! \n");

    return new_queue;
}

// Function to check if the Queue is empty
bool is_empty(Queue* queue)
{
    if (queue->front == -1 || queue->front > queue->rear)
    {
        printf("The Queue is empty! Come on guys, I need some company here. \n");
        return true;
    }

    return false;
}

// Function to check if the Queue is full
bool is_full(Queue* queue)
{
    if (queue->rear == MAX_SIZE - 1)
    {
        printf("The Queue is full! I cannot take it anymore, I need some space. \n");
        return true;
    }

    return false;
}

// Function to add an element to the queue
void enqueue(Queue* queue, int num)
{
    if (is_full(queue))
    {
        printf("Sorry buddy, but this Queue cannot contain any more elements! \n");
        return;
    }

    queue->rear++;
    queue->arr[queue->rear] = num;
    printf("%d has joined the Queue! Let's wait together!\n", num);

    if (queue->front == -1)
        queue->front = 0;
}

// Function to remove an element from the queue
void dequeue(Queue* queue)
{
    if (is_empty(queue))
    {
        printf("I cannot remove an element if there is nothing in the Queue! \n");
        return;
    }

    printf("%d has left the Queue! Goodbye my friend, until we meet again. \n", queue->arr[queue->front]);
    queue->front++;

    if (queue->front > queue->rear)
    {
        queue->front = -1;
        queue->rear = -1;
    }
}

// Function to display the current status of the queue
void display(Queue* queue)
{
    if (is_empty(queue))
        return;

    printf("Current Queue:\n");
    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

int main()
{
    Queue* my_queue = create_queue();

    enqueue(my_queue, 1);
    enqueue(my_queue, 2);
    display(my_queue);
    dequeue(my_queue);
    enqueue(my_queue, 3);
    enqueue(my_queue, 4);
    enqueue(my_queue, 5);
    enqueue(my_queue, 6);
    enqueue(my_queue, 7);
    enqueue(my_queue, 8);
    enqueue(my_queue, 9);
    enqueue(my_queue, 10);
    enqueue(my_queue, 11);
    display(my_queue);
    dequeue(my_queue);
    dequeue(my_queue);
    dequeue(my_queue);
    dequeue(my_queue);
    dequeue(my_queue);
    dequeue(my_queue);
    dequeue(my_queue);
    dequeue(my_queue);
    dequeue(my_queue);
    dequeue(my_queue);
    dequeue(my_queue);
    display(my_queue);
    dequeue(my_queue);

    free(my_queue);

    return 0;
}