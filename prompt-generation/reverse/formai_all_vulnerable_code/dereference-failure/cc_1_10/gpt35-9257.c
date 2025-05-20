//FormAI DATASET v1.0 Category: Queue Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10 // Maximum size of the queue

// Queue structure
typedef struct queue 
{
    int front, rear; // front and rear indices of the queue
    int array[MAX_QUEUE_SIZE]; // Array to store the elements of the queue
} Queue;

// Function to create and initialize a new queue
Queue* create_queue()
{
    Queue* q = malloc(sizeof(Queue)); // Allocate memory for the new queue

    if(!q)
    {
        printf("Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE); // Exit the program if memory allocation fails
    }

    q->front = -1; // Initialize the front index as -1
    q->rear = -1; // Initialize the rear index as -1

    return q;
}

// Function to check if the queue is empty
int is_empty(Queue* q)
{
    return (q->front == -1 && q->rear == -1);
}

// Function to check if the queue is full
int is_full(Queue* q)
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// Function to add an element to the queue
void enqueue(Queue* q, int value)
{
    if(is_full(q))
    {
        printf("Error: Queue is full.\n");
        return; // Exit the function if the queue is full
    }

    if(is_empty(q))
    {
        q->front = 0; // Set the front index as 0
        q->rear = 0; // Set the rear index as 0
    }
    else
    {
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; // Move the rear index to the next position
    }

    q->array[q->rear] = value; // Add the element to the queue
}

// Function to remove an element from the queue
int dequeue(Queue* q)
{
    if(is_empty(q))
    {
        printf("Error: Queue is empty.\n");
        return -1; // Return -1 if the queue is empty
    }

    int value = q->array[q->front]; // Get the front element of the queue

    if(q->front == q->rear)
    {
        q->front = -1; // Set the front index as -1
        q->rear = -1; // Set the rear index as -1
    }
    else
    {
        q->front = (q->front + 1) % MAX_QUEUE_SIZE; // Move the front index to the next position
    }

    return value;
}

// Function to display the elements of the queue
void display(Queue* q)
{
    if(is_empty(q))
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");

    int i = q->front;

    while(i != q->rear)
    {
        printf("%d ", q->array[i]);
        i = (i + 1) % MAX_QUEUE_SIZE;
    }

    printf("%d\n", q->array[q->rear]);
}

int main()
{
    printf("Welcome to the Queue Program!\n");

    Queue* q = create_queue();

    printf("Queue created successfully.\n");

    printf("Adding elements to the queue...\n");

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 60);
    enqueue(q, 70);
    enqueue(q, 80);
    enqueue(q, 90);
    enqueue(q, 100);

    printf("Displaying the elements of the queue...\n");

    display(q);

    printf("Removing elements from the queue...\n");

    dequeue(q);
    dequeue(q);
    dequeue(q);

    printf("Displaying the elements of the queue...\n");

    display(q);

    printf("Adding more elements to the queue...\n");

    enqueue(q, 110);
    enqueue(q, 120);
    enqueue(q, 130);

    printf("Displaying the elements of the queue...\n");

    display(q);

    printf("Thank you for using the Queue Program!\n");

    return 0;
}