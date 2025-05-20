//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Node data structure
typedef struct node
{
    int data;
    struct node *next;
} node;

// Queue data structure
typedef struct queue
{
    node *front;
    node *rear;
    int size;
} queue;

// Function to create a queue
queue *createQueue()
{
    queue *q = (queue *)malloc(sizeof(queue));
    if (q == NULL)
        return NULL;
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

// Function to check if the queue is empty
int isEmpty(queue *q)
{
    return (q->size == 0);
}

// Function to enqueue an element
void enqueue(queue *q, int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL)
        return;
    new_node->data = data;
    new_node->next = NULL;
    if (q->rear == NULL)
        q->front = q->rear = new_node;
    else
    {
        q->rear->next = new_node;
        q->rear = new_node;
    }
    q->size++;
}

// Function to dequeue an element
int dequeue(queue *q)
{
    if (isEmpty(q))
        return -1;
    int data = q->front->data;
    node *temp = q->front;
    q->front = q->front->next;
    free(temp);
    q->size--;
    if (q->front == NULL)
        q->rear = NULL;
    return data;
}

// Function to print the queue
void printQueue(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    node *temp = q->front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main()
{
    // Create a queue
    queue *q = createQueue();

    // Enqueue some elements
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    // Print the queue
    printf("Queue: ");
    printQueue(q);

    // Dequeue an element
    int data = dequeue(q);
    printf("Dequeued element: %d\n", data);

    // Print the queue
    printf("Queue: ");
    printQueue(q);

    // Free the queue
    while (!isEmpty(q))
        dequeue(q);
    free(q);

    return 0;
}