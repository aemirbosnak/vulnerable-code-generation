//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Queue node structure
typedef struct node
{
    int data;
    struct node* next;
} Node;

// Queue class
typedef struct queue
{
    Node* head;
    Node* tail;
    int size;
} Queue;

// Function to create a new queue
Queue* createQueue()
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

// Function to check if the queue is empty
int isEmpty(Queue* q)
{
    return q->size == 0;
}

// Function to add an element to the queue
void enqueue(Queue* q, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    // If the queue is empty, make the new node the head and tail
    if (q->size == 0)
    {
        q->head = newNode;
        q->tail = newNode;
    }
    else
    {
        q->tail->next = newNode;
        q->tail = newNode;
    }
    q->size++;
}

// Function to remove an element from the queue
int dequeue(Queue* q)
{
    if (isEmpty(q))
    {
        return -1;
    }
    int data = q->head->data;
    Node* temp = q->head;
    q->head = q->head->next;
    free(temp);
    q->size--;
    return data;
}

// Function to print the queue
void printQueue(Queue* q)
{
    Node* current = q->head;
    while (current!= NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main()
{
    Queue* q = createQueue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    printQueue(q);
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    return 0;
}